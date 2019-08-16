#include "DiffusionSimulator.h"

DiffusionSimulator::DiffusionSimulator(int num_rows, int num_cols) : mNumRows(num_rows), mNumCols(num_cols) {
    mGrid.resize(mNumRows);
    for (auto &row : mGrid) {
        row.resize(mNumCols, 0);
    }
    mTimeSpent.resize(17, 0);
}

void DiffusionSimulator::print() {
    std::cout << " + Steps ----+ Num -+ Graph -" << std::endl;
    for (int i = 0; i < mTimeSpent.size(); i++) {
        std::cout << " |           |      |";
        if (i < mTimeSpent.size() - 1) {
            std::cout << std::endl << " | " << std::setw(3) << std::right << i * 10 << " ~ "
                      << std::setw(3) << std::left << i * 10 + 9 << " | ";
        } else {
            std::cout << std::endl << " | " << std::setw(3) << std::right << i * 10 << "+      | ";
        }
        std::cout << std::setw(4) << std::right << mTimeSpent[i] << " | ";
        for (int j = 0; j < mTimeSpent[i]; j++) {
            std::cout << '=';
            if (j >= 100) {
                std::cout << " MORE - - -";
                break;
            }
        }
        std::cout << std::endl;
    }
    std::cout << " |           |      |" << std::endl
              << " +-----------+------+--------" << std::endl << std::endl
              << " +";
    for (int i = 0; i < mNumCols; i++) {
        std::cout << '-';
    }
    std::cout << "+" << std::endl;
    for (auto &row : mGrid) {
        std::cout << " |";
        for (auto &cell : row) {
            std::cout << (cell ? '*' : ' ');
        }
        std::cout << "|" << std::endl;
    }
    std::cout << " +";
    for (int i = 0; i < mNumCols; i++) {
        std::cout << '-';
    }
    std::cout << "+" << std::endl;
}

void DiffusionSimulator::set(int row, int col) {
    mGrid[row][col] = 1;
}

void DiffusionSimulator::simulate() {
    static std::random_device rd;
    static std::default_random_engine gen(rd());
    std::uniform_int_distribution<> dis_side(0, 3);
    std::uniform_int_distribution<> dis_row(0, mNumRows - 1);
    std::uniform_int_distribution<> dis_col(0, mNumCols - 1);
    int r = 0, row, col;
    r = dis_side(gen);
    if (r == 0) {
        row = 0;
        col = dis_col(gen);
    } else if (r == 1) {
        row = mNumRows - 1;
        col = dis_col(gen);
    } else if (r == 2) {
        row = dis_row(gen);
        col = 0;
    } else {
        row = dis_row(gen);
        col = mNumCols - 1;
    }
    int count = 0;
    while (!check_neighbours(row, col)) {
        update_location(col, row);
        count++;
    }
    count /= 10;
    if (count >= mTimeSpent.size()) {
        count = mTimeSpent.size() - 1;
    }
    mTimeSpent[count]++;
    set(row, col);
}

bool DiffusionSimulator::check(int row, int col) {
    if (row < 0 || col < 0 || row >= mNumRows || col >= mNumCols) {
        return false;
    } else {
        return mGrid[row][col] > 0;
    }
}

bool DiffusionSimulator::check_neighbours(int row, int col) {
    int comp[] = {1, 0, -1};
    for (int d1 : comp) {
        for (int d2 : comp) {
            if (d1 == 0 && d2 == 0) {
                continue;
            }
            if (check(row + d1, col + d2)) {
                return true;
            }
        }
    }
    return false;
}

void DiffusionSimulator::update_location(int &xPos, int &yPos) {
    static std::random_device rd;
    static std::default_random_engine gen(rd());
    double vec_angel = atan2(mNumRows / 2.0 - yPos, mNumCols / 2.0 - xPos);
    std::normal_distribution<> dis(vec_angel, M_PI_2);
    double angel = dis(gen);
    xPos += lround(cos(angel));
    yPos += lround(sin(angel));
    if (xPos < 0) {
        xPos = 0;
    }
    if (xPos >= mNumCols) {
        xPos = mNumCols - 1;
    }
    if (yPos < 0) {
        yPos = 0;
    }
    if (yPos >= mNumRows) {
        yPos = mNumRows - 1;
    }
}
