#include <iostream>

int main(int argc, char* argv[])
{
    // 00110000 00111001
    short Value1 = 12345;
    // 00100111 00010000
    short Value2 = 10000;
    
    //// | - bitwise OR
    // {
    //     // 00110000 00111001
    //     // |
    //     // 00100111 00010000
    //     // 00110111 00111001
    //     short Result = Value1 | Value2;
    //
    //     std::cout << Result << '\n';
    // }
    
    //// & - bitwise AND
    // {
    //     // 00110000 00111001
    //     // &
    //     // 00100111 00010000
    //     // 00100000 00010000
    //     short Result = Value1 & Value2;
    //
    //     std::cout << Result << '\n';
    // }

    //// ~ - bitwise INVERSION
    // {
    //     // 00110000 00111001
    //
    //     // -32768 + 20422
    //     // 11001111 11000110
    //     
    //     short Result = ~Value1; 
    //     
    //     std::cout << Result << '\n';
    // }

    //// << - left shift
    // {
    //     // 00110000 00111001
    //     // -32768 + 456 = -32312
    //     // 10000001 11001000
    //     short Result = Value1 << 3;
    //
    //     std::cout << Result << '\n';
    // }

    //// >> right shift
    // {
    //     // 00110000 00111001
    //     // 00000110 00000111
    //     short Result = Value1 >> 3;
    //
    //     std::cout << Result << '\n';
    // }

    //// ^ - XOR
    // {
    //     // 00110000 00111001 (Value1)
    //     // ^
    //     // 00100111 00010000 (Value2)
    //     
    //     // 00010111 00101001 (Result)
    //
    //     // --
    //     // 00010111 00101001 (Result)
    //     // ^
    //     // 00100111 00010000 (Value)
    //     // 00110000 00111001 (Value1)
    //     
    //     short Result = Value1 ^ Value2;
    //
    //     std::cout << Result << '\n';
    //
    //     short BackResult = Result ^ Value2;
    //
    //     std::cout << BackResult << '\n';
    // }


    // One variable two values
    int Container{};
    {
        short Value1 = 10000;
        short Value2 = 25555;
        
        // 00000000 00000000 00100111 00010000
        Container |= Value1;

        // 00100111 00010000 00000000 00000000 
        Container <<= 16;

        // 00100111 00010000 01100011 11010011
        Container |= Value2;

        // std::cout << Container;
    }

    {
        // 00000000 00000000 00100111 00010000

        std::cout << (short)Container << '\n';
        std::cout << (short)(Container >> 16) << '\n';
    }
    
    return 0;
}
