//task 1
#include <iostream>
using namespace std;
struct Book {
    int bookId;
    float price;
    int pages;
};
int main() {
    Book myBook;
    Book* ptr = &myBook;

    cout << "--- Enter Book Details ---" << endl;
    cout << "Enter Book ID: ";
    cin >> myBook.bookId;
    cout << "Enter Price: ";
    cin >> myBook.price;
    cout << "Enter Number of Pages: ";
    cin >> myBook.pages;

    int choice;
    cout << "\nOptions:" << endl;
    cout << "1. Display the price of the most costly book (using pointer)" << endl;
    cout << "2. Enter the details again and display the new result" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {

        cout << "\nPrice of the most costly book: Rs" << ptr->price << endl;

    } else if (choice == 2) {

        cout << "\n--- Enter Book Details Again ---" << endl;
        cout << "Enter Book ID: ";
        cin >> ptr->bookId;
        cout << "Enter Price: ";
        cin >> ptr->price;
        cout << "Enter Number of Pages: ";
        cin >> ptr->pages;

        cout << "\n--- Updated Book Record ---" << endl;
        cout << "Book ID: " << ptr->bookId << endl;
        cout << "Price: Rs" << ptr->price << endl;
        cout << "Number of Pages: " << ptr->pages << endl;

    } else {
        cout << "\nInvalid choice entered." << endl;
    }

    return 0;
}
//LAB TASK 2:
#include <iostream>
using namespace std;

struct Citizen {
    long long cnicID;
    char name[30];
    char city[20];
    int age;
};

int main() {
    Citizen c;
    Citizen *ptr;
    ptr = &c;

    cout << "Enter CNIC ID: ";
    cin >> ptr->cnicID;
    cin.ignore();

    cout << "Enter Name: ";
    cin.getline(ptr->name, 30);

    cout << "Enter City: ";
    cin.getline(ptr->city, 20);

    cout << "Enter Age: ";
    cin >> ptr->age;

    int choice;
    cout << "\nPress 1 to update city of residence, 0 to display record: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        cout << "Enter new city: ";
        cin.getline(ptr->city, 20);

        cout << "\n--- Updated NADRA Record ---\n";
        cout << "CNIC ID : " << ptr->cnicID << "\n";
        cout << "Name : " << ptr->name << "\n";
        cout << "City : " << ptr->city << "\n";
        cout << "Age : " << ptr->age << "\n";
    } else {
        cout << "\n--- NADRA Record ---\n";
        cout << "CNIC ID : " << ptr->cnicID << "\n";
        cout << "Name : " << ptr->name << "\n";
        cout << "City : " << ptr->city << "\n";
        cout << "Age : " << ptr->age << "\n";
    }

    return 0;
}
//task 4
#include<iostream>
using namespace std;

struct Bill {
    int accountNo;
    char ownerName[30];
    int unitsConsumed;
    float ratePerUnit;
    float totalBill;
};

void inputBill(Bill *b) {
    cout << "Enter Account No : ";
    cin >> b->accountNo;
    cin.ignore();
    cout << "Enter Owner Name : ";
    cin.getline(b->ownerName, 30);
    cout << "Units Consumed : ";
    cin >> b->unitsConsumed;
    cout << "Rate Per Unit (Rs) : ";
    cin >> b->ratePerUnit;
}

void calculateBill(Bill *b) {
    b->totalBill = b->unitsConsumed * b->ratePerUnit;
    if (b->unitsConsumed > 300) {
        b->totalBill += (b->totalBill * 0.15);
    }
}

void displayBill(Bill *b) {
    cout << "\n========== LESCO Bill ==========\n";
    cout << "Account No : " << b->accountNo << "\n";
    cout << "Owner Name : " << b->ownerName << "\n";
    cout << "Units Used : " << b->unitsConsumed << "\n";
    cout << "Rate/Unit : Rs. " << b->ratePerUnit << "\n";

    float baseAmount = b->unitsConsumed * b->ratePerUnit;
    cout << "Base Amount : Rs. " << baseAmount << "\n";

    if (b->unitsConsumed > 300) {
        cout << "Surcharge 15%: Rs. " << baseAmount * 0.15 << "\n";
    }
    cout << "Total Bill : Rs. " << b->totalBill << "\n";
}

