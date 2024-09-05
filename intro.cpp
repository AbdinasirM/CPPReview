//variable

#include <iostream>
#include <string>
#include <fstream>

using namespace std;



int main() {


// ofstream myfile("text.txt");

// myfile<<"shut the fuck up!";

// myfile.close();
// Create a text string, which is used to output the text file
string myText;
ifstream myfiletoread("text.txt");

int lines = 0; 
while(getline (myfiletoread, myText)) {
    
    lines += myText.size();
}

cout <<lines<<endl;
myfiletoread.close();

return 0;



}