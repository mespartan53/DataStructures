/***********************************************************************
Marcus Loureiro - Estrada
5/21/2019
String.cpp
Implementation of constructors and member functions defined in String.h.
************************************************************************/

#include "String.h"
#include<cassert>

// default constructor
String::String()
{
    size = 0;
    buffer = nullptr;
}

//           copy constructor
//Acquire the size then loop through each buffer
//and assign the source to this buffer.
String::String(const String &src)
{
    size = src.size;
    buffer = new char[size];
    assert(buffer != nullptr);
    for( int i = 0; i < size; i++ )
      buffer[i] = src.buffer[i];
}

//           move constructor
//Assign the source to this object then set the source to default
String::String(String && src): size{src.size}, buffer{src.buffer}
{
    src.size = 0;
    src.buffer = nullptr;
}

// constructor from "char string" to String
// find size of source, allocate space, assign source to buffer
String::String(const char * src)
{
    size = 0;
    for (const char *c = src; *c; c++)
        size++;
    buffer = new char[size];
    assert(buffer != nullptr);

    for (int i = 0; i < size; i++)
        buffer[i] = src[i];
}

//      Char constructor
//Create String with just one char
String::String(char c)
{
    size = 1;
    buffer = new char[size];
    assert(buffer != nullptr;
    buffer[0] = c;
}
// destructor
String::~String()
{
  delete[] buffer;
};              

String::int length()
{
    return size;
}
           
String::char & operator[](const int index)
{
    assert(index < size);
    return buffer[index];
}

// copy assignment
String::String & operator=(const String &src)
{
    size = src.size;
    char* temp = new char[size];
    assert(temp != nullptr);
  
    for (int i = 0; i < source.size; i++)
        temp[i] = source.buffer[i];
  
    delete [] buffer;
    buffer = temp;
    return *this;
}
           
// move assignment
String::String & operator=(String && src)
{
    size = src.size;
    delete [] buffer;
    buffer = src.buffer;
    src.size = 0;
    delete [] src.buffer;
    return *this;
}
String::String & operator+=(const String &src)
{
    size += src.size;
    char* temp = new char[size];
    assert(temp != nullptr);
  
    for (int i = 0; i < size - src.size; i++)
    {
         temp[i] = buffer[i];
    }
    for (int i = size - src.size; i < size; i++)
    {
        temp[i] = src.buffer[i - size + src.size];
    }
  
    delete [] buffer;
    buffer = temp;
    return *this;
}

String String::operator-(const String & str)
{
    String temp = *this;
    int i = 0, j, k;
    while (i <= temp.size - str.size) {
        j = i;
        k = 0;
        while (k < str.size)
            if (temp.buffer[j] == str.buffer[k]) {
                j++;
                k++;
            } else
                break;
        if (k == str.size) { // found it, shift
            for (j = i+str.size; j < temp.size; j++)
                temp.buffer[j-str.size] = temp.buffer[j];
            temp.size -= str.size;
        } else
            i++;
    }
    return temp;
}
//return the sub string of a String at position pos
//to the end of the string
String::String substr(unsigned pos)
{
    String temp = "";
    for (int i = 0; pos + i < size; i++)
        temp += buffer[pos + i];
    return temp;
}
           
String::String substr(unsigned pos, unsigned len) const
{
    String temp = "";
    for(int i = 0; i < len; i++)
      temp += buffer[pos + i];
    return temp;
}

friend bool operator==(const String &left, const String &right)
{
    if(left.size != right.size)
        return false;
    for(int i = 0; i < left.size; i++)
        if (left.buffer[i] != right.buffer[i])
            return false;
    return true;
}
           
friend bool operator<=(const String &left, const String &right)
{
    if (left.size > rigth.size)
        return false;
    for(int i = 0; i < left.size; i++)
        if(left.buffer[i] > right.buffer[i])
            return false;
    return true;
}
          
friend bool operator<(const String &left, const String &right)
{
    if (left.size >= rigth.size)
        return false;
    for(int i = 0; i <= left.size; i++)
        if(left.buffer[i] >= right.buffer[i])
            return false;
    return true;
}
           
friend ostream & operator<<(ostream &out, const String &src);
{
    for(int i = 0; i < src.size; i++)
        out << src.buffer[i];
    return out;
}
           
friend istream & operator>>(istream &in, String &src)
{
    src = "";
    char t = ' ';
    
    while (t == ' ' or t == '\t' or t == '\n')
        in.get(t);

    while (t != ' ' and t != '\t' and t != '\n') {
        src += t;
        in.get(t);
    }
    cin.unget();

    return in;                
}
