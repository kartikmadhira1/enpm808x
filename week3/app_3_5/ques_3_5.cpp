// Copyright 2019 Kartik Madhira

// Program to calculate grade of a student
#include <iostream>
#include <vector>
#include <string>
#include <limits>

bool isStringCheck(const std::string &name) {
    for (const char *p = name.c_str(); *p == '\n'; ++p) {
        if (std::isdigit(*p)) {
            return false;
        }
    }
    return true;
}

void printVectors(const std::vector<std::string> &nameRoster,
                  const std::vector<double> &gradeList) {
        for (uint16_t i = 0; i < nameRoster.size(); ++i) {
            std::cout << "Name: " << nameRoster[i] << ", ";
            std::cout << "Final grade: " << gradeList[i] << "\n";
        }
    }

int main() {
    int studentCount, subjectCount;
    std::vector<std::string> studentRoster;
    std::vector<double> gradeList;
    std::cout << "Enter the number of students: ";
    std::cin >> studentCount;
    while (!std::isdigit(studentCount)) {
        std::cout << "Please enter a valid number between 1 and 10";
        std::cin >> studentCount;
    }
    std::cout << "Enter the number of subjects: ";
    std::cin >> subjectCount;
    while (!std::isdigit(subjectCount)) {
        std::cout << "Please enter a valid number between 1 and 10";
        std::cin >> subjectCount;
    }
    while (studentCount != 0) {
        std::cout << "Enter your first name: ";
        std::string name;
        std::cin >> name;
        while (!isStringCheck(name)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid entry, please enter a name: ";
            std::cin >> name;
        }
        studentRoster.emplace_back(name);
        // Read for all of the student's grades
        double sum, grade;
        // Loop over the fixed homework marks and average
        std::cout << "Enter marks for the "
                  << std::to_string(subjectCount)
                  << " subjects" << "\n";
        for (int i = subjectCount; i != 0; --i) {
            std::cin >> grade;
            while (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits
                                <std::streamsize>::max(), '\n');
                std::cout << "Invalid entry, please enter a number: ";
                std::cin >> grade;
            }
            sum+=grade;
        }
        grade = (sum/subjectCount);
        std::cout << "Your final grade is: " << grade << std::endl;
        gradeList.emplace_back(grade);
        studentCount--;
    }
    printVectors(studentRoster, gradeList);
    return 0;
}


