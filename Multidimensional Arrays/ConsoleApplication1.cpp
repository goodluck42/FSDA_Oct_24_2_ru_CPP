#include <iostream>


enum Cell
{
    Empty = 0,
    Cross = 1,
    Zero = -1
};

int main()
{
    char foreground;
    char background;

    switch (background)
    {
    case 0:
        switch (foreground)
        {
        case 1:
            system("color 01");
            break;
        case 2:
            system("color 02");
            break;
        case 3:
            system("color 03");
            break;
        case 4:
            system("color 04");
            break;
        // 
        }
    case 1:
        switch (foreground)
        {
        case 0:
            system("color 10");
        case 2:
            system("color 12");
            break;
        case 3:
            system("color 13");
            break;
        }
        break;
    // ...
    }

    // int a;
    // int b;
    //
    // std::cin >> a >> b;

    // ...

    // float c = a + (float)b / 100;
    //
    // std::cout << c * 0.9 << '\n';

    // std::cout << a << "." << b;

    // const int rows = 3;
    // const int cols = 3;
    //
    // //  0   1   2
    // // [X] [ ] [ ] 0
    // // [ ] [X] [ ] 1
    // // [ ] [ ] [X] 2
    //
    //
    // int matrix[rows][cols]{};
    //
    // // true - X
    // // false - 0
    // bool player = true;
    // bool isWin = false;
    //
    // while (true)
    // {
    //     if (isWin)
    //     {
    //
    //         std::cout << "Game over" << '\n';
    //         break;
    //     }
    //     
    //     int i; // row
    //     int j; // col
    //
    //     if (player)
    //     {
    //         std::cout << "Qadir (X) move! \n";
    //     }
    //     else
    //     {
    //         std::cout << "Ruslan (O) move! \n";
    //     }
    //
    //     std::cout << "Enter row col -> ";
    //     std::cin >> i >> j;
    //
    //     if (matrix[i][j] != Empty)
    //     {
    //         std::cout << "Cell is not empty!" << '\n';
    //
    //         continue;
    //     }
    //
    //     // Place a sign (X or 0)
    //     if (player)
    //     {
    //         matrix[i][j] = Cross;
    //     }
    //     else
    //     {
    //         matrix[i][j] = Zero;
    //     }
    //
    //     // change player
    //     player = !player;
    //
    //     // Print matrix
    //     for (int i = 0; i < rows; ++i)
    //     {
    //         for (int j = 0; j < cols; ++j)
    //         {
    //             char c;
    //
    //             switch (matrix[i][j])
    //             {
    //             default:
    //             case Empty:
    //                 c = ' ';
    //                 break;
    //             case Cross:
    //                 c = 'X';
    //                 break;
    //             case Zero:
    //                 c = '0';
    //             }
    //
    //             std::cout << '|' << c << "| ";
    //         }
    //
    //         std::cout << '\n';
    //     }

    // check diag
    // 0 0, 1 1, 2 2
    // if (matrix[0][0] == matrix[1][1]
    //     && matrix[1][1] == matrix[2][2])
    // {
    //     isWin = true;
    // }

    // check alt diag
    // 0 2, 1 1, 2 0
    // if (matrix[0][2] == matrix[1][1]
    //     && matrix[1][1] == matrix[2][0])
    // {
    //     isWin = true;
    // }
    //
    // // 0 0, 0 1, 0 2
    // if (matrix[0][0] == matrix[0][1] && matrix[0][1] == matrix[0][2])
    // {
    //     isWin = true;
    // }
    //
    // // 1 0, 1 1, 1 2
    // if (matrix[1][0] == matrix[1][1] && matrix[1][1] == matrix[1][2])
    // {
    //     isWin = true;
    // }
    //
    //
    // // 2 0, 2 1, 2 2
    // if (matrix[2][0] == matrix[2][1] && matrix[2][1] == matrix[2][2])
    // {
    //     isWin = true;
    // }
    // // 0 0, 1 0, 2 0
    // if (matrix[0][0] == matrix[1][0] && matrix[1][0] == matrix[2][0])
    // {
    //     isWin = true;
    // }
    //
    // // 0 1, 1 1, 2 1
    // if (matrix[0][1] == matrix[1][1] && matrix[1][1] == matrix[2][1])
    // {
    //     isWin = true;
    // }
    //
    // // 0 2, 1 2, 2 2
    // if (matrix[0][2] == matrix[1][2] && matrix[1][2] == matrix[2][2])
    // {
    //     isWin = true;
    // }
    // }
    // system("pause");

    return 0;
}
