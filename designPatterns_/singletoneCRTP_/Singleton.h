#ifndef SINGLETON_H
#define SINGLETON_H

template<typename HeirT>
class Singleton
{
public:
    static HeirT & instance()
    {
        static HeirT instance;
        return instance;
    }

    Singleton(const Singleton & notCopyable) = delete;
    Singleton & operator=(const Singleton & notAssignable) = delete;
    Singleton(Singleton && notMoveable) = delete;
    Singleton & operator=(Singleton && notMoveAssignable) = delete;
    
protected:
    Singleton() = default;
    ~Singleton() = default;
};

#endif // SINGLETON_H