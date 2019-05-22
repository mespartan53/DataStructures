#include <iostream>
#include <cmath>

using namespace std;

class Rectangle {
    private:
    int base, 
        height;
    
    public:
    Rectangle(){base = 0; height = 0;}
    Rectangle(int n){base = height = n;}
    Rectangle(int b, int h){base = b; height = h;}
    Rectangle(Rectangle & rect)
    {
     
        base = rect.base;
        height = rect.height;
        
    }
    ~Rectangle(){delete this;}
    
    void setHeight(int h){height = h;}
    void setBase(int b){base = b;}
    int getHeight(){return height;}
    int getBase(){return base;}
    
    int getArea(){return base*height;}
    int getPerimeter(){return 2*base+2*height;}
    int getDiagonal(){return sqrt(static_cast<float>(base)*base+static_cast<float>(height)*height);}
    
};

int main() {
    
    int base, height;
    Rectangle * r1;
    
    cout << "Enter Base and Height split by a space and followed by enter.\n";
    cin >> base >> height;
    r1 = new Rectangle(base, height);
    
    cout << "Base: " << r1->getBase() << endl << "Height: " << r1->getHeight() << endl;
    
    system("Pause");
    delete r1;
    return 0;   
}
