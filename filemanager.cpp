#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Filemanager
{
public:
    bool writeToFile(const string &filename)
    {
        ofstream myfile(filename, ios::app);//opened the file in append mode that way if it is existing file it doesn't erase the current code.

        if (myfile.is_open())
        {
            myfile << "new content in this new file!"<<endl;
            myfile.close();

            cout << "Saved text successfully on the file!"<<endl;
            return true;
        }
        else
        {
            cerr << "Unable to open file: " << filename << endl;
            return false;
        }
    };

bool readFile(const string &filename) {
    ifstream myfile(filename);
    string myText;

    if (myfile.is_open()) {
        bool fileHasContent = false;
        while (getline(myfile, myText)) {
            cout << myText << endl;
            fileHasContent = true;
        }
        myfile.close();
        if (fileHasContent) {
            return true;
        } else {
            cout << "File is empty." << endl;
            return false;
        }
    } else {
        cerr << "Unable to read the " << filename << endl;
        return false;
    }
}



};


int main()
{
    Filemanager fl;
    bool result = fl.readFile("newfile2.txt");
   if (result) {
        cout << "File operation successful" << endl;
    } else {
        cout << "File operation failed" << endl;
    }

    return 0;
}