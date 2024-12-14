#include <iostream>
#include <memory>
#include <stack>
#include <vector>
#include <string>

// Receiver: Canvas
class Canvas {
private:
    std::vector<std::string> shapes;

public:
    void addShape(const std::string& shape) {
        shapes.push_back(shape);
        std::cout << "Added shape: " << shape << "\n";
    }

    void removeShape() {
        if (!shapes.empty()) {
            std::cout << "Removed shape: " << shapes.back() << "\n";
            shapes.pop_back();
        } else {
            std::cout << "No shapes to remove.\n";
        }
    }

    void draw() const {
        if (shapes.empty()) {
            std::cout << "Canvas is empty.\n";
        } else {
            std::cout << "Drawing canvas: ";
            for (const auto& shape : shapes) {
                std::cout << shape << " ";
            }
            std::cout << "\n";
        }
    }

    const std::vector<std::string>& getShapes() const {
        return shapes;
    }
};


