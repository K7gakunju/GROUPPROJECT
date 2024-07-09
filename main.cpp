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
    int max_capacity;
    int current_capacity;
    vector<string> genders;

    Activity(string name, int max_capacity) : name(name), max_capacity(max_capacity), current_capacity(0) {}

    bool can_add_student(string gender) {
        int gender_count = count(genders.begin(), genders.end(), gender);
        if (current_capacity >= max_capacity) return false;
        if (name == "Rugby" || name == "Athletics" || name == "Swimming" || name == "Soccer") {
            return gender_count < (0.75 * max_capacity);
        } else {
            return gender_count < (0.50 * max_capacity);
        }
    }

    void add_student(string gender) {
        genders.push_back(gender);
        current_capacity++;
    }
};

class Student {
public:
    string first_name;
    string surname;
    string gender;
    int age;
    int group;
    vector<Activity*> activities;






class co_curricular_system {
private:
    vector<Student> students;
    vector<Activity> sports;
    vector<Activity> clubs;

public:
    co_curricular_system() {
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

    void add_student() {
        string first_name, surname, gender;
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

        Student student(first_name, surname, gender, age, group);
        students.push_back(student);
        allocate_activities(&students.back());
    }

    void allocate_activities(Student* student) {
        int choice, num_clubs = 0, numSports = 0;
        do {
            cout << "Choose an activity for " << student->first_name << " " << student->surname << endl;
            cout << "1. Add Sport\n2. Add Club/Society\n3. Done\n";
            cin >> choice;

            if (choice == 1 && numSports < 1) {
                display_activities(sports);
                int sport_choice;
                cout << "Select a sport: ";
                cin >> sport_choice;
                if (sports[sport_choice - 1].can_add_student(student->gender)) {
                    student->add_activity(&sports[sport_choice - 1]);
                    numSports++;
                } else {
                    cout << "Cannot add to this sport. Either full or gender limit reached.\n";
                }
            } else if (choice == 2 && numClubs < 3) {
                display_activities(clubs);
                int club_choice;
                cout << "Select a club: ";
                cin >> clubChoice;
                if (clubs[club_choice - 1].can_add_student(student->gender)) {
                    student->add_activity(&clubs[club_choice - 1]);
                    num_clubs++;
                } else {
                    cout << "Cannot add to this club. Either full or gender limit reached.\n";
                }
            } else if (choice == 3) {
                if (num_clubs + num_sports >= 1) break;
                else cout << "You must choose at least one activity.\n";
            } else {
                cout << "Invalid choice or activity limit reached.\n";
            }
        } while (true);
    }

    void display_activities(vector<Activity>& activities) {
        for (int i = 0; i < activities.size(); ++i) {
            cout << i + 1 << ". " << activities[i].name << " (" << activities[i].current_capacity << "/" << activities[i].max_capacity << ")\n";
        }
    }

    void viewStudents() {
        for (const auto& student : students) {
            cout << student.firstName << " " << student.surname << ", Group " << student.group << ", Activities: ";
            for (const auto& activity : student.activities) {
                cout << activity->name << " ";
            }
            cout << endl;
        }
    }

    void view_activities(vector<Activity>& activities) {
        for (const auto& activity : activities) {
            cout << activity.name << ": " << activity.current_capacity << "/" << activity.max_capacity << endl;
        }
    }

    void save_to_file() {
        ofstream outFile("students.csv");
        out_file << "first_name,Surname,Gender,Age,Group,Activities\n";
        for (const auto& student : students) {
            out_file << student.first_name << "," << student.surname << "," << student.gender << "," << student.age << "," << student.group << ",";
            for (size_t i = 0; i < student.activities.size(); ++i) {
                out_file << student.activities[i]->name;
                if (i != student.activities.size() - 1) out_file << "|";
            }
            out_file << "\n";
        }
        out_file.close();
        cout << "Data saved to students.csv\n";
    }

    void run() {
        int choice;
        do {
            cout << "1. Add Student\n2. View Students\n3. View Clubs/Societies\n4. View Sports\n5. Save to File\n6. Exit\n";
            cin >> choice;
            switch (choice) {
                case 1: addStudent(); break;
                case 2: viewStudents(); break;
                case 3: viewActivities(clubs); break;
                case 4: viewActivities(sports); break;
                case 5: saveToFile(); break;
                case 6: cout << "Exiting...\n"; break;
                default: cout << "Invalid choice.\n";
            }
        } while (choice != 6);
    }
};





int main() {
    CoCurricularSystem system;
    system.run();
    return 0;
}





