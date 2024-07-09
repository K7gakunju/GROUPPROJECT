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

class Student {
public:
    string firstName;
    string surname;
    string gender;
    int age;
    int group;
    vector<Activity*> activities;

    Student(string firstName, string surname, string gender, int age, int group)
            : firstName(firstName), surname(surname), gender(gender), age(age), group(group) {}

    void addActivity(Activity* activity) {
        activities.push_back(activity);
        activity->addStudent(gender);
    }
};





class CoCurricularSystem {
private:
    vector<Student> students;
    vector<Activity> sports;
    vector<Activity> clubs;

public:
    CoCurricularSystem() {
        // Initialize sports and clubs
        sports.push_back(Activity("Rugby", 20));
        sports.push_back(Activity("Athletics", 20));
        sports.push_back(Activity("Swimming", 20));
        sports.push_back(Activity("Soccer", 20));

        clubs.push_back(Activity("Journalism Club", 60));
        clubs.push_back(Activity("Red Cross Society", 60));
        clubs.push_back(Activity("AISEC", 60));
        clubs.push_back(Activity("Business Club", 60));
        clubs.push_back(Activity("Computer Science Club", 60));
    }

    void addStudent() {
        string firstName, surname, gender;
        int age, group;
        cout << "Enter First Name: ";
        cin >> firstName;
        cout << "Enter Surname: ";
        cin >> surname;
        cout << "Enter Gender (Male/Female): ";
        cin >> gender;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Group (1-3): ";
        cin >> group;

        Student student(firstName, surname, gender, age, group);
        students.push_back(student);
        allocateActivities(&students.back());
    }


    void allocateActivities(Student* student) {
        int choice, numClubs = 0, numSports = 0;
        do {
            cout << "Choose an activity for " << student->firstName << " " << student->surname << endl;
            cout << "1. Add Sport\n2. Add Club/Society\n3. Done\n";
            cin >> choice;

            if (choice == 1 && numSports < 1) {
                displayActivities(sports);
                int sportChoice;
                cout << "Select a sport: ";
                cin >> sportChoice;
                if (sports[sportChoice - 1].canAddStudent(student->gender)) {
                    student->addActivity(&sports[sportChoice - 1]);
                    numSports++;
                } else {
                    cout << "Cannot add to this sport. Either full or gender limit reached.\n";
                }
            } else if (choice == 2 && numClubs < 3) {
                displayActivities(clubs);
                int clubChoice;
                cout << "Select a club: ";
                cin >> clubChoice;
                if (clubs[clubChoice - 1].canAddStudent(student->gender)) {
                    student->addActivity(&clubs[clubChoice - 1]);
                    numClubs++;
                } else {
                    cout << "Cannot add to this club. Either full or gender limit reached.\n";
                }
            } else if (choice == 3) {
                if (numClubs + numSports >= 1) break;
                else cout << "You must choose at least one activity.\n";
            } else {
                cout << "Invalid choice or activity limit reached.\n";
            }
        } while (true);
    }






