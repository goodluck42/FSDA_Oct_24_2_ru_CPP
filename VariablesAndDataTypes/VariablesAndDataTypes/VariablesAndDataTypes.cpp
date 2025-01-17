#include <iostream>

int main(int argc, char* argv[])
{
    // This code outputs Hello world!

    /* multiline
     * comment
     */

    // std::cout << "Hello World!";

    // // 1b
    // char symbol = 65; // -128 - 127
    // unsigned char u_symbol = '@'; // 0 - 255
    // bool boolean = false;
    //
    // // 2b
    // short short_value = 10000; // -32768 - 32767
    // unsigned short ushort_value = 10000; // 0 - 65535
    //
    // // 4b
    // int int_value = 10000; //  -2147483648 - 2147483647
    // unsigned int uint_value = 10000U; // 0 - 4294967295
    // long long_value = 1000L; //  -2147483648 - 2147483647
    // unsigned long ulong_value = 1000UL; // 0 - 4294967295

    // // 8b
    // long long ll_value = 10LL; // -9223372036854775808 - 9223372036854775807
    // unsigned long long ull_value = 1000ULL; // 0 - 18446744073709551615

    // // 4b
    //float f = 10.9f; // 34.56 // +0.3456 * 10^2

    // // 8b
    // double d = 3.14159;

    ///////////////////////////////
    // // implicit casts
    //
    // char a = 42ULL; // int -> char
    // bool b = '@'; // char -> bool
    // float f = 20.5; // double -> float
    // int i = 4200000000000LL; // long long -> int

    // // explicit casts
    // int symb = 64;
    //
    // char c = (char)symb;
    //
    // std::cout << c << '\n';
    //
    // float f = 10.11311f;
    //
    // std::cout << (int)f << '\n';
    
    ///////////////////////////////

    // Operators
    // +, -, *, /, % (arithmetic)
    // =, +=, -=, *=, /=, %= (assigment & shorthand)

    // int a = 5;
    // int b = 10;
    //
    // auto result = a % 2 == 0 ? "even" : "odd"; // ternary operator
    // std::cout << a - b << '\n'; // binary operator
    // std::cout << -b << '\n'; // unary operator

    // // increment and decrement
    //
    // a++; // a = a + 1
    // a--; // a = a - 1

    // std::cout << symbol;

    char o = 130;

    std::cout << (int)o << '\n';


    int a, b;

    std::cout << "Enter first number: ";
    std::cin >> a;

    std::cout << "Enter second number: ";
    std::cin >> b;

    std::cout << a + b;

    std::cout << "\\t";
    
    return 0;
}
