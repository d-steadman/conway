//
// Created by Wil Steadman on 3/7/22.
//

#include <vector>

#ifndef CONWAY_CONWAY_H
#define CONWAY_CONWAY_H

using namespace std;

class Conway {
private:
    vector<int> map;
    unsigned int width;
    unsigned int heigh;
    float initial_chance;
    unsigned int death_limit;
    unsigned int birth_limit;

    //Map generation functions
    void randomVoid(void);
    unsigned int cellNeighbors(unsigned x, unsigned y);
    void simulation(void);
    void fillBorder(void);

public:
    //Creating the cell map
    Conway(unsigned int width, unsigned int height);
    Conway(unsigned int width, unsigned int height, float initial_chance);
    void generate(void);

    //Fetching from the cell map
    int getCell(unsigned int x, unsigned int y);
    void printMap(void);
};


#endif //CONWAY_CONWAY_H
