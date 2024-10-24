#include <iostream>

class Singleton {
private:
    static Singleton* instance;

    // Private constructor to prevent direct instantiation
    Singleton() {
        std::cout << "Singleton instance created." << std::endl;
    }

    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    // Public method to get the instance
    static Singleton& getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return *instance;
    }

    // Example method
    void someBusinessLogic() {
        std::cout << "Performing some business logic." << std::endl;
    }

    // Cleanup method (optional, for completeness)
    static void cleanup() {
        delete instance;
        instance = nullptr;
    }
};

// Initialize static member
Singleton* Singleton::instance = nullptr;

// Example usage
int main() {
    // Get the singleton instance
    Singleton& instance1 = Singleton::getInstance();
    instance1.someBusinessLogic();

    // Try to get the instance again
    Singleton& instance2 = Singleton::getInstance();
    instance2.someBusinessLogic();

    // Check if both instances are the same
    std::cout << "Are instances the same? " 
              << (&instance1 == &instance2 ? "Yes" : "No") << std::endl;

    // Cleanup (optional, typically not needed as the singleton lives for the entire program)
    Singleton::cleanup();

    return 0;
}