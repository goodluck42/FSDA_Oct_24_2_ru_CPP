#include <iostream>
#include "File1.h"

// SharedPtr, UniquePtr

template <typename TType>
class UniquePtr
{
public:
    ~UniquePtr()
    {
        if (std::is_array_v<TType>)
        {
            delete[] My_Data;
        }
        else
        {
            delete My_Data;
        }
    }

    UniquePtr(const UniquePtr<TType>& Other) = delete;

    UniquePtr(UniquePtr<TType>&& Other) noexcept
    {
        My_Data = Other.My_Data;
        Other.My_Data = nullptr;
    }

    UniquePtr(TType* Data) // new int;
    {
        if (Data)
        {
            My_Data = Data;
        }
    }

    void operator=(const UniquePtr<TType>& Other) = delete;

    UniquePtr<TType>& operator=(UniquePtr<TType>&& Other) noexcept
    {
        if (this != &Other)
        {
            this->~UniquePtr();

            this->My_Data = Other.My_Data;
            Other.My_Data = {};
        }

        return *this;
    }

    TType* Get() const
    {
        return My_Data;
    }

    TType& operator*()
    {
        return *My_Data;
    }

    TType* operator->()
    {
        return My_Data;
    }

private:
    TType* My_Data{};
};


template <typename TType>
class SharedPtr
{
public:
    ~SharedPtr()
    {
        if (*My_ReferenceCounter == 1)
        {
            delete My_Data;
            delete My_ReferenceCounter;

            return;
        }

        --(*My_ReferenceCounter);
    }

    SharedPtr(TType* Data)
    {
        if (Data)
        {
            My_Data = Data;
        }

        My_ReferenceCounter = new int{1};
    }

    SharedPtr(const SharedPtr& Other)
    {
        My_Data = Other.My_Data;
        My_ReferenceCounter = Other.My_ReferenceCounter;

        ++(*My_ReferenceCounter);
    }

    SharedPtr(SharedPtr<TType>&& Other) noexcept
    {
        My_Data = Other.My_Data;
        Other.My_Data = {};

        My_ReferenceCounter = Other.My_ReferenceCounter;
        Other.My_ReferenceCounter = {};
    }

    SharedPtr& operator=(const SharedPtr<TType>& Other)
    {
        if (this != &Other)
        {
            this->~SharedPtr();

            My_Data = Other.My_Data;
            My_ReferenceCounter = Other.My_ReferenceCounter;

            ++(*My_ReferenceCounter);
        }

        return *this;
    }

    SharedPtr& operator=(SharedPtr<TType>&& Other) noexcept
    {
        if (this != &Other)
        {
            this->~SharedPtr();

            My_Data = Other.My_Data;
            Other.My_Data = {};

            My_ReferenceCounter = Other.My_ReferenceCounter;
            Other.My_ReferenceCounter = {};
        }

        return *this;
    }

    TType* Get() const
    {
        return My_Data;
    }

    int GetCounter()
    {
        return *My_ReferenceCounter;
    }

    TType& operator*()
    {
        return *My_Data;
    }

    TType* operator->()
    {
        return My_Data;
    }

private:
    TType* My_Data;
    int* My_ReferenceCounter;
};

struct Person
{
    std::string Name;
    int Age;
};

void PrintPerson(SharedPtr<Person> Ptr)
{
    
}

int main(int argc, char* argv[])
{
    //UniquePtr<Person> Ptr{new Person{"Emi", 99}};

    std::cout << Counter << '\n';
    
    SharedPtr<Person> Me{new Person{"Alex", 22}};
    SharedPtr<Person> Ptr1{new Person{"Emi", 22}};
    SharedPtr<Person> Ptr2{Ptr1};
    
    Ptr1 = Me;

    std::cout << Ptr1.GetCounter() << '\n';
    std::cout << Ptr2.GetCounter() << '\n';
    //std::cout << Ptr3.GetCounter() << '\n';


    return 0;
}
