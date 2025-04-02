#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class World
{
public:
    ~World()
    {
        std::cout << "World::~World()" << '\n';

        Free();
    }

    World()
    {
        NumActors = new int{0};
    }

    World(const World& Other)
    {
        NumActors = new int;

        memcpy(NumActors, Other.NumActors, sizeof(int));
    }

    void Free()
    {
        delete NumActors;
    }

private:
    int* NumActors;
};

class Actor // class itself
{
public: // access modifier

    // Actor()
    // {
    //     X = 0.f;
    // }

    Actor(int id) : X(0.f), Id(id)
    {
    }

    float GetX() // method
    {
        return X;
    }

    World GetWorld()
    {
        return World;
    }

    void SetX(float newValue)
    {
        if (newValue < 0)
        {
            return;
        }

        X = newValue;
    }

    int GetId() const
    {
        return this->Id;
    }

private:
    float X{}; // field
    const int Id; // constant field

    World World;
};

class Character
{
public:
    ~Character()
    {
        std::cout << "Character::~Character()" << '\n';
    }

    Character()
    {
        XSetHealth(0);
        XSetName(nullptr);
    
        std::cout << "Character::Character()" << '\n';
    }

    Character(int Health, const char* Name)
    {
        XSetHealth(Health);
        XSetName(Name);

        std::cout << "Character::Character(int Health, const char* Name)" << '\n';
    }

    int XGetHealth() const
    {
        return My_Health;
    }

    const char* XGetName() const
    {
        return My_Name;
    }

    void XSetHealth(int NewValue)
    {
        if (NewValue <= 0)
        {
            My_Health = 0;
            return;
        }

        My_Health = NewValue;
    }

    void XSetName(const char* NewValue)
    {
        if (NewValue) // NewValue != nullptr
        {
            strcpy(My_Name, NewValue); // My_Name = NewValue;
        }
        else // NewValue == nullptr
        {
            memset(My_Name, 0, MaxNameLength);
        }
    }

private:
    static constexpr int MaxNameLength = 32;
    char My_Name[MaxNameLength];
    int My_Health;
};


int main(int argc, char* argv[])
{
    // void* world = nullptr;
    //
    // Actor Character{0, world}; // object
    //
    // Character.SetX(-16);
    //
    // std::cout << Character.GetX() << '\n';

    //// Destructors
    // std::cout << "begin" << '\n';
    //
    // {
    //     World world1;
    // } // <--- object is dead
    //
    // std::cout << "end" << '\n';

    //
    // Actor Actor1{10};
    // Actor Actor2{20};
    //
    // std::cout << Actor1.GetId() << '\n';
    // std::cout << Actor2.GetId() << '\n';

    //// Allocate with default constructor
    Character* Characters = new Character[100];


    const Character& First = Characters[0];
    
    // First.XSetHealth(100);
    // First.XSetName("pro100_Nagibator1337_228_69");
    
    std::cout << "Name = " << First.XGetName() << '\n';
    std::cout << "Health = " << First.XGetHealth() << '\n';
    
    
    Characters[1].XSetHealth(50);
    Characters[1].XSetName("jopich");
    
    std::cout << "Name = " << Characters[1].XGetName() << '\n';
    std::cout << "Health = " << Characters[1].XGetHealth() << '\n';

    delete[] Characters;


    //// Allocate raw memory
    // Character* RawCharacters = (Character*)operator new(sizeof(Character) * 100);
    //
    // operator delete(RawCharacters);


    //// Allocate with **

    // Character** Characters = new Character*[100]{};
    //
    // Characters[0] = new Character{50, "jopich"};
    //
    // std::cout << Characters[0]->XGetName() << '\n';
    //
    // delete Characters[0];
    // delete[] Characters;

    return 0;
}
