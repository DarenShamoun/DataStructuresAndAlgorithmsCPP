#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

// swap and add 1 to each of the values
void swap(long& x, long& y) 
{
    long t;
    t = x+1;
    x = y+1;
    y = t;
}

int main(int argc, char** argv) 
{
    long a = 10;
    long b = 20;
    for (int i=1; i < argc; ++i) 
    {
        if (std::strcmp(argv[i], "-a") == 0) 
        {
            ++i;
            if (i < argc) 
            {
                a = std::atoi(argv[i]);
            } 
            else 
            {
                std::cerr << "Error using '-a' argument: no value provided\n";
            }
        } 
        else if (std::strcmp(argv[i], "-b") == 0) 
        {
            ++i;
            if (i < argc) 
            {
                b = std::atoi(argv[i]);
            } 
            else 
            {
                std::cerr << "Error using '-b' argument: no value provided\n";
            }
        } 
        else 
        {
            std::cerr << "Unrecognized argument. Using defaults.\n";
            std::cerr << "Usage: " << argv[0] 
                      << " [-a an_int] [-b an_int]\n";
        }
    }
    cout << "original values:\n";
    cout << "a: " << a << ", ";
    cout << "b: " << b << '\n';

    // make temp copies before call
    int x = a;
    int y = b;

    // swap (and add 1)
    swap (a, b);

    cout << "\nafter swap and add:\n";
    cout << "a: " << a << ", ";
    cout << "b: " << b << '\n';

    //validate a and b
    assert (a == y+1);
    assert (b == x+1);
    
    return 0;
}

