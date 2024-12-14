#include "StateManager.hpp"

StateManager::StateManager()
{
    _AlreadyHavingTheKnowledge = new AlreadyHavingTheKnowledge(this);
    _NotBeingInterested = new NotBeingInterested(this);
    _NotHavingTheKnowledgeButBeingInterested = new NotHavingTheKnowledgeButBeingInterested(this);
    _NotHavingTheKnowledgeButNotBeingInterested = new NotHavingTheKnowledgeButNotBeingInterested(this);
    _CurrentState = _AlreadyHavingTheKnowledge;
}

IState *StateManager::get_AlreadyHavingTheKnowledge_State() const
{
    return _AlreadyHavingTheKnowledge;
}

std::shared_ptr<IState> StateManager::get_CurrentState() const
{
    return _CurrentState;
}

IState *StateManager::get_NotBeingInterested_State() const
{
    return _NotBeingInterested;
}

IState *StateManager::get_NotHavingTheKnowledgeButBeingInterested_State() const
{
    return _NotHavingTheKnowledgeButBeingInterested;
}

IState *StateManager::get_NotHavingTheKnowledgeButNotBeingInterested_State() const
{
    return _NotHavingTheKnowledgeButNotBeingInterested;
}


StateManager::~StateManager()
{
    delete _NotBeingInterested;
    delete _AlreadyHavingTheKnowledge;
    delete _NotHavingTheKnowledgeButBeingInterested;
    delete _NotHavingTheKnowledgeButNotBeingInterested;
    delete _CurrentState;
}