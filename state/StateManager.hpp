#ifndef STATEMANAGER_HPP
# define STATEMANAGER_HPP

#include "State.hpp"
#include <memory>
#include <iostream>


class StateManager
{
private:
    IState *_AlreadyHavingTheKnowledge;
    IState *_NotHavingTheKnowledgeButBeingInterested;
    IState *_NotHavingTheKnowledgeButNotBeingInterested;
    IState *_NotBeingInterested;

    std::shared_ptr<IState> _CurrentState;


public:
    StateManager(/* args */);
    void setState(std::shared_ptr<IState> state) {
        _CurrentState = std::move(state);
    }


    IState *get_AlreadyHavingTheKnowledge_State() const;
    IState *get_NotHavingTheKnowledgeButBeingInterested_State() const;
    IState *get_NotHavingTheKnowledgeButNotBeingInterested_State() const;
    IState *get_NotBeingInterested_State() const;
    IState *get_CurrentState() const;

    void Think()
    {
        _CurrentState->Think();
    };

    void AskQuestion()
    {
        _CurrentState->AskQuestion();
    };

    void ReadOrListen()
    {
        _CurrentState->ReadOrListen();
    };


    ~StateManager();
};

#endif