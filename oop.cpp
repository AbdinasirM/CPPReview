#include <iostream>
using namespace std;

class Myclass {
    private:
        int x;
        int y;
    public:
        void setX(int myX) {
            x = myX;
        }
        void setY(int myY) {
            y = myY;
           
        }
        int getX() {
            return x; 
        }
        int getY() {  
            return y;
        }
};  

int main() {
    Myclass myC;

    myC.setX(4);
    myC.setY(6); 

    cout << myC.getX() << endl;
    cout << myC.getY() << endl;

    return 0;
}