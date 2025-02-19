// looops.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
//1
int main()
{
    int row = 5, col = 5;

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (i == 2 && j % 2 == 1) {
                std::cout << "  ";
            }
            else {
                std::cout << "* ";
            }
        }
        std::cout << "\n";
    }
    return 0;
    
    }


