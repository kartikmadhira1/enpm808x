// Copyright 2019 Kartik Madhira

// Program to calculate grade of a student
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <map>
#include <sstream>

using std::istream;
using std::vector;
using std::map;
using std::string;
using std::cin;
using std::cout;

int main() {
    std::string word;
    vector<string> wordVector;
    map<string, int> wordDictionary;
    std::cout << "Enter the word stream to add in the dictionary" <<
                 "followed by ctrl-D to terminate:\n";
    int totalWords = 0;
    int uniqueWords = 0;
    while (cin) {
        std::getline(cin, word);
        std::stringstream wordStream(word);
        string eachWord;
        while (wordStream >> eachWord) {
            wordVector.push_back(eachWord);
            wordDictionary[eachWord]++;
            totalWords++;
        }
        if (word.empty()) {
            continue;
        }
        wordStream.clear();
    }
    map<string, int>::iterator it;
    for (it = wordDictionary.begin(); it != wordDictionary.end(); it++) {
        cout << "The word is: " << it->first << ", ";
        uniqueWords++;
        cout << "Occuring - " << it->second << " times" << std::endl;
    }
    cout << "\nTotal number of words are: " << totalWords <<std::endl;
    cout << "\nTotal number of unique words are: " << uniqueWords <<std::endl;

    return 0;
}


