#include <iostream>

template <typename Type>
void print_array(Type array[], const int size)
{
    std::cout << "{ ";

    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i];

        if (i != size - 1)
        {
            std::cout << ", ";
        }
    }

    std::cout << " }\n";
}

template <typename T>
T sum(T a, T b)
{
    T result = a + b;

    return result;
}

template <typename T1, typename T2>
auto sum(T1 a, T2 b)
{
    return a + b;
}

int main(int argc, char* argv[])
{
    // {
    //     const int length = 3;
    //     float arr1[length] = {10.1f, 20.2f, 30.1f};
    //     int arr2[length] = {12, 25, 35};
    //     double arr3[length] = {11.5, 20.6, 30.7};
    //
    //     print_array<float>(arr1, length); // print_array__float
    //     print_array<int>(arr2, length); // print_array__int
    //     print_array(arr3, length);
    // }
    // CTRL + ALT + L 
    {
        // float result = sum<float>(10.2f, 20.1f);

        auto result = sum<int, float>(10, 20.5f);
        std::cout << result;
    }

    return 0;
}
