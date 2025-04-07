#include <iostream>
#include <random>


class Array
{
    friend std::ostream& operator<<(std::ostream& Os, const Array& Arr);

public:
    ~Array()
    {
        delete[] My_Data;
    }

    Array()
    {
        Length = 0;
        Capacity = My_DefaultCapacity;
        My_Data = new int[My_DefaultCapacity];
    }

    void Append(int Value)
    {
        if (Length == Capacity)
        {
            return;
        }

        My_Data[Length++] = Value;
    }

    int GetValueByIndex(int Index) const
    {
        return My_Data[Index];
    }

    int GetLength() const
    {
        return Length;
    }

    int& operator[](int Index)
    {
        return My_Data[Index];
    }

    const int& operator[](int Index) const
    {
        return My_Data[Index];
    }

private:
    int* My_Data;
    int Length;
    int Capacity;
    static constexpr int My_DefaultCapacity = 10;
};

class RandomEngine
{
public:
    RandomEngine()
    {
        srand((int)time(0));
    }

    int Generate(int Min, int Max) const
    {
        int RandomValue = rand() % (Max - Min) + Min;

        return RandomValue;
    }
};

class Range
{
    // friend class RandomEngine;
public:
    Range(int Min, int Max) : Min(Min), Max(Max)
    {
    }

    int operator()(const RandomEngine& Engine)
    {
        return Engine.Generate(Min, Max);
    }

private:
    int Min;
    int Max;
};

std::ostream& operator<<(std::ostream& Os, const Array& Arr)
{
    Os << "{";
    for (int i = 0; i < Arr.Length; i++)
    {
        Os << Arr[i];
        if (i != Arr.Length - 1)
        {
            Os << ", ";
        }
    }

    Os << "}";

    return Os;
}

int main(int argc, char* argv[])
{
    //// Indexer
    {
        Array Arr{}; // Arr = []

        Arr.Append(10); // Arr.append(10)
        Arr.Append(20); // ...
        Arr.Append(30); // ...
        Arr.Append(40); // ...

        Arr[0] = 90;

        std::cout << Arr << '\n'; // print(Arr)
    }


    //// RNG
    // {
    //     std::default_random_engine Engine{};
    //
    //     std::uniform_int_distribution<int> Range(10, 99);
    //
    //     int result = Range(Engine);
    //
    //     std::cout << result << '\n';
    //
    // }
    //
    // //// Our RNG
    // {
    //     RandomEngine Engine{};
    //     Range Range{10, 99};
    //
    //     int result = Range(Engine);
    //
    //     std::cout << result << '\n';
    // }


    return 0;
}
