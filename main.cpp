#include <iostream>
#include <chrono>
#include <thread>
#include "DiffusionSimulator.h"

void cls() {
    for (int i = 0; i < 80; i++) {
        std::cout << '\n';
    }
    std::cout << std::endl;
}

void delay(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

int main() {
    int rows = 61, cols = 61;
    DiffusionSimulator sim(rows, cols);
    sim.set(rows / 2, cols / 2);
    for (int i = 0; i < 600; i++) {
        sim.simulate();
        cls();
        sim.print();
        delay(50);
    }
}