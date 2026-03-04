#include <iostream>
#include <iomanip>  
using namespace std;

// Abstract base class
class Vehicle {
protected:
    double baseRate;
    double taxRate;

public:
    Vehicle(double base, double tax) : baseRate(base), taxRate(tax) {}

    virtual double calculateTaxes() = 0;
    virtual double calculateTotalCost() = 0;

    virtual ~Vehicle() {}
};

// NormalCar derived class
class NormalCar : public Vehicle {
public:
    NormalCar(double base) : Vehicle(base, 0.15) {}

    double calculateTaxes() override {
        return taxRate * baseRate;
    }

    double calculateTotalCost() override {
        return baseRate + calculateTaxes();
    }
};

// LuxuryCar derived class
class LuxuryCar : public Vehicle {
private:
    double eduty;

public:
    LuxuryCar(double base) : Vehicle(base, 0.20), eduty(30000) {}

    double calculateTaxes() override {
        return (taxRate * baseRate) + eduty;
    }

    double calculateTotalCost() override {
        return baseRate + calculateTaxes();
    }
};

int main() {
    // Create objects using base class pointers (polymorphism)
    Vehicle* standardCar = new NormalCar(500000);   
    Vehicle* luxuryCar = new LuxuryCar(2000000);   

    // Prevent scientific notation and remove decimal places
    cout << fixed << setprecision(0);

    cout << "Standard Car Total Cost: " << standardCar->calculateTotalCost() << endl;
    cout << "Luxury Car Total Cost: " << luxuryCar->calculateTotalCost() << endl;

    // Free allocated memory
    delete standardCar;
    delete luxuryCar;

    return 0;
}