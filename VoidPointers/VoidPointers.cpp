#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "mathlib.h"

struct Person
{
    char name[32];
    int age;
};

struct Account
{
    char* login;
    char* password;
};

// char* serialize(Person& person)
// {
//     
// }

void write_Person(Person& person, const char* filename)
{
    FILE* file = fopen(filename, "wb");

    if (file)
    {
        fwrite(&person, sizeof(Person), 1, file);

        fclose(file);
    }
}

Person read_Person(const char* filename)
{
    FILE* file = fopen(filename, "rb");

    if (file)
    {
        Person value;

        fread(&value, sizeof(Person), 1, file);

        fclose(file);

        return value;
    }

    return Person{};
}

void write_Account(Account& account, const char* filename)
{
    FILE* file = fopen(filename, "wb");

    if (file)
    {
        int loginSize = strlen(account.login);
        int passwordSize = strlen(account.password);

        fwrite(&loginSize, sizeof(int), 1, file); // metadata
        fwrite(account.login, sizeof(char), loginSize, file);

        fwrite(&passwordSize, sizeof(int), 1, file); // metadata
        fwrite(account.password, sizeof(char), passwordSize, file);

        fclose(file);
    }
}

Account* read_Account(const char* filename)
{
    FILE* file = fopen(filename, "rb");

    if (file)
    {
        Account* account = new Account;

        int loginSize;
        int passwordSize;

        fread(&loginSize, sizeof(int), 1, file);

        account->login = new char[loginSize + 1]{};

        fread(account->login, sizeof(char), loginSize, file);
        fread(&passwordSize, sizeof(int), 1, file);

        account->password = new char[passwordSize + 1]{};

        fread(account->password, sizeof(char), passwordSize, file);

        return account;
    }

    return nullptr;
}

int main(int argc, char* argv[])
{
    // binary write (int)
    // {
    //     FILE* file = fopen("data.bin", "wb");
    //
    //     if (file) // file != nullptr
    //     {
    //         int value = 99999;
    //         char* buffer = (char*)&value;
    //
    //         fwrite(buffer, sizeof(int), 1, file);
    //         
    //         fclose(file);
    //     }
    // }

    // binary read (int)
    // {
    //     FILE* file = fopen("data.bin", "rb");
    //
    //     if (file)
    //     {
    //         int value;
    //                     
    //         fread(&value, sizeof(int), 1, file);
    //
    //         fclose(file);
    //
    //         std::cout << value;
    //     }
    // }

    // {
    //     Person person;
    //
    //     person.age = 10000000;
    //
    //     strcpy(person.name, "Alex");
    //
    //     write_Person(person, "data.bin");
    // }

    // {
    //     Person person =  read_Person("data.bin");
    //
    //     std::cout << person.name << '\n';
    //     std::cout << person.age << '\n';
    // }

    {
        Account acc;
    
        acc.login = new char[32];
        acc.password = new char[32];
    
        strcpy(acc.login, "admin");
        strcpy(acc.password, "admin_password");
    
        write_Account(acc, "acc.bin");
    
        delete[] acc.login;
        delete[] acc.password;
    }


    {
        Account* account = read_Account("acc.bin");

        if (account)
        {
            std::cout << account->login << '\n';
            std::cout << account->password << '\n';
        }
    }

    // raw memory
    // init memory

    // int* ptr = new int[3]{10, 20, 30};

    // std::cout << sizeof(void);

    // void* memory = operator new(8);
    //
    // char* anchor = (char*)memory;
    //
    // *anchor = '@';
    //
    // anchor += sizeof(char);
    //
    // *(int*)anchor = 2351;
    //
    // anchor += sizeof(int);
    //
    // *(short*)anchor = 19;
    //
    // anchor += sizeof(short);
    //
    // *anchor = '$';
    //
    // {
    //     char* anchor = (char*)memory;
    //
    //     std::cout << *anchor << '\n';
    //
    //     anchor += sizeof(char);
    //
    //     std::cout << *(int*)anchor << '\n';
    //
    //     anchor += sizeof(int);
    //
    //     std::cout << *(short*)anchor << '\n';
    //
    //     anchor += sizeof(short);
    //
    //     std::cout << *anchor << '\n'; 
    // }
    //
    // operator delete(memory);

    // std::cout << ptr << '\n';


    return 0;
}
