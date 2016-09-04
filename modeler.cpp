//
//  processor.cpp
//  Map Processor
//
//  Created by Tasman Thenell on 8/17/16.
//  Copyright © 2016 Tasman Thenell. All rights reserved.
//

#include "modeler.h"

village::village(int x, int y, int pop, double rate, string name){
    this->name = name;
    this->x = x;
    this->y = y;
    population = pop;
    killRate = rate;
}

int village::getPop(int year){
    //cout << "returning pop: " << population << endl;
    return population; //* growth factor;
}

processor::processor(parameters* setup){
    xSize = setup->x;
    ySize = setup->y;
    this->years = setup->years;
    cout << "years: " << years << endl;
    carryCapacity = setup->carryCapacity;
    huntRange = setup->huntRange;
    HpHy = setup->huntsPerYear;
    killProb = setup->killProb;

    animalDiffRate = .02;
    animalGrowthRate = .07;
    encounterRate = .02043;
    theta = 1;

    if(setup->geolocation){
        geoX = setup->geoX;
        geoY = setup->geoY;
        geolocation = true;
    }
    else{
        geolocation = false;
    }

    //make grid
    grid = new double**[years + 1];
    for(int i = 0; i < years + 1; i++){
        cout << "on year: " << i << endl;
        grid[i] = new double*[ySize];
        for(int j = 0; j < ySize; j++){
            grid[i][j] = new double[xSize]();
        }
    }

    for(int i = 0; i < ySize; i++){
        for(int j = 0; j < xSize; j++){
            grid[0][i][j] = carryCapacity;
        }
    }

    output = new int[4];

    for(int i = 0; i < 4; i++){
        output[i] = setup->output[i];
    }

    directory = setup->workingPath;
    this->name = setup->name;

    std::cout << "end of the processor constructor" << endl;
}

void processor::runSimulation(){
    int count;
    double top, bot, locationValue;
    double **yearlyGrid = new double*[ySize]; //n2
    double **growth = new double*[ySize];
    double **effort = new double*[ySize];
    for(int i = 0; i < ySize; i++){
        yearlyGrid[i] = new double[xSize];
        growth[i] = new double[xSize];
        effort[i] = new double[xSize];
    }

    std::cout << "at the start of main loop" << endl;
    for(int curYear = 0; curYear < years; curYear++){
        cout << "current year is: " << curYear << endl;
        count = 0;
        for(int y = 0; y < ySize; y++){
            for(int x = 0; x < xSize; x++){
                count = count + 1;

                //d*(n[year,i+1,j]+n[year,i-1,j])+(1-4*d)*n[year,i,j]+d*(n[year,i,j+1]+n[year,i,j-1])
                if(y > 0 && y < ySize - 1){
                    if(x > 0 && x < xSize - 1){
                        yearlyGrid[y][x] = animalDiffRate*(grid[curYear][y+1][x] + grid[curYear][y-1][x]) + (1-4*animalDiffRate)*grid[curYear][y][x] + animalDiffRate*(grid[curYear][y][x+1] + grid[curYear][y][x-1]);
                        //* getNeighborTotals(curYear, x, y);
                    }
                    else{
                        yearlyGrid[y][x] = carryCapacity;
                    }
                }
                else{
                    yearlyGrid[y][x] = carryCapacity;
                }

                for(int settleNum = 0; settleNum < towns.size(); settleNum++){
                    //((comlocation[numb,0]-i)**2+(comlocation[numb,1]-j)**2))
                    locationValue = pow(towns[settleNum]->x - x, 2) + pow(towns[settleNum]->y - y, 2);

                    //math.exp(-1/(2*std**2)*locationValue
                    top = exp((-1)/(2*pow(huntRange, 2))*locationValue);

                    //(2*math.pi*math.sqrt(locationValue+1)
                    bot = 2*M_PI*sqrt(locationValue) + 1;
                    //cout << "top: " << top << " bot: " << bot << endl;
                    if(settleNum == 0){
                        effort[y][x] = (HpHy*towns[settleNum]->getPop(curYear)*top)/bot;
                    }
                    else{
                        effort[y][x] = effort[y][x] + (HpHy*towns[settleNum]->getPop(curYear)*top)/bot;
                    }
                    //cout << "effort at: " << x << " " << y << " " << effort[y][x] << endl;
                }
                //n[year,:,:]*lambdas-lambdas*n[year,:,:]*(n[year,:,:]/density)**theta
                growth[y][x] = animalGrowthRate*grid[curYear][y][x] - animalGrowthRate*grid[curYear][y][x]*pow((grid[curYear][y][x]/carryCapacity), theta);

                //cout << "yearly grid - stuff + growth" << endl;
                //cout << "yearly grid: " << yearlyGrid[y][x] << " stuff: " << killProb*encounterRate*effort[y][x]*grid[curYear][y][x] << " growth: " << growth[y][x] << endl;

                grid[curYear + 1][y][x] = (yearlyGrid[y][x] + growth[y][x]) - killProb*encounterRate*effort[y][x]*grid[curYear][y][x];
            }
        }
        /* debug stuff
        cout << "grids at the end of year: " << curYear << endl;
        cout << "yearlyGrid: " << endl;
        for(int y = 0; y < ySize; y++){
            for(int x = 0; x < xSize; x++){
                cout << yearlyGrid[y][x] << " ";
            }
            cout << endl;
        }
        cout << "effort: " << endl;
        for(int y = 0; y < ySize; y++){
            for(int x = 0; x < xSize; x++){
                cout << effort[y][x] << " ";
            }
            cout << endl;
        }
        cout << "overall grid: " << endl;
        for(int y = 0; y < ySize; y++){
            for(int x = 0; x < xSize; x++){
                cout << grid[curYear + 1][y][x] << " ";
            }
            cout << endl;
        }

         */
        for(int y = 0; y < ySize; y++){
            for(int x = 0; x < xSize; x++){
                if(grid[curYear + 1][y][x] < 0){
                    grid[curYear + 1][y][x] = 0;
                }
            }
        }
        emit progressUpdate(curYear + 1);
    }

    for(int i = 0; i < ySize; i++){
        free(yearlyGrid[i]);
        free(growth[i]);
        free(effort[i]);
    }

    free(yearlyGrid);
    free(growth);
    free(effort);

    generateOutput();
}

