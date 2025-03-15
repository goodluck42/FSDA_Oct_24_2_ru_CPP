#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

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
        std::cout << "copy constructor" << '\n';
        
        Battery = other.Battery;
        Color = new char[17];

        strcpy(Color, other.Color);
    }

    Phone(cstring color)
    {
        ++Count;
        Battery = 0;

        Color = new char[17];

        SetColor(color);
    }

    void Charge()
    {
        ++Battery;
    }

    int GetBattery()
    {
        return Battery;
    }

    static int GetCount()
    {
        return Count;
    }

    const char* GetColor()
    {
        return Color;
    }

private:
    void SetColor(cstring color)
    {
        if (color)
        {
            strcpy(Color, color);
        }
    }

    static int Count;
    int Battery; // obj1.Battery = 42; --> obj2.Battery = 42;
    char* Color; // obj1.Color = 0x99; --> obj2.Color = 0x99;
};

int Phone::Count = 0; // count = 0;

class Stock
{
public:
    void AddPhone(Phone phone)
    {
        // 
    }

    Phone GetPhoneByIndex(int index)
    {
        Phone phone;

        return phone;
    }
};

void count()
{
    static int number = 0;

    std::cout << number++ << '\n';
}


int main(int argc, char* argv[])
{
    //// Copy constructor

    Stock stock;

    Phone phone;

    stock.AddPhone(phone);
    // stock.GetPhoneByIndex(0);
    // stock.AddPhone(phone);
    // stock.AddPhone(phone);
    // stock.AddPhone(phone);
    // stock.AddPhone(phone);

    

    //// Statics
    // Phone myPhone;
    //
    // myPhone.Charge();
    // myPhone.Charge();
    // myPhone.Charge();
    //
    // std::cout << myPhone.GetBattery() << '\n';
    //
    // std::cout << "Count = " << Phone::GetCount() << '\n';
    //
    // Phone myPhone2;
    //
    // myPhone2.Charge();
    // myPhone2.Charge();
    //
    // std::cout << myPhone2.GetBattery() << '\n';
    //
    // std::cout << "Count = " << Phone::GetCount() << '\n';
    //
    // Phone myPhone3;
    // Phone myPhone4;
    // Phone myPhone5;
    //
    // std::cout << "Count = " << Phone::GetCount() << '\n';

    return 0;
}
