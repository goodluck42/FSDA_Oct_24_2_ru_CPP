#include "Account.h"
#include <iostream>

void Account::SetAge(int value)
{
    this->Age = value;

    // Foo(this);
}

Account::Account()
{
    //Account* self = this;
        
    std::cout << this << '\n';

    ++Count;
}

Account::Account(int birthdate)
{
    this->birthdate = birthdate;
}

int Account::GetAge() const
{
    // std::cout << Count;
        
    //return Age;

    // Age = 20;
    
    return this->Age;
}

int Account::GetBirthdate() const
{    
    return this->birthdate;
}

int Account::GetCount()
{
    //std::cout << Age;
        
    return Count;
}

int Account::Count = 0;