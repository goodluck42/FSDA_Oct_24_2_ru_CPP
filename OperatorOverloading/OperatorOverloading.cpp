#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Number
{
public:
    Number() : My_Value{} // My_Value = 0;
    {
    }

    Number(int RawValue) : My_Value{RawValue} // My_Value = RawValue;
    {
    }

    // Debug purpose only!
    void Print()
    {
        std::cout << My_Value << '\n';
    }

    // lhs = this | rhs = Other
    bool operator>(const Number& Rhs) const
    {
        // this = Num2; (left)
        // Rhs = Num1; (right)
        return this->My_Value > Rhs.My_Value;
    }

    bool operator<(const Number& Rhs) const
    {
        return !operator>(Rhs);
    }

    Number operator+(const Number& Rhs)
    {
        Number Result;

        Result.My_Value = My_Value + Rhs.My_Value;

        return Result;
    }

    Number operator-(const Number& Rhs) const // binary
    {
        Number Result;

        Result.My_Value = My_Value - Rhs.My_Value;

        return Result;
    }

    Number operator-() const // unary
    {
        return Number{-My_Value};
    }

    // prefix form
    Number& operator++()
    {
        My_Value += 1;

        return *this;
    }

    // postfix form
    Number operator++(int)
    {
        Number Copy{*this};

        My_Value += 1;

        return Copy;
    }

private:
    int My_Value;
};

class Object
{
};

class String
{
public:
    ~String()
    {
        delete[] My_Data;
    }

    String()
    {
        My_Data = new char[64]{};
    }

    String(const char* RawString) : String()
    {
        strcpy(My_Data, RawString);
    }

    String(const String& Other)
    {
        My_Data = new char[64]{};

        for (int i = 0; i < 64; i++)
        {
            My_Data[i] = Other.My_Data[i];
        }
    }

    String(String&& Other) noexcept
    {
        My_Data = Other.My_Data;

        Other.My_Data = nullptr;
    }

    // copy assignment
    String& operator=(const String& Other)
    {
        delete[] My_Data;

        My_Data = new char[64]{};

        for (int i = 0; i < 64; i++)
        {
            My_Data[i] = Other.My_Data[i];
        }

        return *this;
    }

    String& operator=(String&& Other)
    {
        delete[] My_Data;

        My_Data = Other.My_Data;

        Other.My_Data = nullptr;

        return *this;
    }

    const char* GetCString() const
    {
        return this->My_Data;
    }

private:
    char* My_Data;
};

int main(int argc, char* argv[])
{
    //// Ass. Operators

    String S1{"Ravan"};
    String S2{};

    S2 = S1; // copy assignment
    S2 = std::move(S1); // move assignment

    std::cout << S1.GetCString() << '\n';
    std::cout << S2.GetCString() << '\n';


    //// Operators

    // Number Num1{42};
    // Number Num2{9};
    //
    // ++Num2;
    //
    // Num1++;
    //
    // Num1.Print();
    // Num2.Print();

    //// 
    // if (Num1.operator>(Num2))
    // {
    //     std::cout << "Num1 is greater than Num2" << '\n';
    // }
    //
    // if (Num2 > Num1)
    // {
    //     std::cout << "Num1 is greater than Num2" << '\n';
    // }


    int a = 42;
    int b = 13;

    b = a;
    b = 9;


    return 0;
}

class Chair
{
public:
    ~Chair()
    {
        delete[] My_data;
    }

    Chair()
    {
        Capacity = 9;
        Length = 0;
        My_data = new int[Capacity];
    }

    Chair(const Chair& Other)
    {
        My_data = new int[Other.Capacity];

        for (int i = 0; i < Other.Capacity; i++)
        {
            My_data[i] = Other.My_data[i];
        }

        Length = Other.Length;
        Capacity = Other.Capacity;
    }

    Chair(Chair&& Other)
    {
        this->Length = Other.Length;
        Other.Length = {};

        this->Capacity = Other.Capacity;
        Other.Capacity = {};

        this->My_data = Other.My_data;
        Other.My_data = {};
    }

    Chair& operator=(const Chair& Other)
    {
        this->~Chair();

        My_data = new int[Other.Capacity];

        for (int i = 0; i < Other.Capacity; i++)
        {
            My_data[i] = Other.My_data[i];
        }

        Length = Other.Length;
        Capacity = Other.Capacity;

        return *this;
    }

    Chair& operator=(Chair&& Other)
    {
        this->~Chair();

        this->Length = Other.Length;
        Other.Length = {};

        this->Capacity = Other.Capacity;
        Other.Capacity = {};

        this->My_data = Other.My_data;
        Other.My_data = {};

        return *this;
    }

private:
    int* My_data;
    int Length;
    int Capacity;
};
