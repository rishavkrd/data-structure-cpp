#include <iostream>
#include <stack>
using namespace std;

void invalidPointerCall(int* p)
{
    cout << *p << endl;
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    int* p = NULL;
    while (!s.empty())
    {
        cout << s.top() << ", ";
        s.pop();
    }
    // try catch block to handle exception when top is called on empty stack
    // segmentation fault cannot be caught by cpp try catch block
    // use gdb:
        // Compile with -g flag
        // gdb exception.exe 
            //run
            //frame
            //print <necessary debug info>

    try
    {
        cout << s.top() << ", ";
    }
    catch (...)
    {
        cout << "Exception caught" << endl;
    }

    cout << endl;
    return 0;
}