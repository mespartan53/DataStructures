#ifndef RECTANGLE_H
#define RECTANGLE_H

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
    Rectangle & operator=(const Rectangle & r)
    { 
        base = r.base;
        height = r.height;  
        return *this;
    }
    
    int getArea(){return base*height;}
    int getPerimeter(){return 2*base+2*height;}
    int getDiagonal(){return sqrt(static_cast<float>(base)*base+static_cast<float>(height)*height);}
    bool isSquare(){return base == height;}
    
    //output all rectangle data and draw it;
    friend ostream & operator<<(ostream & out, Rectangle & r)
    {
     
        if (r.isSquare())
            out << "Square\n";
        else
            out <<"Rectangle\n";
            
        out << "Base: " << r.getBase() << endl
            << "Height: " << r.getHeight() << endl
            << "Perimeter: " << r.getPerimeter() << endl
            << "Area: " << r.getArea() << endl
            << "Diagonal: " << r.getDiagonal() << endl;
            
        for (int i = 0; i < r.getHeight(); i++)
        {
            for(int j = 0; j < r.getBase(); j++)
            {  
                if (i == 0 || i == r.getHeight() - 1)   
                    out << "--";
                else
                    if (j == 0)
                        out << "| ";
                    else if (j == r.getBase() - 1)
                        out << " |";
                    else
                        out <<"  ";
            }
            out << endl;
        }
        
        return out;
    }
    
    friend bool operator==(const Rectangle &left, const Rectangle &right)
    { 
        return (left.base * left.height) == (right.base * right.height);
    }
    
    friend bool operator<(const Rectangle &left, const Rectangle &right)
    {  
        return (left.base * left.height) < (right.base * right.height);   
    }
    
    friend bool operator<=(const Rectangle &left, const Rectangle &right)
    {
        return (left.base * left.height) <= (right.base * right.height);     
    }
};

#endif