int main() {
    Bill b;

    cout << "=== LESCO Billing System ===\n";
    inputBill(&b);
    calculateBill(&b);
    displayBill(&b);

    return 0;
}
//task 3
#include <iostream>
using namespace std;

struct PetrolPump {
    char name[20];
    float pricePerLiter;
    int availableLiters;
};

void input(PetrolPump *p) {
    cout << "Enter Pump Name: ";
    cin >> p->name;
    cout << "Enter Price per Liter: ";
    cin >> p->pricePerLiter;
    cout << "Enter Available Liters: ";
    cin >> p->availableLiters;
}

void display(PetrolPump *p) {
    cout << "\nPump Name: " << p->name << "\n";
    cout << "Price: " << p->pricePerLiter << "\n";
    cout << "Stock: " << p->availableLiters << " liters\n";
}

int main() {
    PetrolPump p;
    input(&p);
    display(&p);
    return 0;
}
//Home task 1:
#include <iostream>

using namespace std;

struct Patient {
    int patientID;
    char name[30];
    float temperature;
    int severity;
};

Patient* mostCritical(Patient arr[], int n) {
    if (n <= 0) return NULL;
    Patient* critical = &arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i].severity > critical->severity) {
            critical = &arr[i];
        }
    }
    return critical;
}

Patient* findByID(Patient arr[], int n, int id) {
    for (int i = 0; i < n; ++i) {
        if (arr[i].patientID == id) {
            return &arr[i];
        }
    }
    return NULL;
}

void displayPatient(Patient *p) {
    cout << "ID : " << p->patientID << "\n";
    cout << "Name : " << p->name << "\n";
    cout << "Temp : " << p->temperature << " C\n";
    cout << "Severity : " << p->severity << "/10\n";
}

void inputPatient(Patient *p, int index) {
    cout << "\nPatient " << index + 1 << ":\n";
    cout << "ID: ";
    cin >> p->patientID;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
    } else {
        cin.ignore(10000, '\n');
    }

    cout << "Name: ";
    cin.getline(p->name, 30);
    cout << "Temp: ";
    cin >> p->temperature;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Severity: ";
    cin >> p->severity;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

int main() {
    int n;
    cout << "=== General Hospital - Emergency Triage ===\n";
    cout << "Enter number of patients: ";
    cin >> n;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        n = 0;
    }

    Patient patients[50];

    for (int i = 0; i < n; ++i) {
        inputPatient(&patients[i], i);
    }

    cout << "\n--- Most Critical Patient ---\n";
    Patient* critical = mostCritical(patients, n);
    if (critical) {
        for (int i = 0; i < n; i++) {
            if (patients[i].severity == critical->severity) {
                cout << "⚠️ ALERT: Immediate Attention Required!\n";
                displayPatient(&patients[i]);
            }
        }
    }

    char cont = 'y';
    while (cont == 'y' || cont == 'Y') {
        int updateID;
        cout << "\nEnter Patient ID to update (0 to stop): ";
        cin >> updateID;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a valid ID.\n";
            continue;
        }

        if (updateID == 0) break;

        Patient* p = findByID(patients, n, updateID);
        if (p) {
            cout << "Enter new temperature: ";
            cin >> p->temperature;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
            }

            cout << "Enter new severity : ";
            cin >> p->severity;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
            }

            cout << "\n--- Updated Record ---\n";
            displayPatient(p);

            cout << "\n--- New Most Critical Patient ---\n";
            Patient* newCritical = mostCritical(patients, n);
            if (newCritical) {
                for (int i = 0; i < n; i++) {
                    if (patients[i].severity == newCritical->severity) {
                        cout << "⚠️ ALERT: Immediate Attention Required!\n";
                        displayPatient(&patients[i]);
                    }
                }
            }
        } else {
            cout << "Patient not found.\n";
        }

        cout << "\nUpdate another patient? (y/n): ";
        cin >> cont;
        cin.ignore(10000, '\n');
    }

    cout << "\n=== Final Triage Summary ===\n";
    for (int i = 0; i < n; ++i) {
        cout << "ID: " << patients[i].patientID
             << " | Name: " << patients[i].name
             << " | Temp: " << patients[i].temperature
             << " C | Severity: " << patients[i].severity << "\n";
    }

    return 0;
}

