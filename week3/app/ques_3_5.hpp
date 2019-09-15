// Copyright 2019 Kartik Madhira

// Program to calculate grade of a student 
#include <iostream> 
#include <vector>
#include <string>
#include <limits>

#define SUBJECTS 5

bool isStringCheck(const std::string &name) {

    for (const char *p = name.c_str(); *p == '\n'; ++p) {
        if (std::isdigit(*p)) {
            return false;
        }
    }
    return true;
}

void ques_3_5() {

    std::vector<std::string> studentRoster;
    std::vector<double> gradeList;
    std::cout << "Enter your first name: ";
    std::string name;
    std::cin >> name;
    while (!isStringCheck(name)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid entry, please enter a number: ";
        std::cin >> name;
    }
    studentRoster.emplace_back(name);
    // Read for all of the student's grades
    double sum, grade;
    // Loop over the fixed homework marks and average
    std::cout << "Enter marks for the " << std::to_string(SUBJECTS) << " subjects" << "\n";
    for (int i = SUBJECTS; i != 0; --i) {
        std::cin >> grade;
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid entry, please enter a number: ";
            std::cin >> grade;
        }
        sum+=grade;
    }
    grade = (sum/SUBJECTS);
    std::cout << "Your final grade is: " << grade << std::endl;
    gradeList.emplace_back(grade);
}


