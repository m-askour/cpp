#pragma once

template <typename T>
Array<T>::Array()
    : array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n)
    : array(new T[n]), _size(n)
{
}

template <typename T>
Array<T>::Array(const Array &other)
    : array(NULL), _size(other._size)
{
    if (_size > 0)
    {
        array = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            array[i] = other.array[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        T *tmp = NULL;
        if (other._size > 0)
        {
            tmp = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                tmp[i] = other.array[i];
        }
        delete[] array;
        array = tmp;
        _size = other._size;
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] array;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw OutOfBound();
    return array[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw OutOfBound();
    return array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

template <typename T>
const char *Array<T>::OutOfBound::what() const throw()
{
    return "Index out of bounds";
}