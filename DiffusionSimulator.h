#ifndef DIFFUSIONSIMULATOR_H
#define DIFFUSIONSIMULATOR_H

#include <vector>

class DiffusionSimulator {
    int mNumRows; //
    int mNumCols; //
    std::vector<std::vector<int>> mGrid; //
    void update_location(int &xPos, int &yPos); //
public:
    DiffusionSimulator(int num_rows, int num_cols); //
    void print(); //
    void set(int row, int col); //
    bool check(int row, int col); //
    bool check_neighbours(int row, int col); //
    void simulate(); //
};

#endif // DIFFUSIONSIMULATOR_H
