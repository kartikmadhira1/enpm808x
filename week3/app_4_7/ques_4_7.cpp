// Copyright 2019 Kartik Madhira

// Program to calculate grade of a student
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <numeric>

using std::istream;
using std::vector;
using std::string;
using std::cin;
using std::cout;

int main() {
    std::vector<double> numberVector;
    double number;
    std::cout << "Enter numbers line by line and terminate with ctrl-D\n";
    while (cin >> number) {
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits
                            <std::streamsize>::max(), '\n');
            std::cout << "Invalid entry, please enter a number: ";
            std::cin >> number;
        }
        numberVector.emplace_back(number);
    }
    if (numberVector.size() == 0) {
        cout << "No numbers entered, exiting:";
        return 0;
    }

    double average = std::accumulate(numberVector.begin(),
                                    numberVector.end(), 0.0)/
                                    numberVector.size();

    std::cout << "Average is: " << average << "\n" << std::endl;
    return 0;
}


