#include <iostream>
#include <string>
using namespace std;

class University;

class Student {
private:
    string name;
    int marks;
    int semester;

public:
    Student(const string& n, int m, int s)
        : name(n), marks(m), semester(s) {}

    friend void display(const Student& s, const University& u);
};

class University {
private:
    string universityName;
    int ranking;

public:
    University(const string& uName, int r)
        : universityName(uName), ranking(r) {}

    friend void display(const Student& s, const University& u);
};

void display(const Student& s, const University& u) {
    cout << "====== Student & University Profile ======" << endl;
    cout << "Student Name  : " << s.name << endl;
    cout << "Marks         : " << s.marks << endl;
    cout << "Semester      : " << s.semester << endl;
    cout << "------------------------------------------" << endl;
    cout << "University    : " << u.universityName << endl;
    cout << "Ranking       : " << u.ranking << endl;
    cout << "==========================================" << endl;
}

int main() {
    Student s1("Ali Ahmed", 87, 4);
    University u1("Superior University", 12);

    display(s1, u1);

    return 0;
}
// homme task
#include <iostream>
#include <string>
using namespace std;

class RobotUnit {
private:
    string robotName;
    int robotID;

    static int objectCount;

public:
   
    RobotUnit() : robotName("Unknown"), robotID(0) {
        objectCount++;

        cout << "[Default Constructor] RobotUnit '"
             << robotName << "' (ID: " << robotID
             << ") created. Count: " << objectCount << endl;
    }


    RobotUnit(string name, int id) : robotName(name), robotID(id) {
        objectCount++;

        cout << "[Constructor] RobotUnit '"
             << robotName << "' (ID: " << robotID
             << ") created. Count: " << objectCount << endl;
    }

    
    ~RobotUnit() {
        objectCount--;

        cout << "[Destructor] RobotUnit '"
             << robotName << "' destroyed. Count: "
             << objectCount << endl;
    }


    static int getCount() {
        return objectCount;
    }


    void display() const {
        cout << "Robot: " << robotName
             << "   | ID: " << robotID << endl;
    }
};


int RobotUnit::objectCount = 0;

int main() {
    
    cout << "Objects alive: " << RobotUnit::getCount() << endl;

    
    {
        RobotUnit r1("Scout-1", 101);
        RobotUnit r2("Carrier-2", 102);
        RobotUnit r3;

        cout << "Objects alive: " << RobotUnit::getCount() << endl;

        
        RobotUnit* heapBot = new RobotUnit("Heap-Bot", 200);

        cout << "Objects alive: " << RobotUnit::getCount() << endl;

        
        delete heapBot;

        cout << "Objects alive: " << RobotUnit::getCount() << endl;

        cout << "--- Individual Robot Info ---" << endl;
        r1.display();
        r2.display();
        r3.display();

        cout << "--- End of main ---" << endl;
    }

    
    cout << "Final object count: " << RobotUnit::getCount() << endl;

    return 0;
}
