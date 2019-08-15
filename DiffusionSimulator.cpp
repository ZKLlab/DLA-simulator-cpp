#include "DiffusionSimulator.h"

DiffusionSimulator::DiffusionSimulator(int num_rows, int num_cols) : mNumRows(num_rows), mNumCols(num_cols) {
    mGrid.resize(mNumRows);
    for (auto &row : mGrid) {
        row.resize(mNumCols, 0);
    }
}

void DiffusionSimulator::print() {

}

void DiffusionSimulator::set(int row, int col) {

}

bool DiffusionSimulator::check(int row, int col) {
    return false;
}

bool DiffusionSimulator::check_neighbours(int row, int col) {
    return false;
}

void DiffusionSimulator::simulate() {

}

void DiffusionSimulator::update_location(int &xPos, int &yPos) {

}
