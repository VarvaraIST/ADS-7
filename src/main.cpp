// Copyright 2026 NNTU-CS
#include <iostream>
#include <random>
#include <vector>

#include "train.h"

int main() {
    std::vector<int> sizes = {
    10, 50, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000,
    1500, 2000, 2500, 3000, 3500, 4000, 4500, 5000
};
    std::vector<std::pair<int, int>> resultsAllOff;
    std::vector<std::pair<int, int>> resultsAllOn;
    std::vector<std::pair<int, int>> resultsRandom;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 1);

    for (int n : sizes) {
        Train trainOff;
        for (int i = 0; i < n; i++) {
            trainOff.addCar(false);
        }
        trainOff.getLength();
        resultsAllOff.push_back({ n, trainOff.getOpCount() });

        Train trainOn;
        for (int i = 0; i < n; i++) {
            trainOn.addCar(true);
        }
        trainOn.getLength();
        resultsAllOn.push_back({ n, trainOn.getOpCount() });

        Train trainRand;
        for (int i = 0; i < n; i++) {
            trainRand.addCar(dist(gen));
        }
        trainRand.getLength();
        resultsRandom.push_back({ n, trainRand.getOpCount() });

        std::cout << "n = " << n << " done" << std::endl;
    }

    std::cout << "\n -All OFF- \n";
    for (const auto& p : resultsAllOff) {
        std::cout << p.first << ", " << p.second << "\n";
    }

    std::cout << "\n -All ON- \n";
    for (const auto& p : resultsAllOn) {
        std::cout << p.first << ", " << p.second << "\n";
    }

    std::cout << "\n -Random- \n";
    for (const auto& p : resultsRandom) {
        std::cout << p.first << ", " << p.second << "\n";
    }

    return 0;
}
