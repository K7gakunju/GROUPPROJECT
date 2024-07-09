//Creating a C++ program to help BBIT Year 1 students select co-curricular activities involves several steps. Below is a structured approach to developing this program. The program will use vectors to manage students and their selected activities, ensuring it adheres to the rules provided. We'll start with the necessary class definitions and then develop the main program with the menu and functionalities.

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class Activity {
public:
    string name;
    int maxCapacity;
    int currentCapacity;
    vector<string> genders;

    Activity(string name, int maxCapacity) : name(name), maxCapacity(maxCapacity), currentCapacity(0) {}

    bool canAddStudent(string gender) {
        int genderCount = count(genders.begin(), genders.end(), gender);
        if (currentCapacity >= maxCapacity) return false;
        if (name == "Rugby" || name == "Athletics" || name == "Swimming" || name == "Soccer") {
            return genderCount < (0.75 * maxCapacity);
        } else {
            return genderCount < (0.50 * maxCapacity);
        }
    }

    void addStudent(string gender) {
        genders.push_back(gender);
        currentCapacity++;
    }
};


