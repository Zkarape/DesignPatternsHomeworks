#include <iostream>
#include "StateManager.hpp"
#include "State.hpp"

int main() {
    // Create the state manager
    StateManager manager;

    // Set the initial state to NotBeingInterested
    manager.setState(std::make_shared<NotBeingInterested>(&manager));

    std::cout << "--- Starting State Transition Process ---" << std::endl;
    while (manager.get_CurrentState() != nullptr) {
        manager.get_CurrentState()->Think();
        manager.get_CurrentState()->AskQuestion();
        manager.get_CurrentState()->ReadOrListen();
    }

    std::cout << "--- State Transition Process Complete ---" << std::endl;
    return 0;
}
