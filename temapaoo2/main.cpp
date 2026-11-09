#include <iostream>
#include <string>

// ITEM 4: Make sure that objects are initialized before they’re used.
class SensorData {
private:
    std::string sensorName;
    int measurementCount;
    double lastValue;

public:
    SensorData(const std::string& name, double initialValue)
        : sensorName(name),
          measurementCount(0),
          lastValue(initialValue)
    {
        std::cout << "[Item 4] SensorData creat: " << sensorName << "\n";
    }

    void display() const {
        std::cout << "Sensor: " << sensorName << " | Valoare: " << lastValue << "\n";
    }
};

// ITEM 5: Know what functions C++ silently writes and calls.
class Configuration {
public:
    std::string ipAddress;
    int port;

    Configuration(const std::string& ip, int p) 
        : ipAddress(ip), port(p) {}

    void print() const {
        std::cout << "[Item 5] Config - IP: " << ipAddress << ":" << port << "\n";
    }
};

// ITEM 6: Explicitly disallow the use of compiler generated functions you do not want.
class NetworkLock {
private:
    int lockID;

public:
    NetworkLock(int id) : lockID(id) {
        std::cout << "[Item 6] NetworkLock " << lockID << " a fost preluat.\n";
    }

    ~NetworkLock() {
        std::cout << "[Item 6] NetworkLock " << lockID << " a fost eliberat.\n";
    }

    NetworkLock(const NetworkLock&) = delete;
    NetworkLock& operator=(const NetworkLock&) = delete;
};

int main() {
    std::cout << "--- Testare Item 4 ---\n";

    SensorData sensor("TempSensor_A", 24.5);
    sensor.display();

    std::cout << "\n--- Testare Item 5 ---\n";
    Configuration config1("192.168.1.10", 8080);
    
    Configuration config2 = config1; 
    
    Configuration config3("10.0.0.1", 22);
    config3 = config1; 
    
    config2.print();
    config3.print();

    std::cout << "\n--- Testare Item 6 ---\n";
    NetworkLock lock1(101);

    // DECOMENTAREA LINIEI DE MAI JOS VA GENERA O EROARE DE COMPILARE:
    // NetworkLock lock2 = lock1; 

    // DECOMENTAREA LINIEI DE MAI JOS VA GENERA O EROARE DE COMPILARE:
    // NetworkLock lock3(lock1); 

    std::cout << "\n[Sfarsit executie - Destructorii sunt apelati automat]\n";
    return 0;
}