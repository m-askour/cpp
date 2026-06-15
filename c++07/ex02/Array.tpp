#include <iostream>
#include <string>

// Template member function implementations for Array

template<typename T>
Array<T>::Array() : arr(NULL), _size(0)
{}

template<typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]()), _size(n)
{}

template <typename T>
Array<T>::Array(const Array &other) : arr(NULL), _size(0)
{
    *this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] arr;
        _size = other._size;

        if (_size == 0)
            arr = NULL;
        else
        {
            arr = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
            {
                arr[i] = other.arr[i];
            }
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] arr;
}

// throw the exception
template <typename T>
T& Array<T>::operator[](int index)
{
    if (index < 0 || static_cast<unsigned int>(index) >= _size)
    {
        throw std::out_of_range("index out of the range");
    }
    return arr[index];
}

template <typename T>
int Array<T>::size() const
{
    return static_cast<int>(_size);
}