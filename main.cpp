##include <iostream>
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
    Student students[10];
    int count = 0;
    int choice;

    do {
        cout << "\n----- Student Mark System -----\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nEnter Student ID: ";
            cin >> students[count].id;

            cout << "Enter Student Name: ";
            cin.ignore();
            getline(cin, students[count].name);

            students[count].total = 0;

            for (int i = 0; i < 3; i++) {
                cout << "Enter marks for subject " << i + 1 << ": ";
                cin >> students[count].marks[i];
                students[count].total += students[count].marks[i];
            }

            students[count].average = students[count].total / 3;
            students[count].grade =
                calculateGrade(students[count].average);

            count++;
            cout << "Student added successfully!\n";
        }

        else if (choice == 2) {
            if (count == 0) {
                cout << "\nNo student records available.\n";
            } else {
                cout << "\n----- Student Records -----\n";
                for (int i = 0; i < count; i++) {
                    cout << "\nStudent " << i + 1 << endl;
                    cout << "ID: " << students[i].id << endl;
                    cout << "Name: " << students[i].name << endl;
                    cout << "Total: " << students[i].total << endl;
                    cout << "Average: " << students[i].average << endl;
                    cout << "Grade: " << students[i].grade << endl;
                }
            }
        }

        else if (choice == 3) {
            cout << "\nExiting program...\n";
        }

        else {
            cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
