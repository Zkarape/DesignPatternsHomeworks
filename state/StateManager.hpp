#ifndef STATEMANAGER_HPP
# define STATEMANAGER_HPP

#include "State.hpp"

class StateManager
{
private:
    IState *_AlreadyHavingTheKnowledge;
    IState *_NotHavingTheKnowledgeButBeingInterested;
    IState *_NotHavingTheKnowledgeButNotBeingInterested;
    IState *_NotBeingInterested;

    IState *_CurrentState;

public:
    StateManager(/* args */);
    void set_state(IState *state_to_set);
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