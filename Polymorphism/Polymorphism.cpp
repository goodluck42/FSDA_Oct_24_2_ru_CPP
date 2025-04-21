#include <iostream>

class Item // abstract class
{
public:
    virtual ~Item()
    {
        delete[] My_ItemName;

        std::cout << "Item::~Item()" << '\n';
    }

    Item()
    {
        My_ItemName = new char[32]{"ItemName"};

        std::cout << "Item::Item()" << '\n';
    }

    // virtual void Use()
    // {
    //     std::cout << "Using an item" << '\n';
    // }

    const char* GetItemName()
    {
        return My_ItemName;
    }

    virtual void Use() = 0; // pure virtual function/methods / abstract method
protected:
    char* My_ItemName;
};

class Medkit : public Item // abstract
{
public:
    virtual ~Medkit() override = default;
    
    Medkit()
    {
        My_HP = 100;
    }

    virtual void Use() override
    {
        std::cout << "Using medkit" << '\n';
    }

    float GetHP()
    {
        return My_HP;
    }

private:
    float My_HP;
};

class Energizer : public Item
{
public:
    virtual ~Energizer()
    {
        std::cout << "Energizer::~Energizer()" << '\n';
    }

    Energizer()
    {
        std::cout << "Energizer::Energizer()" << '\n';

        My_StaminaPoints = 50;
    }

    virtual void Use() override
    {
        std::cout << "Using Energizer" << '\n';
    }

    float GetStaminaPoints()
    {
        return My_StaminaPoints;
    }

private:
    float My_StaminaPoints;
    // void* __vptr;
};

class Stim : public Item
{
public:
    virtual void Use() override
    {
        std::cout << "Using Stim" << '\n';
    }
};

int main(int argc, char* argv[])
{
    Item* item = new Medkit; // dynamic polymorphism
    
    item->Use();
    
    std::cout << sizeof(Energizer);


    Item* MyItem = new Energizer;

    delete MyItem;

    //// Inventory
    // Item** Inventory = new Item*[3]{};
    //
    // Inventory[0] = new Medkit;
    // Inventory[1] = new Energizer;
    // Inventory[2] = new Stim;
    //
    // for (int i = 0; i < 3; i++)
    // {
    //     Inventory[i]->Use();
    // }
    //
    //
    // delete Inventory[0];
    // delete Inventory[1];
    // delete Inventory[2];
    //
    // delete[] Inventory;

    return 0;
}
