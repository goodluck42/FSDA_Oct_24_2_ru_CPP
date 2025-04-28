#include <iostream>
#include <stdexcept>
#include <vector>

#define GENERATE_EXCEPTION_CONSTRUCTOR(ClassName) public: ClassName##(const std::string& Message) : Exception(Message) { }

class Exception : public std::exception
{
public:
    Exception(const std::string& Message) : My_Message(Message)
    {
    }

    virtual char const* what() const override
    {
        return My_Message.c_str();
    }

protected:
    std::string My_Message;
};

class OutOfRangeException : public Exception
{
    GENERATE_EXCEPTION_CONSTRUCTOR(OutOfRangeException)
};

class NegativeIndexException : public Exception
{
public:
    GENERATE_EXCEPTION_CONSTRUCTOR(NegativeIndexException)
};

class Vector
{
public:
    int& At(int Index)
    {
        if (Index < 0)
        {
            throw NegativeIndexException{"Index is negative!"};
        }

        if (Index >= My_Length)
        {
            throw OutOfRangeException{"Vector index out of range!"};
        }
        
        return *(My_Arr + Index);
    }

    int& operator[](int Index)
    {
        return *(My_Arr + Index);
    }

private:
    int My_Arr[3]{10, 20, 30};
    const int My_Length = 3;
};

int main(int argc, char* argv[])
{
    Vector Values;

    //// Catch different exceptions
    try
    {
        int& Value = Values.At(4); // <-----
    
        Value = 40;
    
        std::cout << Value;
    }
    catch (OutOfRangeException& Ex) // if
    {
        std::cout << "OutOfRangeException: " << Ex.what() << '\n';
    }
    catch (NegativeIndexException& Ex) // else if
    {
        std::cout << "NegativeIndexException: " << Ex.what() << '\n';
    }
    catch (Exception& Ex) // else
    {
        std::cout << "Exception: " << Ex.what() << '\n';
    }
    catch (...)
    {
        std::cout << "Unknown error!" << '\n';
    }
    //// Catch all exceptions

    // try
    // {
    //     int& Value = Values.At(4); // <-----
    //
    //     Value = 40;
    //
    //     std::cout << Value;
    // }
    // catch (Exception& Ex)
    // {
    //     std::cout << Ex.what() << '\n';
    // }


    // while (true)
    // {
    //     size_t Index;
    //
    //     std::cin >> Index;
    //
    //     if (Index >= Values.size())
    //     {
    //         std::cout << "Invalid Index" << '\n';
    //         continue;
    //     }
    //
    //     Values[Index] = 100;
    //
    //     std::cout << Values[Index] << '\n';
    //     
    //     break;
    // }


    //std::cout << Values.at(4) << '\n';
    return 0;
}
