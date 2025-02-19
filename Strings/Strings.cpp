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
    {
        char* str = new char[32]{};

        strcpy_s(str, 32, "Hello ");
        
        // _strupr_s(str, 32);

        // _strlwr_s(str, 32);
        
        // std::cout << std::isupper(str[0]);        
        // std::cout << std::islower(str[1]);

        // H e l l o _ w o r l d ...
        strcat_s(str, 32, "world");

        std::cout << str << '\n';
        
        delete[] str;
    }
        
    return 0;
}
