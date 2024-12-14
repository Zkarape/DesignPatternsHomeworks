#include "invoker.hpp"

int main() {
    Canvas canvas;
    CommandInvoker invoker;

    invoker.executeCommand(std::make_unique<AddShapeCommand>(canvas, "Circle"));
    invoker.executeCommand(std::make_unique<AddShapeCommand>(canvas, "Square"));
    invoker.executeCommand(std::make_unique<AddShapeCommand>(canvas, "Triangle"));
    invoker.undo();
    invoker.redo();
    invoker.executeCommand(std::make_unique<DrawCommand>(canvas));
    invoker.executeCommand(std::make_unique<DrawCommand>(canvas));
    invoker.executeCommand(std::make_unique<DrawCommand>(canvas));

    return 0;
}