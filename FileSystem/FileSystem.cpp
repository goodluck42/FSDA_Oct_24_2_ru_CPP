#include <iostream>

// C style
// C++ style

int char_to_int(char c) // '2' to 2
{
    ???
}

char* readline(FILE* file)
{
    
}

int main(int argc, char* argv[])
{
    //// Write to file
    // {
    //     FILE* file{};
    //
    //     (void)fopen_s(&file, "data.txt", "w");
    //
    //     if (file != nullptr)
    //     {
    //         (void)fputc('X', file);
    //         (void)fputs("Privetik", file);
    //     
    //         (void)fclose(file);
    //     }
    // }

    // Read file
    // {
    //     FILE* file{};
    //
    //     (void)fopen_s(&file, "data.txt", "r");
    //
    //     if (file != nullptr)
    //     {
    //         int symbol = fgetc(file);
    //         //int symbol2 = fgetc(file);
    //
    //         std::cout << (char)symbol << '\n';
    //         // std::cout << (char)symbol2 << '\n';
    //
    //         char* buffer = new char[100]{};
    //
    //         (void)fgets(buffer, 100, file);
    //
    //         std::cout << buffer << '\n';
    //         
    //         delete[] buffer;
    //
    //         (void)fclose(file);
    //     }
    // }


    // Read whole file
    // {
    //     FILE* file{};
    //
    //     (void)fopen_s(&file, "data.txt", "r");
    //
    //     if (file != nullptr)
    //     {
    //         while (true)
    //         {
    //             char symbol = (char)fgetc(file);
    //
    //             if (symbol == EOF)
    //             {
    //                 break;
    //             }
    //             
    //             std::cout << symbol;
    //         }
    //                     
    //         (void)fclose(file);
    //     }
    // }

    // Read whole file 2
    // {
    //     FILE* file{};
    //
    //     (void)fopen_s(&file, "data.txt", "r");
    //
    //     if (file != nullptr)
    //     {
    //         int bufferSize = 64;
    //         char* buffer = new char[bufferSize];
    //
    //         while (true)
    //         {
    //             char* ptr = fgets(buffer, bufferSize, file);
    //             
    //             if (ptr == nullptr)
    //             {
    //                 break;
    //             }
    //
    //             std::cout << ptr;
    //         }
    //
    //         (void)fclose(file);
    //
    //         delete[] buffer;
    //     }
    // }

    // 
    // {
    //     FILE* file{};
    //
    //     (void)fopen_s(&file, "data.txt", "r");
    //
    //     if (file != nullptr)
    //     {
    //         while (true)
    //         {
    //             int c = fgetc(file);
    //
    //             std::cout << "code:" << c << "|symbol: " << (char)c << '\n';
    //
    //             if (c == EOF)
    //             {
    //                 break;
    //             }
    //         }
    //
    //         (void)fclose(file);
    //     }
    // }

    char c1 = '3';
    char c2 = '9';

    
    
    return 0;
}
