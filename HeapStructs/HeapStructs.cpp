#include <iostream>

constexpr int DEFAULT_LOGIN_SIZE = 32;
constexpr int DEFAULT_PASSWORD_SIZE = 32;

struct Account
{
    char* login;
    char* password;
    int age;
};

struct IntArray
{
    int* data;
    int length;
    int capacity;
};

void Append(IntArray& array, int value)
{
    if (array.length == array.capacity)
    {
        array.capacity *= 2;

        int* new_array = new int[array.capacity];

        for (int i = 0; i < array.length; i++)
        {
            new_array[i] = array.data[i];
        }

        delete[] array.data;

        array.data = new_array;
    }

    array.data[array.length++] = value;
}

Account* CreateAccount(const char* login, const char* password, int age)
{
    Account* account = new Account;

    account->login = new char[DEFAULT_LOGIN_SIZE]{};
    account->password = new char[DEFAULT_PASSWORD_SIZE]{};
    account->age = age;

    strcpy_s(account->login, DEFAULT_LOGIN_SIZE, login);
    strcpy_s(account->password, DEFAULT_PASSWORD_SIZE, password);

    return account;
}

void DestroyAccount(Account* account)
{
    delete[] account->login;
    delete[] account->password;
    delete account;
}

void PrintAccount(Account& account)
{
    std::cout << "Login -> " << account.login << '\n';
    std::cout << "Password -> " << account.password << '\n';
    std::cout << "Age -> " << account.age << '\n';
}

void PrintAccounts(Account** array, int length)
{
    for (int i = 0; i < length; i++)
    {
        PrintAccount(*array[i]);
    }
}

void AddAccount(Account**& array, int& capacity, int& length, Account* value)
{
    if (length == capacity)
    {
        capacity *= 2;

        Account** new_array = new Account*[capacity];

        for (int i = 0; i < length; i++)
        {
            new_array[i] = array[i];
        }

        delete[] array;

        array = new_array;
    }

    array[length++] = value;
}

void DestroyAccountArray(Account** array, int length)
{
    for (int i = 0; i < length; i++)
    {
        DestroyAccount(array[i]);
    }

    delete[] array;
}

int main(int argc, char* argv[])
{
    int capacity = 4;
    int length = 0;
    Account** array = new Account*[capacity];

    Account* account1 = CreateAccount("ALEX", "admin", 400);
    Account* account2 = CreateAccount("ALEX123", "admin", 300);
    Account* account3 = CreateAccount("ALEX456", "admin", 200);

    AddAccount(array, capacity, length, account1); // array.append(account1)
    AddAccount(array, capacity, length, account2); // array.append(account1)
    AddAccount(array, capacity, length, account3); // array.append(account1)

    PrintAccounts(array, length);

    DestroyAccountArray(array, length);

    return 0;
}
