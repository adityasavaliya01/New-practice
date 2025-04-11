#include <iostream>
using namespace std;

const int max_vehicle = 100;
class Vehicle {
public:
    int vehicleID;
    string manufacturer;
    string model;
    int year;
    static int total_vehicles;

    virtual void setvehicle() {
        cout << "Enter vehicle ID: "; cin >> vehicleID;
        cout << "Enter manufacturer: "; cin >> manufacturer;
        cout << "Enter model: "; cin >> model;
        cout << "Enter year: "; cin >> year;
        total_vehicles++;
    }

    virtual void getvehicle() const {
        cout << "Vehicle ID: " << vehicleID
             << "\nManufacturer: " << manufacturer
             << "\nModel: " << model
             << "\nYear: " << year << endl;
    }
    virtual ~Vehicle() {
        
    }
};

int Vehicle::total_vehicles = 0;

class Car :virtual public Vehicle {
public:
    string fueltype;
    void setvehicle() override {
        Vehicle::setvehicle();
        cout << "Enter fuel type: ";
        cin >> fueltype;
    }

    void getvehicle() const override {
        Vehicle::getvehicle();
        cout << "\nFuel Type: " << fueltype;
    }
};

class ElectricCar : public Car {
public:
    int battery_capacity;
    void setvehicle() override {
        Car::setvehicle();
        cout << "Enter battery capacity (in kWh): ";
        cin >> battery_capacity;
    }

    void getvehicle() const override {
        Car::getvehicle();
        cout << "\nBattery Capacity: " << battery_capacity << " kWh";
    }
};

class Aircraft : virtual public Vehicle {
public:
    int flight_range;
};

class FlyingCar : public virtual Car, public virtual Aircraft {
};

class SportsCar : public ElectricCar {
public:
    int topspeed;
    void setvehicle() override {
        ElectricCar::setvehicle();
        cout << "Enter top speed: ";
        cin >> topspeed;
    }

    void getvehicle() const override {
        ElectricCar::getvehicle(); // Call parent display
        cout << "\nTop Speed: " << topspeed << " km/h";
    }
};

class Sedan : public Car {
};

class SUV : public Car {
};

class VehicleRegistry {
public:
    Vehicle* vehicles[max_vehicle];
    int vehicle_count = 0;
    void veh_reg(int n) 
    {
        for (int i = 0; i < n; ++i) {
            cout << "vehicle " << (vehicle_count + 1) << ":\n";
            cout << "Select vehicle type:\n";
            cout << "1. Sedan\n2. SUV\n3. Sports Car\n4. Electric Car\n5. Aircraft\n6. Flying Car\nEnter choice: ";
            int type;
            cin >> type;
            Vehicle* v = nullptr;
            switch (type) {
            case 1:
                v = new Sedan();
                break;
            case 2:
                v = new SUV();
                break;
            case 3:
                v = new SportsCar();
                break;
            case 4:
                v = new ElectricCar();
                break;
            case 5:
                v = new Aircraft();
                break;
            case 6:
                v = new FlyingCar();
                break;
            default:
                cout << "Invalid type.\n";
                continue;
            }
            v->setvehicle();
            vehicles[vehicle_count++] = v;
        }
    }

    void viewallvehicles() const {
        if (vehicle_count == 0) {
            cout << "No vehicles found.\n";
            return;
        }

        for (int i = 0; i < vehicle_count; ++i) {
            vehicles[i]->getvehicle();
            cout << "\n";
        }
    }

    void searchbyid(int id) const {
        for (int i = 0; i < vehicle_count; ++i) {
            if (vehicles[i]->vehicleID == id) {
                vehicles[i]->getvehicle();
                return;
            }
        }
        cout << "Vehicle " << id << " not found.\n";
    }
    ~VehicleRegistry() {
    for (int i = 0; i < vehicle_count; ++i) {
        delete vehicles[i];
    }
}
};

int main() {
    VehicleRegistry vr;
    int ch, n, id;

    while (true) {
        cout << "\n1. Add a vehicle\n2. View all vehicles\n3. Search by ID\n4. Exit\nEnter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "total_vehicles: ";
                cin >> n;
                vr.veh_reg(n);
                break;

            case 2:
                vr.viewallvehicles();
                break;

            case 3:
                cout << "Enter vehicle ID: ";
                cin >> id;
                vr.searchbyid(id);
                break;

            case 4:
                cout << "Exiting program\n";
                return 0;

            default:
                cout << "Enter a valid number\n";
                break;
        }
    }
}
