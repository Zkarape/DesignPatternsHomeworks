#include <iostream>
#include <string>

class Handler {
protected:
    Handler* nextHandler;

public:
    Handler() : nextHandler(nullptr) {}
    virtual ~Handler() = default;

    void setNextHandler(Handler* handler) {
        nextHandler = handler;
    }

    virtual void handleRequest(const std::string& request) {
        if (nextHandler) {
            nextHandler->handleRequest(request);
        } else {
            std::cout << "No handler available for: " << request << "\n";
        }
    }
};

class FrontDesk : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "General Inquiry") {
            std::cout << "FrontDesk handled the request: " << request << "\n";
        } else if (nextHandler) {
            nextHandler->handleRequest(request);
        }
    }
};

class Manager : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "Escalated Issue") {
            std::cout << "Manager handled the request: " << request << "\n";
        } else if (nextHandler) {
            nextHandler->handleRequest(request);
        }
    }
};

class Director : public Handler {
public:
    void handleRequest(const std::string& request) override {
        if (request == "Critical Complaint") {
            std::cout << "Director handled the request: " << request << "\n";
        } else if (nextHandler) {
            nextHandler->handleRequest(request);
        }
    }
};

int main() {
    FrontDesk frontDesk;
    Manager manager;
    Director director;

    frontDesk.setNextHandler(&manager);
    manager.setNextHandler(&director);

    frontDesk.handleRequest("General Inquiry");
    frontDesk.handleRequest("Escalated Issue");
    frontDesk.handleRequest("Critical Complaint");
    frontDesk.handleRequest("Unknown Issue");

    return 0;
}



// Decouples the client from the handler.
// Promotes the Open/Closed Principle: New handlers can be added without modifying existing ones.
// Flexible and easy to extend.
