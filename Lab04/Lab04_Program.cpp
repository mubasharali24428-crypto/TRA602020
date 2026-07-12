//TASK1
#include <iostream>
using namespace std;

struct Result {
    float marks;
    char grade;
};

struct Record {
    int rollNo;
    Result res;
};

int main() {
    Record r;
    cout << "Enter Roll Number: ";
    cin >> r.rollNo;
    cout << "Enter Marks: ";
    cin >> r.res.marks;
    cout << "Enter Grade: ";
    cin >> r.res.grade;

    cout << "\n--- Student Record ---\n";
    cout << "Roll Number: " << r.rollNo << "\n";
    cout << "Marks: " << r.res.marks << "\n";
    cout << "Grade: " << r.res.grade << "\n";

    return 0;
}

//TASK 2


#include <iostream>
#include <string>
using namespace std;

struct Data {
    string name;
    string color;
};

struct Car {
    string model;
    float topSpeed;
    int noOfGears;
    Data d;
};

int main() {
    Car c;
    cout << "Enter Car Name: ";
    cin >> c.d.name;
    cout << "Enter Car Color: ";
    cin >> c.d.color;
    cout << "Enter Car Model: ";
    cin >> c.model;
    cout << "Enter Top Speed (km/h): ";
    cin >> c.topSpeed;
    cout << "Enter No. of Gears: ";
    cin >> c.noOfGears;

    if (c.topSpeed > 200 && c.noOfGears > 4) {
        cout << "\n--- Car Details ---\n";
        cout << "Name: " << c.d.name << "\nColor: " << c.d.color << "\nModel: " << c.model
             << "\nTop Speed: " << c.topSpeed << "\nGears: " << c.noOfGears << "\n";
    } else {
        cout << "\nYour car is not suitable for the race.\n";
    }

    return 0;
}
//TASK3
#include <iostream>
using namespace std;

struct Complex {
    float real;
    float imag;
};

