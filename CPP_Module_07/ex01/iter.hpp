#pragma once

#include <iostream>

template<typename T>
void ft_print(T const &c)
{
    std::cout << c;
}

template<typename T>
void iter(T *array, size_t size, void (*f)(T const &))
{
    for (size_t i = 0; i < size; i++)
        f(array[i]);
}
