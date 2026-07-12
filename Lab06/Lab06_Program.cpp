#include <iostream>
#include <string>
using namespace std;

class tesla
{
public:
    int battery = 100;
    int eMotor = 10;
    string steering = "YORK";
    string color = "Pink";
    int tPrice;

    void cost()
    {
        tPrice = 100000;
    }

    void display(int bPrice, int rPrice)
    {
        cout << "Tesla Details :" << endl;
        cout << "Battery: " << battery << endl;
        cout << "Electric Motor: " << eMotor << endl;
        cout << "Steering: " << steering << endl;
        cout << "Color: " << color << endl;
        cout << "Final Price: " << tPrice << endl;
        cout << "Booking Price: " << bPrice << endl;
        cout << "Remaining Price: " << rPrice << endl;
    }
};

int main()
{
    tesla S;
    int bPrice = 0, rPrice = 0;

    cout << "Enter the booking price: " << endl;
    cin >> bPrice;

    S.cost();
    rPrice = S.tPrice - bPrice;

    S.display(bPrice, rPrice);

    return 0;
}
