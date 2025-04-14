#include <iostream>
#include <stack>
#include <queue>

// Stack - LIFO (Last In First Out)

void a();
void b();
void c();
// a begin, b begin, c exec, b end, a end 
void a()
{
    std::cout << "a begin" << '\n';
    b();
    std::cout << "a end" << '\n';
}

void b()
{
    std::cout << "b begin" << '\n';
    c();
    std::cout << "b end" << '\n';
}


void c()
{
    std::cout << "c exec" << '\n';
}


// Queue - FIFO - First In First Out
// PriorityQueue - FIFO


int main(int argc, char* argv[])
{
    using std::cout;

    //// Stack
    // std::stack<int> Values;
    //
    // Values.push(190);
    // Values.push(200);
    // Values.push(210);
    //
    // Values.pop();
    //
    // cout << Values.top() << '\n';

    //// Queue
    std::queue<int> Values;

    auto PrintQueue = [&Values]() -> void
    {
        while (!Values.empty())
        {
            cout << Values.front() << '\n';

            Values.pop();
        }
        
        std::cout << "-----------\n";
    };

    srand(time({}));

    Values.push(rand());
    Values.push(rand());
    Values.push(rand());

    Values.pop();
    
    // Range based for
    PrintQueue();
    // Enqueue
    // Dequeue


// Node
    
    return 0;
}