Complex addition(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex subtract(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

Complex multiply(Complex a, Complex b) {
    Complex result;
    result.real = (a.real * b.real) - (a.imag * b.imag);
    result.imag = (a.real * b.imag) + (a.imag * b.real);
    return result;
}

int main() {
    Complex num1, num2, ans;

    cout << "Enter the real part of the first number: ";
    cin >> num1.real;
    cout << "Enter the imaginary part of the first number: ";
    cin >> num1.imag;

    cout << "Enter the real part of the second number: ";
    cin >> num2.real;
    cout << "Enter the imaginary part of the second number: ";
    cin >> num2.imag;

    cout << "\n--- Results ---\n";

    ans = addition(num1, num2);
    cout << "Sum: " << ans.real << " + " << ans.imag << "i\n";

    ans = subtract(num1, num2);
    cout << "Difference: " << ans.real << " + " << ans.imag << "i\n";

    ans = multiply(num1, num2);
    cout << "Product: " << ans.real << " + " << ans.imag << "i\n";

    return 0;
}
//TASK4
#include<iostream>
#include<string>
using namespace std;

struct Author {
    string name;
    string nationality;
};

struct Book {
    string title;
    string ISBN;
    double price;
    int pubYear;
    Author author;
};

int main() {
    Book library[3];

    for(int i = 0; i < 3; i++) {
        cout << "\n--- Enter details for Book " << i+1 << " ---" << endl;
        cout << "Enter title: ";
        getline(cin >> ws, library[i].title);
        cout << "Enter ISBN: ";
        getline(cin, library[i].ISBN);
        cout << "Enter price: ";
        cin >> library[i].price;
        cout << "Enter publication year: ";
        cin >> library[i].pubYear;
        cout << "Enter author name: ";
        getline(cin >> ws, library[i].author.name);
        cout << "Enter author nationality: ";
        getline(cin, library[i].author.nationality);
    }

    cout << "\nBooks published after 2015:" << endl;
    for(int i = 0; i < 3; i++) {
        if(library[i].pubYear > 2015) {
            cout << "Title: " << library[i].title << " | Year: " << library[i].pubYear
                 << " | Author: " << library[i].author.name << endl;
        }
    }
    return 0;
}
//TASK5
#include<iostream>
#include<string>
using namespace std;

struct Student {
    string name;
    string rollNo;
    float marks[3];
    float gpa;
};

void calculateGPA(Student &s) {
    s.gpa = (s.marks[0] + s.marks[1] + s.marks[2]) / 3.0 / 10.0;
    if (s.gpa > 4.0) {
        s.gpa = 4.0;
    }
}

void displayStudent(Student s) {
    cout << "\nStudent Details:\n";
    cout << "Name     : " << s.name << "\n";
    cout << "Roll No  : " << s.rollNo << "\n";
    cout << "Marks    : " << s.marks[0] << " " << s.marks[1] << " " << s.marks[2] << "\n";
    cout << "GPA      : " << s.gpa << " / 4.0\n";
}

int main() {
    Student students[2];

    for(int i = 0; i < 2; i++) {
        cout << "\n--- Student " << i+1 << " ---\n";
        cout << "Enter name: ";
        getline(cin >> ws, students[i].name);
        cout << "Enter roll number: ";
        getline(cin, students[i].rollNo);
        cout << "Enter marks for Subject 1: ";
        cin >> students[i].marks[0];
        cout << "Enter marks for Subject 2: ";
        cin >> students[i].marks[1];
        cout << "Enter marks for Subject 3: ";
        cin >> students[i].marks[2];

        calculateGPA(students[i]);
        displayStudent(students[i]);
    }
    return 0;
}
//LABTASK6
#include <iostream>
#include <string>
using namespace std;

struct Account {
    string accountNumber;
    string holderName;
    double balance;
};

Account createAccount() {
    Account acc;
    cout << "=== Create New Account ===\n";
    cout << "Enter account number: ";
    getline(cin >> ws, acc.accountNumber);
    cout << "Enter account holder name: ";
    getline(cin, acc.holderName);
    cout << "Enter initial balance: ";
    cin >> acc.balance;
    return acc;
}

void deposit(Account &acc, double amount) {
    acc.balance += amount;
    cout << "\n=== Deposit Receipt ===\n";
    cout << "Account  : " << acc.accountNumber << "\n";
    cout << "Holder   : " << acc.holderName << "\n";
    cout << "Deposited: Rs. " << amount << "\n";
    cout << "Balance  : Rs. " << acc.balance << "\n\n";
}

bool withdraw(Account &acc, double amount) {
    if (acc.balance >= amount) {
        acc.balance -= amount;
        return true;
    }
    return false;
}

int main() {
    Account myAcc = createAccount();

    double depAmount;
    cout << "\nEnter amount to deposit: ";
    cin >> depAmount;
    deposit(myAcc, depAmount);

    int numWithdrawals;
    cout << "How many withdrawals would you like to make? ";
    cin >> numWithdrawals;

    for (int i = 0; i < numWithdrawals; i++) {
        double wAmount;
        cout << "\nEnter amount for withdrawal " << i + 1 << ": ";
        cin >> wAmount;

        if (withdraw(myAcc, wAmount)) {
            cout << "Withdrawal successful!\n";
            cout << "Balance after withdrawal: Rs. " << myAcc.balance << "\n";
        } else {
            cout << "Insufficient funds!\n";
            cout << "Required: Rs. " << wAmount << " | Available: Rs. " << myAcc.balance << "\n";
        }
    }

    cout << "\nFinal Balance: Rs. " << myAcc.balance << endl;
    return 0;
}
//HOMETASK1
#include <iostream>
#include <string>
using namespace std;

struct Date {
    int day, month, year;
};

struct Phonebook {
    string name;
    string city;
    string phoneNumber;
    Date d;
};

int main() {
    Phonebook p;
    cout << "Enter Name: "; getline(cin >> ws, p.name);
    cout << "Enter City: "; getline(cin, p.city);
    cout << "Enter Phone Number: "; getline(cin, p.phoneNumber);
    cout << "Enter Date (Day Month Year): "; cin >> p.d.day >> p.d.month >> p.d.year;

    cout << "\n--- Phonebook Record ---\n";
    cout << "Name: " << p.name << "\nCity: " << p.city << "\nPhone: " << p.phoneNumber
         << "\nDate: " << p.d.day << "/" << p.d.month << "/" << p.d.year << "\n";

    return 0;
}
//HTASK2
#include <iostream>
using namespace std;

struct Parameters {
    float length, width;
};

struct Result {
    float area, perimeter;
};

struct Rectangle {
    Parameters p;
    Result r;
};

int main() {
    Rectangle rect;
    cout << "Enter Length: "; cin >> rect.p.length;
    cout << "Enter Width: "; cin >> rect.p.width;

    rect.r.area = rect.p.length * rect.p.width;
    rect.r.perimeter = 2 * (rect.p.length + rect.p.width);

    cout << "\nArea: " << rect.r.area << "\nPerimeter: " << rect.r.perimeter << "\n";
    return 0;
}
//HTASK3
#include<iostream>
#include<string>
using namespace std;

struct Instructor {
    string name;
    string department;
};

struct Course {
    string courseCode;
    string courseName;
    int creditHours;
    int maxSeats;
    int enrolledStudents;
    Instructor instructor;
};

bool enrollStudent(Course &c) {
    if (c.enrolledStudents < c.maxSeats) {
        c.enrolledStudents++;
        return true;
    }
    return false;
}

void displayCourse(Course c) {
    cout << "\nCode         : " << c.courseCode << "\n";
    cout << "Name         : " << c.courseName << "\n";
    cout << "Credit Hours : " << c.creditHours << "\n";
    cout << "Instructor   : " << c.instructor.name << " (" << c.instructor.department << ")\n";
    cout << "Seats        : " << c.enrolledStudents << " / " << c.maxSeats
         << " (" << (c.maxSeats - c.enrolledStudents) << " remaining)\n";
}

int main() {
    Course courses[2];

    for(int i = 0; i < 2; i++) {
        cout << "\n--- Enter Details for Course " << i + 1 << " ---\n";
        cout << "Course Code: ";
        getline(cin >> ws, courses[i].courseCode);
        cout << "Course Name: ";
        getline(cin, courses[i].courseName);
        cout << "Credit Hours: ";
        cin >> courses[i].creditHours;
        cout << "Max Seats: ";
        cin >> courses[i].maxSeats;

        courses[i].enrolledStudents = 0;

        cout << "Instructor Name: ";
        getline(cin >> ws, courses[i].instructor.name);
        cout << "Instructor Department: ";
        getline(cin, courses[i].instructor.department);
    }

    cout << "\n--- Enrollment Phase ---\n";
    for(int i = 0; i < 2; i++) {
        int studentsToEnroll;
        cout << "\nHow many students want to enroll in " << courses[i].courseCode << "? ";
        cin >> studentsToEnroll;

        for(int j = 0; j < studentsToEnroll; j++) {
            cout << "Enrolling student " << j + 1 << " in " << courses[i].courseCode << "... ";
            if (enrollStudent(courses[i])) {
                cout << "Success!\n";
            } else {
                cout << "Course Full!\n";
            }
        }
    }

    cout << "\n=== Final Course Details ===";
    displayCourse(courses[0]);
    displayCourse(courses[1]);

    return 0;
}
//HTASK4
#include<iostream>
#include<string>
using namespace std;

struct Date {
    int day, month, year;
};

struct Doctor {
    string name;
    string specialization;
};

struct Patient {
    string patientID;
    string name;
    int age;
    Date admissionDate;
    Doctor assignedDoctor;
    double dailyCharge;
};

double calculateBill(Patient p, int days) {
    return p.dailyCharge * days;
}

void displayPatientReport(Patient p, int days) {
    cout << "\n======= HOSPITAL BILL =======\n";
    cout << "Patient ID    : " << p.patientID << "\n";
    cout << "Name          : " << p.name << "\n";
    cout << "Age           : " << p.age << "\n";
    cout << "Admission     : " << p.admissionDate.day << " / " << p.admissionDate.month << " / " << p.admissionDate.year << "\n";
    cout << "Doctor        : " << p.assignedDoctor.name << "\n";
    cout << "Specialization: " << p.assignedDoctor.specialization << "\n";
    cout << "-----------------------------\n";
    cout << "Days Admitted : " << days << "\n";
    cout << "Daily Charge  : Rs. " << p.dailyCharge << "\n";
    cout << "TOTAL BILL    : Rs. " << calculateBill(p, days) << "\n";
    cout << "=============================\n";
}

int main() {
    Patient patients[2];
    int daysAdmitted[2];

    for(int i = 0; i < 2; i++) {
        cout << "\n--- Enter Details for Patient " << i + 1 << " ---\n";
        cout << "Patient ID: ";
        getline(cin >> ws, patients[i].patientID);
        cout << "Patient Name: ";
        getline(cin, patients[i].name);
        cout << "Age: ";
        cin >> patients[i].age;

        cout << "Admission Day (DD): "; cin >> patients[i].admissionDate.day;
        cout << "Admission Month (MM): "; cin >> patients[i].admissionDate.month;
        cout << "Admission Year (YYYY): "; cin >> patients[i].admissionDate.year;

        cout << "Doctor Name: ";
        getline(cin >> ws, patients[i].assignedDoctor.name);
        cout << "Doctor Specialization: ";
        getline(cin, patients[i].assignedDoctor.specialization);

        cout << "Daily Charge (Rs): ";
        cin >> patients[i].dailyCharge;
        cout << "Days Admitted: ";
        cin >> daysAdmitted[i];
    }

    for(int i = 0; i < 2; i++) {
        displayPatientReport(patients[i], daysAdmitted[i]);
    }

    return 0;
}