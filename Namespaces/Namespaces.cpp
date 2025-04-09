#include <iostream>

namespace MySql
{
    void connect()
    {
        std::cout << "Connected to MySql" << '\n';
    }

    namespace Util
    {
        const char* GetConnectionString()
        {
            return "MySQL";
        }
    }
}

namespace MSSql
{
    void connect()
    {
        std::cout << "Connected to MSSQL" << '\n';
    }
}

// using namespace MySql;
// using namespace MSSql;
// using namespace std; // sin!

int main(int argc, char* argv[])
{
    using std::cout;
    using std::cin;
    
    // connect();

    // cout << "Hello";
    //
    // int val;
    //
    // cin >> val;

    MySql::Util::GetConnectionString();
    
    return 0;
}
