#include <iostream>

// int sum(int a, int b, int c = 10)
// {
//     return a + b + c;
// }
//
// float sum(float a, float b)
// {
//     return a + b;
// }

void call()
{
    static int a;

    std::cout << a << '\n';

    ++a;
}

void print_stars(int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << '*';
    }
}

// n = 5
// n = 4
// n = 3
// n = 2
// n = 1
// *****

void print_stars_recursive(int n)
{
    if (n == 0)
    {
        return;
    }

    std::cout << '*';

    print_stars_recursive(--n);
}

// 5! = 5 * 4 * 3 * 2 * 1 * 0
long long factorial(long long n)
{
    if (n == 1)
    {
        return n;
    }

    return n * factorial(n - 1);
}


int main(int argc, char* argv[])
{
    bool is5 = false;
    for (int i = 0; i < 9; ++i)
    {
        if (is5)
        {
            std::cout << ' ';
        }
        for (int j = 0; j < (is5 ? 5 : 6); ++j)
        {
            std::cout << "* ";
        }
        is5 = !is5;
        
        std::cout << '\n';
    }

    // for (int i = 0; i < 10; i++)
    // {
    //     call();
    // }

    // print_stars(5);

    // print_stars_recursive(5);

    std::cout << factorial(5) << '\n';

    //system("pause");

    return 0;
}
