#include <iostream>
#include <random>

// 4 + 8 + 4 + 4 + 20
int main(int argc, char* argv[])
{
    // const int size = 5;

    // std::cin >> size;

    //             0   1   2   3   4
    // int arr[size] {10, 20, 30, 42, 13};
    //
    // std::cout << arr[0] << '\n';  

    //// Arrays part 1 (input & output)
    // {
    //     const int size = 5;
    //
    //     int arr[size];
    //
    //     // 0 1 2 3 4
    //     // Read numbers from a user
    //     for (int i = 0; i < size; i++)
    //     {
    //         std::cout << "Enter a number -> ";
    //         std::cin >> arr[i];
    //     }
    //
    //     // Output to console
    //     for (int i = 0; i < size; i++)
    //     {
    //         std::cout << "arr[i] = " << arr[i] << '\n';
    //     }
    // }

    //// Random numbers (RNG) part 1
    // {
    //     std::cin.get();
    //     
    //     srand(time(0));        
    //
    //     int value = rand();
    //     
    //     std::cout << value << '\n';
    // }

    //// Random numbers (RNG) part 2
    // {
    //     std::default_random_engine generator(time(0));
    //     std::uniform_int_distribution<int> range(10, 99);
    //
    //     int value = range(generator);
    //
    //     std::cout << value << '\n';
    // }

    //// Arrays part 2 (random & output)

    {
        srand(time(0));
    
        const int size = 10;
        const int min = 10;
        const int max = 99;
        int arr[size];
    
        // min 10, max = 99
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % (max - min + 1) + min;
        }
    
        // Output to console
        for (int i = 0; i < size; i++)
        {
            std::cout << "arr[i] = " << arr[i] << '\n';
        }
    }


    //// Random min max
    // {
    //     int min = 50;
    //     int max = 75;
    //     
    //     srand(time(0));
    //     
    //     int value = rand() % (max - min + 1) + min;
    //     
    //     std::cout << value << '\n';
    //
    //     // int value;
    //     //
    //     // std::cin >> value;
    //     //
    //     // std::cout << value % 90;
    // }


    
    system("pause");

    return 0;
}
