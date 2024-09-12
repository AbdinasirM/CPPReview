#include <iostream>
#include <string>
using namespace std;

// has no return type
void greetingMessage(string name)
{
    cout << "hello " << name << endl;
}

int add(int x, int y)
{
    return (x + y);
}

int main()
{

    string name = "Abdi";
    int x = 8;
    int y = 4;

    greetingMessage(name);

    cout << "The sum of " << x << " and " << y << " is: " << add(x, y) << endl;

    return 0;
}