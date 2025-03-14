#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// public, protected*, private

class Point
{
    // getters & setters
public:
    Point() : Point(0, 0) // default constructor
    {
        std::cout << "default constructor" << '\n';
    }

    Point(int x, int y) // overloaded constructor
    {
        std::cout << "overloaded constructor" << '\n';
        X = x;
        Y = y;
    }

    int GetX()
    {
        return X;
    }

    void SetX(int value)
    {
        if (value >= 0)
        {
            X = value;
        }
    }

    int GetY()
    {
        return Y;
    }

    void SetY(int value)
    {
        if (value >= 0)
        {
            Y = value;
        }
    }

private:
    int X;
    int Y;
};

class Person
{
public:
    ~Person() // destructor
    {
        std::cout << "destructor" << '\n';
        delete[] Name;
    }

    Person()
    {
        std::cout << "constructor" << '\n';
        Age = 0;
        Name = new char[64]{};
    }

    int GetAge()
    {
        return Age;
    }

    void SetAge(int value)
    {
        if (value >= 0 && value <= 69)
        {
            Age = value;
        }
    }

    const char* GetName()
    {
        return Name;
    }

    void SetName(const char* value)
    {
        if (value == nullptr)
        {
            return;
        }

        strcpy(Name, value);
    }

private:
    char* Name;
    int Age;
};

int main(int argc, char* argv[])
{
    //// Heap objects
    // Person* person1 = new Person;
    //
    // delete person1;
    
    //// Destructor sample
    // std::cout << "scope begin" << '\n';
    // {
    //     Person person1;
    // }
    // std::cout << "scope end" << '\n';

    //// Person sample
    // Person person1;
    //
    // person1.SetName("Alex");
    // person1.SetAge(69);
    //
    // std::cout << person1.GetName() << '\n';
    // std::cout << person1.GetAge() << '\n';


    /////////////////// 
    // Point p; // default constructor called
    //
    // std::cout << p.GetX() << '\n';
    // std::cout << p.GetY() << '\n';

    // p.SetX(-10); // p.X = 10

    // std::cout << p.GetX(); // p.X

    // std::cout << p.GetX();


    // std::cin >> p.X;
    // std::cin >> p.Y;
    // std::cin >> p.Z;
    //
    // if (p.X < 0)
    // {
    //     std::cout << "Error" << '\n';
    // }
    //
    // if (p.Y < 0)
    // {
    //     std::cout << "Error" << '\n';
    // }
    //
    // if (p.Z < 0)
    // {
    //     std::cout << "Error" << '\n';
    // }
    //
    // p.X = 10;
    // p.Y = 10;
    // p.Z = 10;


    // std::cout << p.X << '\n';
    // std::cout << p.Y << '\n';
    // std::cout << p.Z << '\n';

    return 0;
}
