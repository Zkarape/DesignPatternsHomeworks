#include "command.hpp"

class CommandInvoker {
private:
    std::stack<std::unique_ptr<Command>> undoStack;
    std::stack<std::unique_ptr<Command>> redoStack;

public:
    void executeCommand(std::unique_ptr<Command> command) {
        command->execute();
        undoStack.push(std::move(command));
        while (!redoStack.empty()) redoStack.pop(); // Clear redo stack
    }

    void undo() {
        if (!undoStack.empty()) {
            auto command = std::move(undoStack.top());
            undoStack.pop();
            command->undo();
            redoStack.push(std::move(command));
        } else {
            std::cout << "Nothing to undo.\n";
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            auto command = std::move(redoStack.top());
            redoStack.pop();
            command->execute();
            undoStack.push(std::move(command));
        } else {
            std::cout << "Nothing to redo.\n";
        }
    }
};
