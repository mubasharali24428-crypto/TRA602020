#include <iostream>
#include <iomanip>
using namespace std;

class RobotArm {
private:
    string  armName;
    int     numJoints;
    string* jointNames;
    float*  jointAngles;
    float   maxReach;
public:

    RobotArm() {
        armName = "DefaultArm";
        numJoints = 3;
        maxReach = 50.0f;
        jointNames = new string[numJoints];
        jointAngles = new float[numJoints];
        jointNames[0] = "J1";
        jointNames[1] = "J2";
        jointNames[2] = "J3";
        for (int i = 0; i < numJoints; i++) jointAngles[i] = 0.0f;
        cout << "[Default Constructor] " << armName
             << " created. Joints: " << numJoints << endl;
    }


    RobotArm(string name, int n, string names[], float reach) {
        armName = name;
        numJoints = n;
        maxReach = reach;
        jointNames = new string[numJoints];
        jointAngles = new float[numJoints];
        for (int i = 0; i < numJoints; i++) {
            jointNames[i] = names[i];
            jointAngles[i] = 0.0f;
        }
        cout << "[Param Constructor] " << armName
             << " created. Joints: " << numJoints << endl;
    }

    RobotArm(const RobotArm& other) {
        armName = other.armName + "_copy";
        numJoints = other.numJoints;
        maxReach = other.maxReach;
        jointNames = new string[numJoints];   // NEW independent arrays
        jointAngles = new float[numJoints];
        for (int i = 0; i < numJoints; i++) {
            jointNames[i] = other.jointNames[i];
            jointAngles[i] = other.jointAngles[i];
        }
        cout << "[Copy Constructor] " << armName
             << " cloned. Joints: " << numJoints << endl;
    }



    ~RobotArm() {
        delete[] jointNames;
        delete[] jointAngles;
        cout << "[Destructor] " << armName << " shut down. Memory freed." << endl;
    }


    void setAngle(int jointIndex, float angle) {
        if (jointIndex < 0 || jointIndex >= numJoints) {
            cout << "Invalid joint index " << jointIndex << "." << endl;
            return;
        }
        if (angle > 180.0f) angle = 180.0f;
        if (angle < 0.0f)   angle = 0.0f;
        jointAngles[jointIndex] = angle;
        cout << armName << " Joint[" << jointIndex << "] "
             << jointNames[jointIndex] << " set to " << angle << " deg." << endl;
    }

    void displayArm() const {
        cout << "Arm: " << armName << " | Max Reach: " << maxReach << " cm" << endl;
        for (int i = 0; i < numJoints; i++) {
            cout << "  Joint[" << i << "] " << left << setw(8) << jointNames[i]
                 << " : " << right << setw(2) << jointAngles[i] << " deg" << endl;
        }
    }

    float totalAngle() const {
        float sum = 0.0f;
        for (int i = 0; i < numJoints; i++) sum += jointAngles[i];
        return sum;
    }
};

int main() {

    RobotArm defaultArm;

    string deltaJoints[4] = {"Shoulder", "Elbow", "Wrist", "Gripper"};
    RobotArm delta("Arm-Delta", 4, deltaJoints, 120.0f);

    delta.setAngle(0, 45.0f);
    delta.setAngle(1, 90.0f);
    delta.setAngle(2, 30.0f);


    RobotArm deltaCopy(delta);

    cout << "--- Arm-Delta Status ---" << endl;
    delta.displayArm();
    cout << "Total angle: " << delta.totalAngle() << " deg" << endl;

    cout << "--- Arm-Delta_copy Status ---" << endl;
    deltaCopy.displayArm();
    cout << "Total angle: " << deltaCopy.totalAngle() << " deg" << endl;

    // Deep-copy correctness test: change the copy, original must stay the same
    cout << "--- Deep copy test: change copy's Shoulder to 10 ---" << endl;
    deltaCopy.setAngle(0, 10.0f);
    cout << "Original Arm-Delta (unchanged):" << endl;
    delta.displayArm();

    cout << "--- End of main ---" << endl;
    return 0;
}
