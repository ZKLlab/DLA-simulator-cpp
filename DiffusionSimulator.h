#ifndef DIFFUSIONSIMULATOR_H
#define DIFFUSIONSIMULATOR_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <cmath>

class DiffusionSimulator {
    int mNumRows, mNumCols;
    std::vector<std::vector<int>> mGrid;
    std::vector<int> mtimeSpent;

    bool check(int row, int col);

    bool check_neighbours(int row, int col);

    void update_location(int &xPos, int &yPos);

public:
    DiffusionSimulator(int num_rows, int num_cols);

    void print();

    void set(int row, int col);

    void simulate();
};

#endif // DIFFUSIONSIMULATOR_H
