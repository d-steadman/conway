#include <iostream>
#include <vector>
#include <cmath>
#include <time.h>
#include "Conway.h"

void Conway::randomVoid(void) {
    /**
     * Initializes the map vector with random values weighted by initial_chance.
     */

    //Seeds RNG
    if (start_seed != 0){
        srand(start_seed);

    } else {
        srand((unsigned) time(NULL));
    }

    for (int i = 0; i < width*height; i++){
        map[i] = ((float)rand() / RAND_MAX) > initial_chance;
    }
}

unsigned int Conway::cellNeighbors(unsigned int x, unsigned int y, bool out_of_bounds) {
    /**
     * Gets the amount of adjacent cells to a cell at (x, y) that are alive.
     * out_of_bounds specifies if neighbors outside the map size should be counted as alive or dead.
     */
    int neighbors = 0;

    for (int x_offset = -1; x_offset <= 1; x_offset++){
        for (int y_offset = -1; y_offset <= 1; y_offset++){
            if (cellOutOfBounds(x + x_offset, y + y_offset)){
                neighbors += out_of_bounds;

            } else if (x_offset == 0 && y_offset == 0){
                //We are looking at the target cell, don't count it

            } else {
                neighbors += getCell(x + x_offset, y + y_offset);
            }
        }
    }

    return neighbors;
}

bool Conway::cellOutOfBounds(unsigned x, unsigned y){
    return x < 0 || x >= width || y < 0 || y >= height;
}

void Conway::simulation(void) {
    /**
     * Runs a single simulation step for Conway's game of life. The rules are as follows:
     * 1. Any live cell with two or three live neighbours survives.
     * 2. Any dead cell with three live neighbours becomes a live cell.
     * 3. All other live cells die in the next generation. Similarly, all other dead cells stay dead.
     * (from Wikipedia)
     */
}

Conway::Conway(unsigned int width_, unsigned int height_, float initial_chance_, unsigned int rounds_) {
    /**
     * Initializes the class and establishes global variables.
     * NOTE: No generation happens within the constructor. Leave it up to the end user to generate the map.
     *       This is because this instance could be used to make as many maps as desired.
     */
    width = width_;
    height = height_;
    initial_chance = initial_chance_;
    rounds = rounds_;

    map.resize(width*height);  //The map size is constant. Ensure that the correct amount of memory is reserved

}

void Conway::seed(unsigned int seed_) {
    /**
     * Seeds the RNG so that a map may be regenerated.
     */
     start_seed = seed_;
}

void Conway::generate(void) {
    /**
     * Generates a map with the default provided specifications.
     */
    randomVoid();  //The starting point for the game of life

    for (int i = 0; i < rounds; i++){
        simulation();
    }
}

void Conway::generate(float initial_chance_, unsigned int rounds_) {
    /**
     * Generates a map with new specifications.
     */
    initial_chance = initial_chance_;
    rounds = rounds_;
    generate();
}

void Conway::fillBorder(void) {
    /**
     * Fills in the borders of the map with alive cells.
     */
}

bool Conway::getCell(unsigned int x, unsigned int y) {
    /**
     * Return the contents of a cell (x, y).
     */
    return map[x + height*y];
}

void Conway::printMap(void) {
    /**
     * Prints the map to stdio. Useful for debugging or saving to an output file.
     */
    char repr[2] = {'.', '#'};  //This could be modifiable, but its really not necessary

    for (int y = 0; y < height; y++){
        for (int x = 0; x < width; x++){
            cout << repr[getCell(x, y)];
            //cout << cellNeighbors(x, y, true);
        }
        cout << endl;
    }
}
