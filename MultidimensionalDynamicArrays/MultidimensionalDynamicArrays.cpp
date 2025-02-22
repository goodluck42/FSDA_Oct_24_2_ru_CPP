#include <iostream>
#include <Windows.h>

char** allocate(int capacity)
{
    return new char*[capacity]; // char**
}

void destroy(char* string)
{
    delete[] string;
}

void destroy(char** data);

void destroy(char** data, int length)
{
    for (int i = 0; i < length; i++)
    {
        destroy(data[i]);
    }

    destroy(data);
}

void destroy(char** data) // <-------------
{
    delete[] data;
}

// char** = [char*, char*, char*]
void append_string(char**& data, int& capacity, int& length, char* string)
{
    if (length == capacity)
    {
        capacity = (int)((float)capacity * 1.5f);

        char** newData = allocate(capacity);

        for (int i = 0; i < length; i++)
        {
            newData[i] = data[i];
        }

        destroy(data);

        data = newData;
    }

    *(data + length) = string; // data[length] = string;
    ++length;
}

void print(char** data, int length)
{
    for (int i = 0; i < length; ++i)
    {
        std::cout << data[i] << " ";
    }

    std::cout << '\n';
}

int main(int argc, char* argv[])
{
    // void* arr = ::operator new(1'000'000);
    //
    //

    // World
    // Heaven
    // Hell
    // Mouse


    // Pointers
    // {
    //     int value = 9;
    //     int* data = &value; // &value -> int*
    //
    //     *data = 41;
    //
    //     int result = *data;
    //
    //     std::cout << result;
    // }


    // Pointer to pointer
    // {
    //     int* data = new int{9};
    //     int** addr = &data;
    //
    //     std::cout << **addr << '\n'; // 9
    //     std::cout << *addr << '\n'; // address of data
    //     std::cout << &addr << '\n'; // address of addr -> int***
    //     std::cout << addr << '\n'; // address of addr variable
    // }


    // while (true)
    // {
    //     char* str1 = new char[32]{"Heaven"};
    //     char* str2 = new char[32]{"Hell"};
    //     char* str3 = new char[32]{"World"};
    //     char* str4 = new char[32]{"Mouse"};
    //
    //     int length = {};
    //     int capacity = 3;
    //     char** str_array = allocate(capacity);
    //
    //     append_string(str_array, capacity, length, str1);
    //     append_string(str_array, capacity, length, str2);
    //     append_string(str_array, capacity, length, str3);
    //     append_string(str_array, capacity, length, str4);
    //
    //     // print(str_array, length);
    //
    //     destroy(str_array, length);
    //     //Sleep(50);
    //
    // }

    // 3x3
    // {
    //     int rows = 3;
    //     int cols = 3;
    //
    //     // *
    //     // *
    //     // *
    //     int** md_arr = new int*[rows]{}; // { nullptr, nullptr, nullptr }
    //
    //     md_arr[0] = new int[cols]{10, 20, 30}; // 0
    //     md_arr[1] = new int[cols]{40, 50, 60}; // 1
    //     md_arr[2] = new int[cols]{70, 80, 90}; // 2
    //
    //     std::cout << md_arr[1][2] << " " << '\n';
    //     std::cout << *(*(md_arr + 1) + 2) << " " << '\n';
    //
    //     delete[] md_arr[0];
    //     delete[] md_arr[1];
    //     delete[] md_arr[2];
    //
    //     delete[] md_arr;
    // }

    // Multidimensional dynamic arrays
    {
        int rows = 3;
        int cols = 3;
        int** md_arr = new int*[rows];

        for (int i = 0; i < rows; i++)
        {
            md_arr[i] = new int[cols]{};
        }

        // fill with random values
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                md_arr[i][j] = rand() % 100;
            }
        }

        // print values
        for (int i = 0; i < rows; i++)
        {
            std::cout << "{ ";
            for (int j = 0; j < cols; j++)
            {
                std::cout << md_arr[i][j] << " ";
            }

            std::cout << " }\n";
        }


        for (int i = 0; i < rows; i++)
        {
            delete[] md_arr[i]; // delete rows
        }

        delete[] md_arr; // delete whole array of pointers
    }

    return 0;
}
