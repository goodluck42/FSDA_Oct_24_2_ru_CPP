#include <iostream>
#include <chrono>
#include <thread>


// addr of param = 0x56
void func(int param) // by value
{
    param = param * 2;
}

// ptr = 0x70
void func(int* ptr) // by pointer
{
    *ptr *= 2;
    // *ptr = *ptr * 2;
}

///////////

void do_smth(int& ref)
{
    ref += 100;
}

// ptr = 0x2f - (9); &ptr = 0x9cc;
void change_ptr(int*& ptr)
{
    delete ptr;

    ptr = new int{4}; // ptr = 0xfffc1 - (4); 
}

template <typename T>
T* allocate(int capacity)
{
    return new T[capacity];
}

template <typename T>
void destroy(T* data)
{
    delete[] data;
}

template <typename T> // T = double
void append(T*& data, int& length, int& capacity, T value)
{
    if (length == capacity)
    {
        capacity = (int)((float)capacity * 1.5f);

        T* newData = allocate<T>(capacity);

        for (int i = 0; i < length; i++)
        {
            newData[i] = data[i];
        }

        destroy<T>(data);

        data = newData;
    }

    data[length] = value;
    ++length;
}

template <typename T>
void print(T* data, int length)
{
    for (int i = 0; i < length; ++i)
    {
        std::cout << data[i] << " ";
    }

    std::cout << '\n';
}


int main(int argc, char* argv[])
{
    //// Dynamic arrays
    {
        int length{};
        int capacity{3};

        int* arr = allocate<int>(capacity);

        for (int i = 0; i < 500; ++i)
        {
            append(arr, length, capacity, rand());

            std::cout << "capacity: " << capacity << '\n';
            std::cout << "length: " << length << '\n';


            std::this_thread::sleep_for(std::chrono::milliseconds{100});
        }

        print(arr, length);

        destroy<int>(arr);
    }

    //// Reference to pointers
    // {
    //     int* ptr = new int{9};
    //
    //     change_ptr(ptr); // ptr = 0x2f - (9); &ptr = 0x9cc;
    //
    //     std::cout << *ptr << '\n';
    // }


    // // References
    //  {
    //      // int* ptr {}; // ptr = nullptr;
    //      //
    //      // *ptr = 10;
    //      
    //      int a = 10;
    //      int b = 20;
    //      int& ref = a; // constant pointer
    //
    //      ref = b; // a = b 
    //      ref = 30; // a = 30
    //
    //      std::cout << a << '\n'; // 30
    //      std::cout << b << '\n'; // 20
    //      
    //  }

    //// References 2
    // {
    //     int a = 10;
    //     
    //     do_smth(a);
    //     
    //     std::cout << a;
    // }

    //// rvalue & lvalue

    // {
    //     int a = 10;
    //
    //     std::cout << a << '\n'; // lvalue
    //     std::cout << a + 10 << '\n'; // rvalue
    // }

    //// Pointers
    // {
    //     int value = 42;
    //     int value2 = 9;
    //     
    //     const int* ptr = &value;
    //
    //     ptr = &value2;
    //     *ptr = 90;
    // }

    ////////////////////

    //// Pointer to constant
    // {
    //     int value = 42;
    //     int value2 = 9;
    //     
    //     const int* ptr = &value;
    //
    //     ptr = &value2;
    //     *ptr = 90;
    // }

    //// Constant pointer
    // {
    //     int value = 42;
    //     int value2 = 9;
    //     
    //     int* const ptr = &value;
    //
    //     ptr = &value2; // FAIL
    //     *ptr = 90;
    // }

    //// Constant pointer to constant
    // {
    //     int value = 42;
    //     int value2 = 9;
    //     
    //     const int* const ptr = &value;
    //
    //     ptr = &value2;
    //     *ptr = 90;
    // }

    /////////
    // int value = 9; // addr of value = 0x14
    // int* value_ptr = &value;
    //
    // func(value_ptr); // addr value = 0x70
    //
    // std::cout << value << '\n';

    ////////////////

    // short value = 16;
    // short it = value;
    //
    // std::cout << it << '\n';
    // std::cout << value << '\n';

    // short* value = new short[3]{19, 16, 13};
    // short* it = value;
    //
    // std::cout << *it << '\n';
    // ++it;
    // std::cout << *it << '\n';
    // ++it;
    // std::cout << *it << '\n';

    // std::cout << *value << '\n';
    // std::cout << *(value + 1) << '\n';
    // std::cout << *(value + 2) << '\n';

    // std::cout << *value << std::endl;

    // delete[] value;



    std::cout << '\n';
    system("pause");
    return 0;
}
