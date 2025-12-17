#include <iostream>
using namespace std;

struct Student {
    int id;
    string name;
    float marks[3];
    float total;
    float average;
    char grade;
};

char calculateGrade(float avg) {
    if (avg >= 75)
        return 'A';
    else if (avg >= 65)
        return 'B';
    else if (avg >= 55)
        return 'C';
    else if (avg >= 35)
        return 'S';
    else
        return 'F';
}

int main() {
    Student s;

    cout << "----- Student Mark System -----\n";

    cout << "Enter Student ID: ";
    cin >> s.id;

    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, s.name);

    s.total = 0;

    for (int i = 0; i < 3; i++) {
        cout << "Enter marks for subject " << i + 1 << ": ";
        cin >> s.marks[i];
        s.total += s.marks[i];
    }

    s.average = s.total / 3;
    s.grade = calculateGrade(s.average);

    cout << "\n----- Student Report -----\n";
    cout << "ID: " << s.id << endl;
    cout << "Name: " << s.name << endl;
    cout << "Total Marks: " << s.total << endl;
    cout << "Average: " << s.average << endl;
    cout << "Grade: " << s.grade << endl;

    return 0;
}
