#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    vector<int> grades;
};

void addStudent(vector<Student>& students) {
    Student student;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, student.name);
    int grade;
    cout << "Enter grades (enter -1 to stop): " << endl;
    while (true) {
        cin >> grade;
        if (grade == -1) break;
        student.grades.push_back(grade);
    }
    students.push_back(student);
}

void displayStudents(const vector<Student>& students) {
    for (const auto& student : students) {
        cout << "Student Name: " << student.name << endl;
        cout << "Grades: ";
        for (int grade : student.grades) {
            cout << grade << " ";
        }
        cout << endl;
    }
}

double calculateAverage(const vector<int>& grades) {
    int sum = 0;
    for (int grade : grades) {
        sum += grade;
    }
    return grades.empty() ? 0.0 : static_cast<double>(sum) / grades.size();
}

void displayStatistics(const vector<Student>& students) {
    for (const auto& student : students) {
        if (!student.grades.empty()) {
            double average = calculateAverage(student.grades);
            int highest = *max_element(student.grades.begin(), student.grades.end());
            int lowest = *min_element(student.grades.begin(), student.grades.end());
            cout << "Statistics for " << student.name << ":" << endl;
            cout << "Average Grade: " << average << endl;
            cout << "Highest Grade: " << highest << endl;
            cout << "Lowest Grade: " << lowest << endl;
        } else {
            cout << "No grades available for " << student.name << endl;
        }
    }
}

int main() {
    vector<Student> students;
    while (true) {
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Display Statistics" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            addStudent(students);
        } else if (choice == 2) {
            displayStudents(students);
        } else if (choice == 3) {
            displayStatistics(students);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
