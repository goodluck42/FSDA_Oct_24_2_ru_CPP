#include <iostream>
#include <Windows.h>

int* allocate(int capacity)
{
    int* memory = new int[capacity]{};

    return memory;
}

void destroy(int* memory)
{
    delete[] memory;
}

int* append(int* array, int* capacity, int* length, int value)
{
    if (*length == *capacity)
    {
        *capacity *= 2;

        int* new_array = allocate(*capacity);

        for (int i = 0; i < *length; i++)
        {
            new_array[i] = array[i];
        }

        destroy(array);

        array = new_array;
    }

    array[*length] = value;

    ++(*length);

    return array;
}

void print(int* array, int length)
{
    std::cout << "{ ";

    for (int i = 0; i < length; i++)
    {
        std::cout << *(array + i);

        if (i != length - 1)
        {
            std::cout << ", ";
        }
    }

    std::cout << " }";
}

void baz(int* ptr)
{
    std::cout << &ptr << '\n';
    ptr = new int{4};
}

int main(int argc, char* argv[])
{
    int* my_ptr = new int{7};

    std::cout << &my_ptr << '\n';

    baz(my_ptr);

    // std::cout << *my_ptr;

    // int arr[3]{10, 20, 30};
    //
    // std::cout << *arr << '\n'; // arr[0]
    // std::cout << *(arr + 1) << '\n'; // arr[1]
    // std::cout << *(arr + 2) << '\n'; // arr[2]

    // {
    //     int* ptr1 = new int{90};
    //     int* ptr2 = ptr1;
    //
    //     std::cout << *ptr1 << '\n';
    //     std::cout << *ptr2 << '\n';
    //     
    // }
    int length = 0;
    int capacity = 5;
    
    int* arr = allocate(capacity);

    for (int i = 0; i < 1000; i++)
    {
        arr = append(arr, &capacity, &length, rand());

        std::cout << "length = " << length << '\n';
        std::cout << "capacity = " << capacity << '\n';

        Sleep(75);
    }
    
    print(arr, length);
    
    destroy(arr);


    printf("\n");
    system("pause");

    return 0;
}
