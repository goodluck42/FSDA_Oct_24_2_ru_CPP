#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

class Object
{
public:
    Object() = default;

    Object(const Object& Other)
    {
        std::cout << "Object(const Object& Other)" << '\n';
    }

    int Address;
};

void PassByValue(Object object)
{
}

void PassByPointer(Object* object)
{
}

void PassByReference(Object& object)
{
}

Object GetObject()
{
    Object MyObject{};

    return MyObject;
}

///////////////

typedef const char* cstring;

class Phone
{
public:
    ~Phone()
    {
        --Count;

        delete[] Color;
    }

    Phone() : Phone("Black")
    {
    }

    Phone(const Phone& other)
    {
        std::cout << "Phone::Phone(const Phone& other)" << '\n';

        Battery = other.Battery;
        Color = new char[17];

        strcpy(Color, other.Color);
    }

    Phone(Phone&& Other) noexcept
    {
        std::cout << "Phone::Phone(Phone&& Other)" << '\n';
        
        this->Battery = Other.Battery;
        Other.Battery = 0;
        this->Color = Other.Color;
        Other.Color = nullptr;
    }
        
    Phone(cstring color)
    {
        std::cout << "Phone::Phone(cstring color)" << '\n';

        ++Count;
        Battery = 50;

        Color = new char[17];

        SetColor(color);
    }

    void Charge()
    {
        ++Battery;
    }

    int GetBattery() const
    {
        return Battery;
    }

    static int GetCount()
    {
        return Count;
    }

    const char* GetColor() const
    {
        return Color;
    }

    void SetColor(cstring color)
    {
        if (color)
        {
            strcpy(Color, color);
        }
    }

private:
    static int Count;
    int Battery;
    char* Color;
};

int Phone::Count = 0;


void PassByRef(int& value)
{
}

void PassByConstRef(const int& value)
{
}

void MovePhone(Phone RValueRef)
{
    
}

int main(int argc, char* argv[])
{
    //// Copy constructor call
    // Object MyObject;
    //
    // PassByValue(MyObject);
    //
    // Object NewObject = GetObject();
    //
    // Object Copy{MyObject};

    //// () vs {}
    // {
    //     Object MyObject{};
    //
    //     MyObject.Address = 10;
    //
    //     std::cout << MyObject.Address << '\n';
    // }


    //// Rvalue references & universal references
    // {
    //     int value = 42;
    //
    //     const int& LValueRef = value;
    //     int&& RValueRef = 13;
    //
    //     Phone&& RValueRefObj = Phone{};
    //
    //     auto&& UniversalRef = LValueRef;
    //
    //     // PassByRef(value);
    //     // PassByConstRef(value);
    // }


    {
        Phone Phone1{"Azure"};

        Phone Result = std::move(Phone1);

        // std::cout << "Old = " << Phone1.GetBattery() << '\n';
        // std::cout << "Old = " << Phone1.GetColor() << '\n';
        
        std::cout << "Moved = " << Result.GetBattery() << '\n';
        std::cout << "Moved = " << Result.GetColor() << '\n';

        MovePhone(Result);
        MovePhone(std::move(Result));
    }


    return 0;
}
