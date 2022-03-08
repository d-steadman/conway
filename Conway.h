//
// Created by Wil Steadman on 3/7/22.
//

#include <vector>

#ifndef CONWAY_CONWAY_H
#define CONWAY_CONWAY_H

using namespace std;

class Conway {
private:
    vector<bool> map;
    unsigned int width;
    unsigned int height;
    float initial_chance;
    unsigned int rounds;
    unsigned int start_seed = 0;

    //Map generation functions
    void randomVoid(void);
    bool cellOutOfBounds(unsigned x, unsigned y);
    unsigned int cellNeighbors(unsigned x, unsigned y, bool out_of_bounds);
    void simulation(void);

public:
    //Creating the cell map
    Conway(unsigned int width_, unsigned int height_, float initial_chance_, unsigned int rounds_);
    void seed(unsigned int seed_);
    void generate(void);
    void generate(float initial_chance, unsigned int rounds);
    void fillBorder(void);

    //Fetching from the cell map
    bool getCell(unsigned int x, unsigned int y);
    void printMap(void);
};


#endif //CONWAY_CONWAY_H
