#include <iostream>

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
s
template <typename UType>
std::ostream& operator<<(std::ostream& Os, const Array<UType>& Array)
{
    Os << "{";
    for (int i = 0; i < Array.My_Length; i++)
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

int main(int argc, char* argv[])
{
    Array<int> arr;

    arr.Append(10);
    arr.Append(20);
    arr.Append(30);
    arr.Append(40);

    std::cout << arr;

    return 0;
}
