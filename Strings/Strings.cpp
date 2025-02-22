// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale>

// Ela\0
// 10,20,30,40
void cout(const char* str)
{
    while (true)
    {
        char c = *str;

        if (c == '\0')
        {
            break;
        }

        printf("%c", c);

        ++str;
    }

    printf("\n");
}

int my_strlen(const char* str)
{
    int count = 0;

    while (true)
    {
        char c = *str;

        if (c == '\0')
        {
            return count;
        }

        ++count;
        ++str;
    }
}

int my_strcmp(const char* str1, const char* str2)
{
    while (true)
    {
        char left = *str1;
        char right = *str2;

        if (left == '\0' && right == '\0')
        {
            return 0;
        }

        if (left > right)
        {
            return 1;
        }

        if (left < right)
        {
            return -1;
        }

        ++str1;
        ++str2;
    }
}

int main(int argc, char* argv[])
{
    //  char str[6] = "Hello"; // read-write
    //  const char* str1 = "Hello"; // readonly
    //  char str2[] {'H', 'e', 'l', 'l', 'o', '\0'};
    //
    //  str[0] = 'h';
    //  //str1[0] = 'h';
    //
    //  // str = "Goodbye"; // error
    //  // str1 = "Goodbye"; // error
    //
    //  std::cout << str1;
    //
    // // Strings in memory
    //  {
    //      char str1[] = "Hello";
    //      char str2[] = "Hello";
    //
    //      std::cout << (void*)str1 << '\n';
    //      std::cout << (void*)str2 << '\n';
    //      
    //      std::cout << (str1 == str2 ? "equals" : "not equals");
    //  }
    //
    //  {
    //      const char* str1 = "Hello";
    //      const char* str2 = "Hello";
    //
    //      std::cout << (void*)str1 << '\n';
    //      std::cout << (void*)str2 << '\n';
    //
    //      if (str1 == str2)
    //      {
    //          std::cout << "Yasno";
    //      }
    //  }
    // {
    //     int length = 100;
    //     char* str = new char[length]{}; // buffer
    //
    //     strcpy_s(str, 3 + 1, "Ela");
    //     // strcpy_s(str, 6 + 1, "qwerty");
    //     
    //     cout(str);
    //
    //     std::cout << strlen(str);
    //     
    //     // s r u _ d e n g a m i \0 \0 \0 ...
    //     // q w e r t y \0 g a m i \0 \0 \0 ...
    //
    //     // for (int i = 0; i < length; i++)
    //     // {
    //     //     std::cout << str[i] << '\n';
    //     // }
    //
    //     // str[0] = 'h';
    //     // str[1] = 'o';
    //     // str[2] = 'o';
    //     // str[3] = 'k';
    //     
    //     delete[] str;
    // }


    // {
    //     int length = 32;
    //     char* my_str2 = new char[length]{};
    //
    //     // strcpy_s(my_str2, 13, "Hello World!");
    //
    //     std::cin.getline(my_str2, length);
    //
    //     std::cout << "Output string = " << my_str2 << '\n';
    //
    //     //std::cout << "len = " << my_strlen(my_str2) << '\n';
    //
    //     delete[] my_str2;
    // }

    // lower & upper case
    // {
    //     char* str = new char[32]{};
    //
    //     strcpy_s(str, 32, "Hello ");
    //     
    //     // _strupr_s(str, 32);
    //
    //     // _strlwr_s(str, 32);
    //     
    //     // std::cout << std::isupper(str[0]);        
    //     // std::cout << std::islower(str[1]);
    //
    //     // H e l l o _ w o r l d ...
    //     strcat_s(str, 32, "world"); // "str1" + "str2"
    //     
    //     std::cout << str << '\n';
    //     
    //     delete[] str;
    // }

    // Strings
    // {
    //     // char str[] = "ravan";
    //     // char str2[] = "ravan";
    //
    //     //str[0] = 'R'; // ok        
    // }

    // {
    //     const char* str = "ravan";
    //     const char* str2 = "ravan";
    //
    //     // str[0] = 'R';
    //     
    //     std::cout << (void*)str << '\n';
    //     std::cout << (void*)str2 << '\n';
    // }


    // char symbol = 'A';
    //
    // symbol += 32;

    // std::cout << (char)('a' - 32) << '\n';
    // std::cout << (char)('A' + 32) << '\n';

    // strlen;
    // strupr;
    // strlwr;
    // strcat;
    // strcpy;

    // strcmp

    // {
    //     int length = 100;
    //     char* str1 = new char[length];
    //     char* str2 = new char[length];
    //
    //     std::cin.getline(str1, length);
    //     std::cin.getline(str2, length);
    //
    //     int result = my_strcmp(str1, str2);
    //
    //     std::cout << result << '\n';
    //
    //     delete[] str1;
    //     delete[] str2;
    //
    //     // strcmp("Car", "Egg"); // -1 => "Car" < "Egg"
    //     // Car
    //     // Egg
    //     // 67 > 69
    //
    //
    //     // Car
    //     // Cam
    //
    //     // Cars
    //     // Car
    // }

    // {
    //     const char* str = "100";
    //     
    //     int result = atoi(str); // atof, atol, atoll
    //
    //     std::cout << result * 2 << '\n';
    // }

    // strchr & strstr
    {
        // auto c = L'z';
        
        char* str = new char[100]{};

        strcpy_s(str, 100, "Hey there! How are u doin? What are these???");

        ///
        // char* result = strchr(str, '!'); // strrchr & strchr
        ///

        char* result = strstr(str, "are"); // strstr
        
        // long long diff = std::abs(str - result);
        //
        // std::cout << str[diff];
        
        std::cout << result;
    }
    
    return 0;
}