double processor::getNeighborTotals(int year, int x, int y){
    double total = 0;
    total = grid[year][y + 1][x];
    total += grid[year][y - 1][x];
    total += grid[year][y][x + 1];
    total += grid[year][y][x - 1];
    total -= 4*grid[year][y][x];
    return total;
}

void processor::addVillage(village *newTown){
    if(geolocation){
        //convert lat long position into x, y of grid.
    }
    cout << "adding a town with " << newTown->population << " population." << endl;
    towns.push_back(newTown);
}

void processor::printResults(){
    for(int time = 0; time < years + 1; time++){
        cout << "Grid for year: " << time + 1 << endl;
        for(int y = 0; y < ySize; y++){
            for(int x = 0; x < xSize; x++){
                cout << grid[time][y][x] << " ";
            }
            cout << endl;
        }
    }
}

void processor::dumpForHeatmap(){
    ofstream out("test.txt");

    if(out.is_open()){
        for(int i = 0; i < ySize; i++){
            for(int j = 0; j < xSize; j++){
                out << i << " " << j << " " << 10*((carryCapacity - grid[years][i][j])/carryCapacity) << endl;
            }
        }
    }
    else{
        cout << "problem opening file" << endl;
    }
}

void processor::generateHeatmap(int year){
    heatmap_t* newMap = heatmap_new(xSize, ySize);
    heatmap_stamp_t* stamp = heatmap_stamp_gen(1);
    static const unsigned char discrete_data[] = {
        0, 0, 0, 0, 94, 79, 162, 255, 50, 136, 189, 255, 102, 194, 165, 255, 171, 221, 164, 255, 230, 245, 152, 255, 241, 243, 167, 255, 254, 224, 144, 255, 253, 174, 97, 255, 244, 109, 67, 255, 213, 62, 79, 255, 158, 1, 66, 255
    };
    static const heatmap_colorscheme_t discrete = { discrete_data, sizeof(discrete_data)/sizeof(discrete_data[0]/4) };
    const heatmap_colorscheme_t* colorscheme = &discrete;
    float weight;

    for(int y = 0; y < ySize; y++){
        for(int x = 0; x < xSize; x++){
            weight = 10*((carryCapacity - grid[year][y][x])/carryCapacity);
            heatmap_add_weighted_point_with_stamp(newMap, x, y, weight, stamp);
        }
    }

    heatmap_stamp_free(stamp);
    std::vector<unsigned char> image((xSize)*(ySize)*4);
    heatmap_render_to(newMap, colorscheme, &image[0]);
    heatmap_free(newMap);
    std::vector<unsigned char> png;
    if(unsigned error = lodepng::encode(directory + "/" + name + "_heatmap"+to_string(year)+".png", image, xSize, ySize)) {
        std::cerr << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
    }

}

void processor::generateOutput(){
    if(output[0] == 2){
        //emit progressImages(1);
        generateHeatmap(years + 1);
    }
    else if(output[0] == 1){
        for(int i = 1; i < years + 1; i++){
            //emit progressImages(i);
            generateHeatmap(i);
            //emit progressImages(i);
        }
    }

    if(output[1] == 2){
        generateCSV(years + 1);
    }
    else if(output[1] == 1){
        for(int i = 1; i < years + 1; i++){
            generateCSV(i);
        }
    }

    /*
    if(output[2] == 1){
        dumpConfig(false);
    }
    else if(output[2] == 1){
        dumpConfig(true);
    }

    if(output[3] == 1){
        savePopulations();
    }
    */
}

void processor::generateCSV(int t){
    std::cout << "at generate csv, dir: " << directory << " name: " << name << std::endl;
    ofstream outfile;
    outfile.open(directory + "/" + name + "_year" + to_string(t) + ".csv");
    for(int i = 0; i < ySize; i++){
        for(int j = 0; j < xSize; j++){
            outfile << grid[t][i][j] << ",";
        }
        outfile << "\n";
    }
    outfile.close();
}

void processor::dumpConfig(bool){

}

void processor::savePopulations(){

}

processor::~processor(){
    if(grid != nullptr){
        for(int i = 0; i < years + 1; i++){
            for(int j = 0; j < ySize; j++){
                free(grid[i][j]);
            }
            free(grid[i]);
        }
        free(grid);
    }

    free(output);
    //cleanup towns
}
