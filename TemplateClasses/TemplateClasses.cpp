#include <iostream>
#include <unordered_map>

template <typename TType> // TType = std::string
class Array
{
    template <typename UType>
    friend std::ostream& operator<<(std::ostream& Os, const Array<UType>& Array);

public:
    ~Array()
    {
        delete[] My_Data;
    }

    Array()
    {
        My_Data = new TType[My_DefaultCapacity];
        My_Capacity = My_DefaultCapacity;
        My_Length = 0;
    }

    void Append(const TType& Value)
    {
        if (My_Length == My_Capacity)
        {
            return;
        }

        My_Data[My_Length++] = Value;
    }

    TType& operator[](size_t Index)
    {
        return My_Data[Index];
    }

    const TType& operator[](size_t Index) const
    {
        return My_Data[Index];
    }

    // void Append(std::string&& value)
    // {
    //     
    // }

private:
    TType* My_Data;
    size_t My_Length;
    size_t My_Capacity;
    static constexpr size_t My_DefaultCapacity = 15;
};

template <typename UType>
std::ostream& operator<<(std::ostream& Os, const Array<UType>& Array)
{
    Os << "{";
    for (size_t i = 0; i < Array.My_Length; i++)
    {
        Os << Array[i];

        if (i != Array.My_Length - 1)
        {
            Os << ", ";
        }
    }

    Os << "}";

    return Os;
}

class Greater
{
public:
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};

class Less
{
public:
    bool operator()(int a, int b) const
    {
        return a < b;
    }
};

template <typename XType>
class Integer
{
public:
    Integer(int A, int B) : My_a(A), My_b(B)
    {
    }

    bool Compare()
    {
        return My_Comparer(My_a, My_b);
    }

private:
    XType My_Comparer;
    int My_a;
    int My_b;
};

int main(int argc, char* argv[])
{
    Integer<Greater> Value{20, 30};

    std::cout << Value.Compare() << '\n';

    Less MyLess;

    std::cout << MyLess(10, 20);
    
    // Array<int> arr;
    //
    // arr.Append(10);
    // arr.Append(20);
    // arr.Append(30);
    // arr.Append(40);
    //
    // std::cout << arr;

    return 0;
}
