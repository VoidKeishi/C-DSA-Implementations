#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H

#include <iostream>
#include <stdexcept>

struct StaticArray {
    int* data;
    std::size_t capacity;

    // Constructor
    StaticArray(std::size_t size);

    // Destructor
    ~StaticArray();

    // Function to get the size of the array
    std::size_t size() const;

    // Function to get an element at a specific index
    int& at(std::size_t index);

    // Function to set an element at a specific index
    void set(std::size_t index, int value);

    // Function to print all elements in the array
    void print() const;
};

#endif // STATIC_ARRAY_H