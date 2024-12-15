#include <iostream>
#include <memory>
#include <string>

class MessagingAPI {
public:
    virtual ~MessagingAPI() = default;
    virtual void sendMessage(const std::string& recipient, const std::string& message) = 0;
};

class SimpleMessagingAPI : public MessagingAPI {
public:
    void sendMessage(const std::string& recipient, const std::string& message) override {
        std::cout << "SimpleAPI: Sending message to " << recipient << ": " << message << "\n";
    }
};

class AdvancedMessagingAPI : public MessagingAPI {
public:
    void sendMessage(const std::string& recipient, const std::string& message) override {
        std::cout << "AdvancedAPI: Sending encrypted message to " << recipient << ": " << message << "\n";
    }
};


class Notification {
protected:
    std::shared_ptr<MessagingAPI> messagingAPI;

public:
    Notification(std::shared_ptr<MessagingAPI> api) : messagingAPI(api) {}
    virtual ~Notification() = default;

    virtual void notify(const std::string& recipient, const std::string& message) = 0;
};

class EmailNotification : public Notification {
public:
    EmailNotification(std::shared_ptr<MessagingAPI> api) : Notification(api) {}

    void notify(const std::string& recipient, const std::string& message) override {
        std::string emailMessage = "[Email] " + message;
        messagingAPI->sendMessage(recipient, emailMessage);
    }
};

class SMSNotification : public Notification {
public:
    SMSNotification(std::shared_ptr<MessagingAPI> api) : Notification(api) {}

    void notify(const std::string& recipient, const std::string& message) override {
        std::string smsMessage = "[SMS] " + message;
        messagingAPI->sendMessage(recipient, smsMessage);
    }
};

int main() {
    std::shared_ptr<MessagingAPI> simpleAPI = std::make_shared<SimpleMessagingAPI>();
    std::shared_ptr<MessagingAPI> advancedAPI = std::make_shared<AdvancedMessagingAPI>();

    EmailNotification emailNotification(simpleAPI);
    SMSNotification smsNotification(advancedAPI);

    emailNotification.notify("john@example.com", "Your report is ready!");
    smsNotification.notify("+1234567890", "Your OTP is 123456.");

    return 0;
}