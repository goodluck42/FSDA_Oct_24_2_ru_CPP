#include <iostream>
#include <functional>

class Item
{
public:
    int My_Id;
    int My_Quantity;
    std::string My_Name;
};

class ItemHasher
{
public:
    size_t operator()(const Item& item) const
    {
        return My_Hasher(item.My_Name);
    }

private:
    std::hash<std::string> My_Hasher;
};

template <typename TType, typename THasher>
class HashTable
{
public:
    void Add(const TType& Value)
    {
        std::cout << My_Hasher(Value) << '\n';
    }

    void Remove(const TType& Value)
    {
        
    }

private:
    THasher My_Hasher;
};

int main(int argc, char* argv[])
{
    HashTable<Item, ItemHasher> ItemTable;

    ItemTable.Add(Item{10, 3, "Test"});

    return 0;
}
