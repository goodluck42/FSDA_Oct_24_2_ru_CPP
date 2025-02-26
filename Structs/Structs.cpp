#include <iostream>

struct Gpu
{
    char model[32]; // field
    int vram;
    int cuda;
};

struct Motherboard
{
    char socket[32];
    double max_ram_frequency;
    Gpu gpu;
};
// struct A
// {
//     int a; // 4 of 4*
//     char d; // 1 of 4*
//     char d2; // 2 of 4
//     short d1; // 4 of 4
//     int e; // 4 of 4*
// };
// struct B
// {
//     int a; // 4 of 8*
//     short c; // 6 of 8
//     int b; // 4 of 8*
//     double d; // 8 of 8*
// };

//***//
struct B
{
    char a; // 1 of 8*
    int b; // 5 of 8
    short c; // 7 of 8
    double d; // 8 of 8*
};

// struct B
// {
//     char a;
//     double b;
//     short d;
//     int c;
//     char x;
// };

struct Inner
{
    double a;
    double b;
};

struct Outer
{
    int a; // 4 of 8*
    char b; // 5 of 8
    int c; // 4 of 8*

    Inner inner;
    // double a; // 8 of 8*
    // double b; // 8 of 8*
};



int main(int argc, char* argv[])
{
    std::cout << sizeof(B);
    
    {
        Motherboard motherboard;
        Gpu gpu1; // gpu1 = object/instance
    
        gpu1.vram = 6;
        gpu1.cuda = 3840;
    
        strcpy_s(gpu1.model, 32, "rtx3060");
    
        std::cout << gpu1.model << '\n';
        std::cout << gpu1.vram << '\n';
        std::cout << gpu1.cuda << '\n';
        
        motherboard.max_ram_frequency = 3666;
        motherboard.gpu = gpu1;
    }

    // {
    //     Gpu gpu2; // gpu1 = object/instance
    //
    //     gpu2.vram = 32;
    //     gpu2.cuda = 32768;
    //
    //     strcpy_s(gpu2.model, 32, "rtx6080ti");
    //
    //     std::cout << gpu2.model << '\n';
    //     std::cout << gpu2.vram << '\n';
    //     std::cout << gpu2.cuda << '\n';
    // }

    return 0;
}
