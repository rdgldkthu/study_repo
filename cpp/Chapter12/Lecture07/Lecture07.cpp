/*
    순수 Pure 가상 함수, 추상 Abstract 기본 클래스, 인터페이스 Interface 클래스
*/
#include <iostream>
#include <string>

using namespace std;

class Animal
{
protected:
    string m_name;

public:
    Animal(std::string name) : m_name(name) {}

public:
    string getName() { return m_name; }
    virtual void speak() const = 0; // pure virtual function
};

// the body of pure virtual function // useless by itself
//void Animal::speak() const
//{
//    cout << m_name << " ???" << endl;
//}

class Cat : public Animal
{
public:
    Cat(std::string name) : Animal(name) {}

    void speak() const 
    {
        cout << m_name << " Meow" << endl;
    }
};

class Dog : public Animal
{
public:
    Dog(std::string name) : Animal(name) {}

    void speak() const
    {
        cout << m_name << " Woof" << endl;
    }
};

class Cow : public Animal
{
public:
    Cow(std::string name) : Animal(name) {}
};

// Interface class
class IErrorLog
{
public:
    virtual bool reportError(const char* errorMessage) = 0;
    virtual ~IErrorLog() {}
};

class FileErrorLog : public IErrorLog
{
public:
    bool reportError(const char* errorMessage) override
    {
        cout << "Writing error to a file" << endl;
        return true;
    }
};

class ConsoleErrorLog : public IErrorLog
{
public:
    bool reportError(const char* errorMessage) override
    {
        cout << "Printing error to a console" << endl;
        return true;
    }
};

void doSomething(IErrorLog& log) 
{
    log.reportError("Runtime error!!");
}

int main()
{
    // cannot be declared
    //Animal ani("Hi");
    //Cow cow("moo");

    FileErrorLog file_log;
    ConsoleErrorLog console_log;

    doSomething(file_log);
    doSomething(console_log);

    return 0;
}