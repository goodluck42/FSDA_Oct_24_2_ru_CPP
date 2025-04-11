#include <iostream>
#include <vector>

class Object
{
public:
    ~Object()
    {
        std::cout << "~Object::Object()" << '\n';
    }

    Object()
    {
        std::cout << "Object::Object()" << '\n';
    }

    Object(const Object& obj)
    {
        std::cout << "Object(const Object&)" << '\n';
    }

    Object(Object&& obj)
    {
        std::cout << "Object(Object&&)" << '\n';
    }

    Object(void* ptr)
    {
        std::cout << "Object::Object(void*)" << '\n';
    }

    Object& operator=(const Object& obj)
    {
        std::cout << "Object& operator=(const Object&)" << '\n';

        return *this;
    }

    Object& operator=(Object&& obj) noexcept
    {
        std::cout << "Object& operator=(Object&&)" << '\n';

        return *this;
    }
};

//
//
// class Array
// {
// public:
//     Array() : My_Obj(nullptr)
//     {
//         std::cout << "Array::Array()" << '\n';
//     }
//
//     void AddObject(const Object& Object)
//     {
//         std::cout << "Array::AddObject(const Object& Object)" << '\n';
//     }
//
// private:
//     Object My_Obj;
// };

// generic spec
template <typename TType>
class Array
{
public:
    ~Array()
    {
        operator delete(My_Data);
    }

    Array()
    {
        std::cout << "Array<TType>::Array()" << '\n';

        My_Data = (TType*)operator new(69);
    }

    void Append(const TType& Value)
    {
        std::cout << "Array<TType>::Append(const TType& Value)" << '\n';
    }

private:
    TType* My_Data;
};

// full spec
template <>
class Array<void>
{
};

// full spec
template <>
class Array<bool>
{
public:
    ~Array()
    {
    }

    Array()
    {
    }

    void AppendBool(bool Value)
    {
        std::cout << "Array<bool>::AppendBool(bool Value)" << '\n';
    }
};

// partial spec
template <typename TType>
class Array<TType*>
{
public:
    ~Array()
    {
        auto LocalAnchor = My_Memory;
        
        for (size_t i = 0; i < My_Length; ++i)
        {
            LocalAnchor->~TType();
            LocalAnchor += 1;
        }
        
        operator delete(My_Memory);
    }

    Array()
    {
        std::cout << "Array<TType*>::Array()" << '\n';

        My_Memory = My_Anchor = (TType*)operator new(sizeof(TType) * 16);
    }

    void Append(const TType& Object)
    {
        new(My_Anchor) TType(Object); // placement new

        My_Anchor += sizeof(TType);

        My_Length++;
    }

private:
    TType* My_Memory;
    TType* My_Anchor;
    size_t My_Length = 0;
};


template<typename T>
struct IsPrimitive
{
    static constexpr bool Value = false;
};

int main(int argc, char* argv[])
{
    std::cout << IsPrimitive<int>::Value << '\n'; // Value must be true
    std::cout << IsPrimitive<void*>::Value << '\n'; // Value must be false
    
    //Array<bool> My_Array;

    //My_Array.Append(Object{});

    // Array<int> Arr;
    //
    // Arr.Append(10);

    //Array<int> IntArr;

    //IntArr.Append(10);

    return 0;
}


