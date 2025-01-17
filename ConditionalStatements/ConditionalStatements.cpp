// char, bool (1b)
// short, int* (2b)
// long, int*, float (4b)
// double, long long (8b)

#include <vector>
#include <cstdint>
#include <iostream>

enum Filemode
{
    Write = 1,
    Read,
    Append
};

int main(int argc, char* argv[])
{
    // int a = 0b00000110;

    // char a = 130; // -128 - 127
    //
    // std::cout << (int)a;

    // std::cout << a;

    // int_8
    // int_16
    // int_32
    // int_64
    // uint_32


    // long a = 1000L;

    // int a = 10;
    // float b = 3;
    //
    // std::cout << a / b;

    // long a = 10;
    // long long b = 10;

    // auto res = a + b;

    // int x = 42;
    // float y = (float)x;

    //////////////////////////////////
    // comparison operators: >, <, >=, <=, ==, !=
    //// #1
    // int a;
    // int b;
    //
    // std::cin >> a >> b;
    //
    // // bool result = a > b;
    //
    //
    // if (a > b)
    // {
    //     std::cout << "a is greater than b";
    // }
    // else if (a == b)
    // {
    //     std::cout << "a is equal to b";
    // }
    // else
    // {
    //     std::cout << "b is greater than a";
    // }

    //// 
    // int a = 41;

    // if (a > 0)
    // {
    //     std::cout << "a is positive" << '\n';
    //
    //     if (a % 2 == 0)
    //     {
    //         std::cout << "a is even" << '\n';
    //     }
    // }

    // and, or, not
    // && , ||, !

    // 1 || 0 => 1
    // 0 || 0 => 0
    // 0 || 1 => 1
    // 1 && 0 => 0
    // 0 && 0 => 0
    // 1 && 1 => 1
    // 1 && 0 || 1 => 1

    // if (a > 0 && a % 2 == 0)
    // {
    //     std::cout << "a is even" << '\n';
    //     std::cout << "a is positive" << '\n';
    // }

    // int filemode;
    //
    // std::cin >> filemode;
    //
    // Filemode mode = (Filemode)filemode;
    //
    // switch (mode)
    // {
    // case Write:
    //     std::cout << "Writing to a file" << '\n';
    //     break;
    // case Read:
    //     std::cout << "Reading from a file" << '\n';
    //     break;
    // case Append:
    //     std::cout << "Appending to a file" << '\n';
    //     break;
    // default:
    //     std::cout << "Invalid enum" << '\n';
    // }

    ////////////
    // char c;
    //
    // std::cin >> c;
    //
    // switch (c)
    // {
    // case 'w':
    // case 'W':
    //     std::cout << "forward\n";
    //     break;
    // case 's':
    // case 'S':
    //     std::cout << "backward\n";
    //     break;
    // }


    char c;

    std::cin >> c;
    
    switch (c)
    {
    case 64:
        break;
    case '@':
        break;
    }

    
    system("pause");

    return 0;
}
