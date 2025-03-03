#include <iostream>

// C style
// C++ style

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
    {
        FILE* file{};
    
        (void)fopen_s(&file, "data.txt", "r");
    
        if (file != nullptr)
        {
            int bufferSize = 64;
            char* buffer = new char[bufferSize];
    
            while (true)
            {
                char* ptr = fgets(buffer, bufferSize, file);
                
                if (ptr == nullptr)
                {
                    break;
                }
    
                std::cout << ptr;
            }
    
            (void)fclose(file);

            delete[] buffer;
        }
    }

    return 0;
}
