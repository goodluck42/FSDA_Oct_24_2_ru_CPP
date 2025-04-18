#include <iostream>
#include <vector>

// model class (анемичная модель)
// class Game
// {
// public:
//     int id;
//     std::string My_Name; // My_Name = other.My_Name
//     std::vector<std::string> My_Genres;
//
//     unsigned int My_Price;
// };
// //// Aggregation
// class Library
// {
// public:
//     ~Library()
//     {
//         // My_Games.clear();
//     }
//     void Add(Game* Value)
//     {
//         My_Games.push_back(Value);
//     }
// private:
//     std::vector<Game*> My_Games;
// };

//// Composition
// class Library
// {
// public:
//     ~Library()
//     {
//         for (size_t i = 0; i < My_Games.size(); ++i)
//         {
//             delete My_Games[i];
//         }
//     }
//     
//     void Add(Game* Value)
//     {
//         My_Games.push_back(Value);
//     }
//     void Destroy()
//     {
//         My_Games.clear();
//     }
// private:
//     std::vector<Game*> My_Games;
// };

enum class Gender : bool
{
    Male,
    Female
};

class Person // Parent class, Base class
{
public:
    void SetName(const std::string& Name)
    {
        My_Name = Name;
    }

    const std::string& GetName() const
    {
        return My_Name;
    }

    void SetAge(int Age)
    {
        if (My_Gender == Gender::Male)
        {
            if (Age > 0 && Age < 70)
            {
                My_Age = Age;
            }
        }
        else
        {
            if (Age > 0 && Age < 100)
            {
                My_Age = Age;
            }
        }
    }

    int GetAge() const
    {
        return My_Age;
    }

    Gender GetGender() const
    {
        return My_Gender;
    }

    void SetGender(Gender Gender)
    {
        My_Gender = Gender;
    }

    void PrintInfo()
    {
        std::cout << "Name = " << My_Name << '\n';

        std::cout << "Gender = ";

        switch (My_Gender)
        {
        case Gender::Male:
            std::cout << "Male";
            break;
        case Gender::Female:
            std::cout << "Female";
            break;
        }
        std::cout << '\n';
        std::cout << "Age = " << My_Age << '\n';
    }

protected:
    std::string My_Name;
    Gender My_Gender{};
    int My_Age{};
};

class Student : public virtual Person
{
public:
    void SetCoins(int Coins)
    {
        if (Coins > 0)
        {
            My_Coins = Coins;
        }
    }

    int GetCoins() const
    {
        return My_Coins;
    }

    void SetCrystals(int Crystals)
    {
        if (Crystals > 0)
        {
            My_Crystals = Crystals;
        }
    }

    int GetCrystals() const
    {
        return My_Crystals;
    }

protected:
    int My_Coins{};
    int My_Crystals{};
};

class Teacher : public virtual Person // child class, derived class
{
protected:
    int My_Salary{};

public:
    void SetSalary(int Salary)
    {
        if (Salary < 0)
        {
            return;
        }

        My_Salary = Salary;
    }

    int GetSalary() const
    {
        return My_Salary;
    }

    void PrintTeacherInfo()
    {
        //PrintInfo();

        std::cout << My_Age;
        std::cout << "Salary = " << My_Salary << '\n';
    }
};

class SuperStudent : public Student, public Teacher
{
public:
    SuperStudent()
    {
    }
};

class A
{
public:
    int PublicValue;

protected:
    int ProtectedValue;

private:
    int PrivateValue;
};

class B : public A
{
public:
    B()
    {
        ////// class B : public A
        //// public -> public
        //// protected -> protected
        //// private -> private
        //// this->ProtectedValue = 10;
        // this->PublicValue = 10;

        ////// class B : protected A
        //// public -> protected
        //// protected -> protected
        //// private -> private
        //// this->ProtectedValue = 10;
        //// this->PublicValue = 10;

        ////// class B : protected A
        //// public -> private
        //// protected -> private
        //// private -> private

        this->ProtectedValue = 10;
        this->PublicValue = 10;
    }
};

class C : public B
{
public:
    C()
    {
        this->PublicValue = 10;
        this->ProtectedValue = 10;
    }
};

int main(int argc, char* argv[])
{
    ////
    // Game* Game1 = new Game;
    //
    // Game1->id = 1;
    // Game1->My_Name = "r6";
    // Game1->My_Genres.push_back("Shooter");
    // Game1->My_Price = 10;
    //
    // {
    //     Library MyLibrary;
    //
    //     MyLibrary.Add(Game1);
    //     // MyLibrary.~Library();
    // }
    //
    // std::cout << Game1->My_Price << '\n';
    // std::cout << Game1->My_Name << '\n';

    // SuperStudent SuperStudent1{};
    //
    // SuperStudent1.SetAge(18);
    // SuperStudent1.SetGender(Gender::Female);
    // SuperStudent1.SetName("Emi");


    //// class B : public A
    // B Object;
    //
    // Object.PublicValue = 42;

    //// class B : protected A
    // B Object;
    //
    // Object.PublicValue = 42; // compile error

    return 0;
}
