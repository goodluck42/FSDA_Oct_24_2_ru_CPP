#include <iostream>

// by pointer
// by reference
// by value


void print(int* arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << '\n';
}

int sum(short amogus, short bebra)
{
    return amogus + bebra;
}

int mult(short a, short b)
{
    return a * b;
}

// C style
typedef long long int64;
typedef int (*action)(short, short);

// C++ style 
// using int64 = long long;
//using action = int (*)(short, short);

bool less(int a, int b)
{
    return a < b;
}

bool greater(int a, int b)
{
    return a > b;
}

void bubble_sort(int* arr, int length, bool(*comparator)(int, int))
{
    // ???
}


int main(int argc, char* argv[])
{
    bubble_sort(nullptr, 0, greater);
    
    int (*func)(short, short) = mult;
    //action func = nullptr;
    // char op;
    //
    // std::cout << "Enter operation type:";
    // std::cin >> op;
    //
    // switch (op)
    // {
    // case '+':
    //     func = sum;
    //     break;
    // case '*':
    //     func = mult;
    //     break;
    // }
    //
    // short a, b;
    //
    // std::cout << "Enter two numbers:";
    // std::cin >> a >> b;
    //
    // if (func != nullptr)
    // {
    //     int result = func(a, b);
    //
    //     std::cout << result << '\n';
    // }
    

    return 0;
}
