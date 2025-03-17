#pragma once

class Account
{
public:
    Account();
    Account(int birthdate);
    
    // int GetAge();
    int GetAge() const;
    void SetAge(int value);

    int GetBirthdate() const;

    static int GetCount();
    
private:
    int birthdate;
    int Age = 0;
    static int Count;
};
