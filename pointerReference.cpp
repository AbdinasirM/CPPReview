#include <iostream>
#include <string>
using namespace std;


int main (){

    string  food = "pizza";
    string *ptr =&food;

    cout<<ptr<<endl; //gets the address of the food variable
    cout<<*ptr<<endl; //gets the value of the food variable
    


    return 0;
}