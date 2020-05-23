// Random sampling from Normal Distribution
// This code requires C++11, e.g., g++ -std=c++11

#include <iostream>
#include <iomanip>
#include <string>
#include <random>

int main()
{
    std::random_device rd;

    std::mt19937 e2(rd());

    std::normal_distribution<> dist(70, 10); // mean 70, variance 10

    for (int n = 0; n < 100000; ++n) {
        std::cout << dist(e2) << "\n";
    }

}
