#include <iostream>

using namespace std;

class Car {
private:
    int maxSpeed;

public:
    Car(int speed) : maxSpeed(speed) { 
        cout << "Construct - " << maxSpeed << endl;
    }
    void setSpeed(int speed) {
        maxSpeed = speed;
    }
    void showSpeed() {
        cout << "Max speed  - " << maxSpeed << endl;
    }
    int getSpeed() {
        return maxSpeed;
    }
    ~Car() {
        cout << "Delete object" << endl;
    }
    static Car add_speed(Car c1, Car c2);
};
Car Car::add_speed(Car c1, Car c2) {
    return Car(c1.getSpeed() + c2.getSpeed());
}

int main()
{
    Car c1(12), c2(12);
    c1.setSpeed(100);
    //c2.setSpeed(200);
    c1.showSpeed();
    c2.showSpeed();
    auto c3 = Car::add_speed(c1, c2);
    c3.showSpeed();
}

