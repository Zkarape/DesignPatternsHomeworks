#ifndef SINGLETON_HPP
# define SINGLETON_HPP

class Singleton
{
    private:
        static Singleton   *_instance;
    public:
        static Singleton *get_instance();

        Singleton(Singleton const&) = delete;             // Copy construct
        Singleton(Singleton&&) = delete;                  // Move construct
        Singleton& operator=(Singleton const&) = delete;  // Copy assign
        Singleton& operator=(Singleton &&) = delete;      // Move assign

    protected:
        Singleton();
};

#endif /*SINGLETON_HPP*/