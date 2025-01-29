#include <iostream>


// prototypes
int sum(int a, int b); // function declaration
int sum(int a, int b, int c);
float sum(float a, float b);

void print_array(int array[], const int size)
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

// PrintArray // C#
// print_array // C++/Python
// printArray // Java/JavaScript

int main(int argc, char* argv[])
{
    // int x;
    // int y;
    //
    // std::cin >> x >> y;
    //
    // int res = sum(x, y);
    //
    // std::cout << res;


    const int size = 6;
    int arr[size]{10, 20, 30, 40, 50, 60};

    //std::cout << sizeof(arr);

    print_array(arr, size);

    int arr2[size]{11, 22, 33, 44, 55, 66};

    print_array(arr2, size);

    return 0;
}

int sum(int a, int b) // function definition
{
    // std::cout << "int sum(int a, int b);\n";

    int value = a + b;

    return value;
}

int sum(int a, int b, int c)
{
    //std::cout << "int sum(int a, int b, int c);\n";

    return a + b + c;
}


float sum(float a, float b)
{
    //std::cout << "float sum(float a, float b);\n";

    float value = a + b;

    return value;
}
