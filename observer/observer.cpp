#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(float temperature) = 0;
};

class Subject {
public:
    virtual ~Subject() = default;
    virtual void attach(std::shared_ptr<Observer> observer) = 0;
    virtual void detach(std::shared_ptr<Observer> observer) = 0;
    virtual void notify() = 0;
};

class WeatherStation : public Subject {
private:
    std::vector<std::shared_ptr<Observer>> observers;
    float temperature;

public:
    WeatherStation() : temperature(0.0f) {}

    void setTemperature(float temp) {
        temperature = temp;
        notify();
    }

    float getTemperature() const { return temperature; }

    void attach(std::shared_ptr<Observer> observer) override {
        observers.push_back(observer);
    }

    void detach(std::shared_ptr<Observer> observer) override {
        observers.erase(
            std::remove(observers.begin(), observers.end(), observer),
            observers.end()
        );
    }

    void notify() override {
        for (auto& observer : observers) {
            observer->update(temperature);
        }
    }
};

class PhoneDisplay : public Observer {
public:
    void update(float temperature) override {
        std::cout << "Phone Display: Current Temperature is " << temperature << "°C\n";
    }
};

class ComputerDisplay : public Observer {
public:
    void update(float temperature) override {
        std::cout << "Computer Display: Current Temperature is " << temperature << "°C\n";
    }
};


int main() {
    auto weatherStation = std::make_shared<WeatherStation>();
    auto phoneDisplay = std::make_shared<PhoneDisplay>();
    auto computerDisplay = std::make_shared<ComputerDisplay>();
    weatherStation->attach(phoneDisplay);
    weatherStation->attach(computerDisplay);
    std::cout << "Setting temperature to 25.5°C...\n";
    weatherStation->setTemperature(25.5f);

    std::cout << "Setting temperature to 30.0°C...\n";
    weatherStation->setTemperature(30.0f);
    std::cout << "Detaching Phone Display...\n";
    weatherStation->detach(phoneDisplay);

    std::cout << "Setting temperature to 20.0°C...\n";
    weatherStation->setTemperature(20.0f);

    return 0;
}
