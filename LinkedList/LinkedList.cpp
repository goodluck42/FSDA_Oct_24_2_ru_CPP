#include <iostream>

template <typename UType>
class LinkedList;

template <typename TType>
struct LinkedListNode
{
    TType My_Value{};
    
    template <typename UType>
    friend class LinkedList;

private:
    LinkedListNode* My_Next{};
    LinkedListNode* My_Prev{};
};

template <typename TType>
class LinkedList
{
public:
    ~LinkedList()
    {
        if (My_Length == 0)
        {
            return;
        }

        LinkedListNode<TType>* CurrentNode = My_Head;

        while (CurrentNode != nullptr)
        {
            LinkedListNode<TType>* TempNode = CurrentNode->My_Next;

            delete CurrentNode;

            CurrentNode = TempNode;
        }
    }

    LinkedList() : My_Head{}, My_Tail{}
    {
    }

    LinkedListNode<TType>& InsertAtEnd(const TType& Value)
    {
        auto* NewNode = new LinkedListNode<TType>;

        NewNode->My_Value = Value;

        if (My_Length == 0)
        {
            My_Head = My_Tail = NewNode;
        }
        else
        {
            My_Tail->My_Next = NewNode;
            NewNode->My_Prev = My_Tail;
            My_Tail = NewNode;
        }

        ++My_Length;

        return *NewNode;
    }

    // LinkedListNode<TType>& InsertAfter(const TType& Value, const LinkedListNode<TType>& AfterNode)
    // {
    // }`

private:
    LinkedListNode<TType>* My_Head;
    LinkedListNode<TType>* My_Tail;
    size_t My_Length = 0;
};

int main(int argc, char* argv[])
{
    // LinkedList<int> MyLL;
    //
    // // 10 -> 20 -> 30
    // MyLL.InsertAtEnd(10);
    // LinkedListNode<int>& Node = MyLL.InsertAtEnd(20);
    // MyLL.InsertAtEnd(30);
    //
    // //MyLL.InsertAfter(25, Node);

    
    
    return 0;
}
