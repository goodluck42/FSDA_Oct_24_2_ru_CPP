#include <iostream>
#include <fstream>

class Animal
{
public:
    virtual ~Animal() = default;

    Animal(const std::string& Name) : My_Name(Name)
    {
    }

    virtual void Sound() = 0; // pure virtual function

    const std::string& GetName()
    {
        return My_Name;
    }

private:
    std::string My_Name;
};

class Monkey : public Animal
{
public:
    Monkey(const std::string& Name) : Animal(Name)
    {
    }

    virtual void Sound() override
    {
        std::cout << "Hoo hah!" << '\n';
    }

    void EatBanana()
    {
        std::cout << "Monkey is eating an banana!" << '\n';
    }
};

class Lion : public Animal
{
public:
    Lion(const std::string& Name) : Animal(Name)
    {
    }

    virtual void Sound() override
    {
        std::cout << "Grrrr!" << '\n';
    }
};

class Cock : public Animal
{
public:
    Cock(const std::string& Name) : Animal(Name)
    {
    }

    virtual void Sound() override
    {
        std::cout << "Kukareku!" << '\n';
    }
};

class Zoo
{
public:
    ~Zoo()
    {
        for (int i = 0; i < My_Length; ++i)
        {
            delete My_Animals[i]; // scalar
        }

        delete[] My_Animals; // vector
    }

    Zoo()
    {
        My_Animals = new Animal*[My_Capacity]; // vector
    }

    void Add(Animal* animal)
    {
        if (animal && My_Length < My_Capacity)
        {
            My_Animals[My_Length++] = animal;
        }
    }

    void Remove(Animal* animal)
    {
        for (int i = 0; i < My_Length; ++i)
        {
        }
    }

    void NotifyAll()
    {
        for (int i = 0; i < My_Length; ++i)
        {
            auto* a = My_Animals[i];

            std::cout << "Name: " << a->GetName() << '\n';

            My_Animals[i]->Sound();
        }
    }

private:
    int My_Capacity = 4;
    int My_Length = 0;
    Animal** My_Animals{};
};

class Parent
{
public:
    Parent()
    {
        Parent_Value = 42;

        std::cout << "Parent" << '\n';
    }

    int Parent_Value;
};

class Child : public Parent
{
public:
    Child()
    {
        Child_Value = 33;

        std::cout << "Child" << '\n';
    }

    int Child_Value;
};

void MakeSound(Animal* animal)
{
    if (animal)
    {
        Cock* cock = dynamic_cast<Cock*>(animal);
        
        if (cock) // cock != nullptr
        {
            std::cout << "Rafa: " << '\n';
        }
        
        Monkey* monkey = dynamic_cast<Monkey*>(animal);

        if (monkey)
        {
            monkey->EatBanana();
        }
        
        animal->Sound();
    }
}

struct User
{
    int login = 13;
    int password = 42;
};

std::ostream& operator<<(std::ostream& os, const User& user)
{
    os << "Login: " << user.login << '\n';
    os << "Password: " << user.password << '\n';

    return os;
}

int main(int argc, char* argv[])
{
    // int c = (int)'@'; // C style  
    //
    // std::cout << c << '\n';

    //// static_cast
    // {
    //     int value = 42;
    //     float v1 = static_cast<float>(value);
    //
    //     int& value_ref = value;
    //     int* value_ptr = &value;
    //
    //     //float& fref = static_cast<float&>(value_ref);
    //     //float* fptr = static_cast<float*>(value_ptr);
    //
    //     //// downcast
    //     {
    //         // Animal* animal = new Monkey{"Clown"}; // 0x99 (Animal)
    //         // Monkey* monkey = static_cast<Monkey*>(animal); // 0x99 (Monkey)
    //         //
    //         // monkey->EatBanana();
    //
    //         // Parent* parent = new Parent;
    //         //
    //         // {
    //         //     Child* child = static_cast<Child*>(parent);
    //         //     
    //         //     std::cout << child->Child_Value << '\n';
    //         //     std::cout << parent->Parent_Value << '\n';
    //         // }
    //         //
    //         // delete parent;
    //     }
    // }

    //// reinterpret_cast
    {
        std::ifstream inputStream;
        
        const std::string filename = "data.txt";
       
        std::fstream fileStream{filename, std::ios::out | std::ios::binary};
        
        if (fileStream.is_open())
        {
            User user; // &user => User*
            
            fileStream << user;
            
            std::cout << user;
            
            fileStream.write(reinterpret_cast<char*>(&user), sizeof(User));
        }
        else
        {
            std::cout << "Error!" << '\n';
        }
    }

    
    //// dynamic_cast
    // {
    //     Animal* animal = new Monkey{"Emil"};
    //     Animal* animal2 = new Cock{"Rafa"};
    //     
    //     MakeSound(animal);
    //     MakeSound(animal2);
    //     
    //     // dynamic_cast<>
    // }

    //// reinterpret_cast

    //// const_cast
    // {
    //     int value = 42;
    //
    //     {
    //         const int& ref = value;
    //
    //         int& nonconst_ref = const_cast<int&>(ref);
    //
    //         nonconst_ref = 10;
    //     }
    //
    //     std::cout << value << '\n';
    //     
    // }

    // Zoo FSDA_Oct_24_2_ru;
    //
    // Cock* cock1 = new Cock{"Revanushka"}; // scalar 
    // Monkey* monkey1 = new Monkey{"Nailchik"}; // scalar
    // Lion* lion1 = new Lion{"Tural"}; // scalar
    //
    // FSDA_Oct_24_2_ru.Add(cock1);
    // FSDA_Oct_24_2_ru.Add(monkey1);
    // FSDA_Oct_24_2_ru.Add(lion1);
    // FSDA_Oct_24_2_ru.NotifyAll();

    

    return 0;
}
