
#ifndef VECTOR_H
#define VECTOR_H

// Vector.h
#include <iostream>
#include <cassert>

using namespace std;

template <class T>  
class Vector
{
public:

    typedef T * iterator;
 
    Vector(unsigned int size = 0, const T & initial = T()); // default constructor
    Vector(const Vector<T> & v);                            // copy constructor
    Vector(Vector<T> && v);                                 // move constructor
    ~Vector();                                              // destructor
    Vector<T> & operator=(const Vector<T> & v);             // copy assignment
    Vector<T> & operator=(Vector<T> && v);                  // move assignment
 
    unsigned int capacity() const;
    unsigned int size() const;   
    bool empty() const;
 
    iterator begin();                      // return iterator to first element
    iterator end();                        // return iterator to last element
    T & front();                           // return reference to first element
    T & back();                            // return reference to last element
    void push_back(const T & value);
    void push_back(T && value);
    void pop_back();               
 
    void reserve(unsigned int capacity);   // adjust capacity
    void resize(unsigned int size);        // adjust size
 
    T & operator[](unsigned int index);
    void erase(iterator);                  // erase elem iterator points to (shift left from iterator)
 
private:
    unsigned int my_size;
    unsigned int my_capacity;
    T * buffer;
};

// default constructor
template <class T>  
Vector<T>::Vector(unsigned int size, const T & initial)
{
    my_size = size;
    my_capacity = size;
    if (size == 0)
        buffer = nullptr;
    else {
        buffer = new T[size];
        assert(buffer != nullptr);
    }

    for (int i = 0; i < size; i++)
        buffer[i] = initial;
}

// copy constructor
template <class T>  
Vector<T>::Vector(const Vector<T> & v)
{
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    buffer = new T[my_capacity];
    assert(buffer != nullptr);

    for (int i = 0; i < my_size; i++)
        buffer[i] = v.buffer[i];
}

// move constructor
template <class T>  
Vector<T>::Vector(Vector<T> && v): my_size{v.my_size}, my_capacity{v.my_capacity}, buffer{v.buffer}
{
    v.my_size = 0;
    v.my_capacity = 0;
    v.buffer = nullptr;
}

template <class T>  
Vector<T>::~Vector()
{
    my_size = 0;
    my_capacity = 0;
    delete [] buffer;
}

// copy assignment
template <class T>  
Vector<T> & Vector<T>::operator=(const Vector<T> & v)
{
    T * temp = new T[v.my_capacity];
    assert(temp != nullptr);

    for (int i = 0; i < v.my_size; i++)
        temp[i] = v.buffer[i];

    delete [] buffer;
    buffer = temp;
    my_size = v.my_size;
    my_capacity = v.my_capacity;

    return *this;
}

// move assignment
template <class T>  
Vector<T> & Vector<T>::operator=(Vector<T> && v)
{
    my_size = v.my_size;
    v.my_size = 0;
    my_capacity = v.my_capacity;
    v.my_capacity = 0;
    delete [] buffer;
    buffer = v.buffer;
    v.buffer = 0;

    return *this;
}

template <class T>  
void Vector<T>::reserve(unsigned int capacity)
{
    if (capacity <= my_capacity)
        return;

    T * new_buffer = new T[capacity];
    assert(new_buffer != nullptr);

    my_capacity = capacity;
    int size;
    for (size = 0; size < my_size; size++)
        new_buffer[size] = buffer[size];

    delete [] buffer;
    buffer = new_buffer;
}

template <class T>  
void Vector<T>::resize(unsigned int size)
{
    if (size > my_capacity)
        reserve(size*2);

    if (size > my_size)
        for (; my_size < size; my_size++)
            buffer[my_size] = T();
    else my_size = size;
}

template <class T>  
iterator Vector<T>::begin();                      // return iterator to first element
template <class T>  
iterator Vector<T>::end();                        // return iterator to last element
template <class T>  
T & Vector<T>::front();                           // return reference to first element
template <class T>  
T & Vector<T>::back();                            // return reference to last element
template <class T>  
void Vector<T>::push_back(const T & value);
{
    T* temp;
    
    if(my_size < my_cap)
    {
        buffer.[my_size++] = value;   
    }
    else
    {
        temp = new T[my_cap++];
        my_size++;
        for (int i = 0; i < my_size - 1; i++)
            temp.buffer[i] = buffer[i];
        temp.buffer[my_size - 1] = value;
        
        delete [] buffer;
        buffer = temp;
    }
}
template <class T>  
void Vector<T>::push_back(T && value);
template <class T>  
void Vector<T>::pop_back()
{
    size--;
}
 
template <class T>  
void Vector<T>::reserve(unsigned int capacity);   // adjust capacity
template <class T>  
void Vector<T>::resize(unsigned int size);        // adjust size

template <class T>   
T & Vector<T>::operator[](unsigned int index);
template <class T>  
void Vector<T>::erase(iterator);                  // erase elem iterator points to (shift left from iterator)

#endif
