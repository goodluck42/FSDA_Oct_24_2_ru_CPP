#include <iostream>
#include <stdint.h>
#include <Windows.h>

// C style
// typedef long long int64;

// C++ style
using int64 = long long;

void change(int* value_ptr)
{
    *value_ptr = 25;
}

int main(int argc, char* argv[])
{
    //  * (x32) - 4bytes
    //  * (x64) - 8bytes
    //
    // // allocate & delete
    //  {
    //      int* arr = new int[100];
    //
    //      delete[] arr; // vector delete
    //
    //      int* value = new int;
    //
    //      delete value; // scalar delete
    //  }
    //
    // // dereference
    //  {
    //      int* value = new int;
    //
    //      *value = 20; // dereference
    //
    //      *value *= *value * 2;
    //
    //      std::cout << *value << '\n';
    //
    //      delete value;
    //  }

    //// address of
    // {
    //     int value = 42;
    //     int* addr = &value;
    //     
    //     change(addr);
    //
    //     std::cout << value << '\n';
    // }


    {
        int size = 4;
        int* arr = new int[size] {10, 20, 30, 40};
        
        std::cout << 1[arr] << '\n';
        std::cout << *(1 + arr) << '\n';
        
        
    }
    

    // system("pause");

    return 0;
}
