#ifndef SINGLETON_HPP
# define SINGLETON_HPP

# include <iostream>

class Singleton
{
    private:
        std::string _name;
    protected:
        Singleton();
    public:
        static Singleton &get_instance();

        void             set_name(std::string);
        std::string      get_name() const;

        Singleton(Singleton const&) = delete;             // Copy construct
        Singleton(Singleton&&) = delete;                  // Move construct
        Singleton& operator=(Singleton const&) = delete;  // Copy assign
        Singleton& operator=(Singleton &&) = delete;      // Move assign
};

#endif /*SINGLETON_HPP*/