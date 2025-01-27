#include <iostream>

int main(int argc, char* argv[])
{
    const int size = 10000;
    const int min = 10;
    const int max = 1000;
    int array[size];

    srand(time(0));

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % (max - min + 1) + min;
    }

    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << '\n';
    }

    std::cout << '\n';

    // Big O notation

    // Linear search
    // {
    //     int target;
    //
    //     std::cout << "Enter a value to search ->";
    //     std::cin >> target;
    //
    //     int found_index = -1;
    //     
    //     for (int i = 0; i < size; ++i)
    //     {
    //         if (array[i] == target)
    //         {
    //             found_index = i;
    //         }
    //     }
    //
    //     if (found_index != -1)
    //     {
    //         std::cout << "found at " << found_index << " index" << '\n';
    //     }
    //     else
    //     {
    //         std::cout << "No element found" << '\n';
    //     }
    // }

    // Double ended search

    // {
    //     int target;
    //     int found_index = -1;
    //     
    //     std::cout << "Enter a value to search ->";
    //     std::cin >> target;
    //     
    //     for (int i = 0, j = size - 1; i < j; ++i, --j)
    //     {
    //         if (array[i] == target)
    //         {
    //             found_index = i;
    //             break;
    //         }
    //
    //         if (array[j] == target)
    //         {
    //             found_index = j;
    //             break;
    //         }
    //     }
    //
    //     if (found_index != -1)
    //     {
    //         std::cout << "found at " << found_index << " index" << '\n';
    //     }
    //     else
    //     {
    //         std::cout << "No element found" << '\n';
    //     }
    // }

    // Bubble sort
    {
        for (int i = 0; i < size - 1; ++i)
        {
            for (int j = 0; j < size - i - 1; ++j)
            {
                if (array[j] > array[j + 1])
                {
                    int temp = array[j];

                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }

        for (int i = 0; i < size; ++i)
        {
            std::cout << array[i] << ' ';
        }

        std::cout << '\n';
    }


    // Selection sort
    // {
    //     for (int i = 0; i < size; i++)
    //     {
    //         int index = i;
    //
    //         for (int j = i + 1; j < size; j++)
    //         {
    //             if (array[index] > array[j])
    //             {
    //                 index = j;
    //             }
    //         }
    //
    //         if (index != i)
    //         {
    //             int temp = array[index];
    //
    //             array[index] = array[i];
    //             array[i] = temp;
    //         }
    //     }
    //
    //     for (int i = 0; i < size; ++i)
    //     {
    //         std::cout << array[i] << ' ';
    //     }
    // }

    // Insertion sort
    // {
    //     for (int i = 1; i < size; i++)
    //     {
    //         int j = i - 1;
    //         int element = array[i];
    //
    //         while (j >= 0 && array[j] > element)
    //         {
    //             array[j + 1] = array[j];
    //             j--;
    //         }
    //
    //         array[j + 1] = element;
    //     }
    //
    //     for (int i = 0; i < size; ++i)
    //     {
    //         std::cout << array[i] << ' ';
    //     }
    // }

    // Binary search
    {
        int target;

        std::cout << "Enter a number to find ->";
        std::cin >> target;

        int found_index = -1;
        int low = 0;
        int high = size - 1;

        int it = 0;

        while (low <= high)
        {
            it++;
            int mid = low + (high - low) / 2;

            if (array[mid] == target)
            {
                found_index = mid;
                break;
            }

            if (array[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        std::cout << "Found index = " << found_index << '\n';\
        std::cout << "Iterations = " << it << '\n';
    }
    
    system("pause");

    return 0;
}
