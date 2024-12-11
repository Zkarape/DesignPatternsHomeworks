#ifndef SATE_HPP
# define STATE_HPP

#include "StateManager.hpp"
#include <iostream>

class StateManager;

class IState
{
    public:
    virtual ~IState() = default;
    virtual void Think() = 0;
    virtual void AskQuestion() = 0;
    virtual void ReadOrListen() = 0;
};

class AlreadyHavingTheKnowledge : public IState
{
    private:
        StateManager *manager;
    public:
        AlreadyHavingTheKnowledge(StateManager *manage) : manager(manage) {}
        void Think()
        {
            std::cout << "I already know the topic" << std::endl;
            
        };
        void AskQuestion()
        {
            std::cout << "I already know the topic, so I don't have questions" << std::endl;
        }
        void ReadOrListen()
        {
            std::cout << "I have heard you, and I already know the topic" << std::endl;
            manager->setState(std::make_shared<NotBeingInterested>());
        }
};


class NotHavingTheKnowledgeButBeingInterested : public IState
{
    private:
        StateManager *manager;
    public:
        NotHavingTheKnowledgeButBeingInterested(StateManager *manage) : manager(manage) {}
        void Think()
        {
            std::cout << "I don't know the topic, but I am interested" << std::endl;
        };
        void AskQuestion()
        {
            std::cout << "I have a question" << std::endl;
        }
        void ReadOrListen()
        {
            std::cout << "I have heard you, and it is interesting" << std::endl;
            manager->setState(std::make_shared<AlreadyHavingTheKnowledge>());
        }
};


class NotHavingTheKnowledgeButNotBeingInterested : public IState
{
    private:
        StateManager *manager;
    public:
        NotHavingTheKnowledgeButNotBeingInterested(StateManager *manage) : manager(manage) {}
        void Think()
        {
            std::cout << "I don't know the topic, and I am not interested" << std::endl;
        };
        void AskQuestion()
        {
            std::cout << "I don't have questions" << std::endl;
        }
        void ReadOrListen()
        {
            std::cout << "I have heard you, and it is not interesting" << std::endl;
            manager->setState(std::make_shared<NotHavingTheKnowledgeButBeingInterested>());
        }

};

class NotBeingInterested : public IState
{
    private:
        StateManager *manager;
    public:
        NotBeingInterested(StateManager *manage) : manager(manage) {}
        void Think()
        {
            std::cout << "I am not interested" << std::endl;
        };
        void AskQuestion()
        {
            std::cout << "I don't have questions" << std::endl;
        }
        void ReadOrListen()
        {
            std::cout << "I don't want to listen to you" << std::endl;
            manager->setState(std::make_shared<NotHavingTheKnowledgeButNotBeingInterested>());
        }

};

#endif