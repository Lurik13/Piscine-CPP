#include "Array.hpp"
#include "Array.tpp"

#define MAX_VAL 13 //
int main(void)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % 100; //
        numbers[i] = value;
        mirror[i] = value;
    }
	numbers.printArray(); //
	std::cout << "size = " << numbers.size() << std::endl; //
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(std::runtime_error &e) //
    {
        std::cerr << "\e[38;2;170;0;0;1m" << e.what() << "\e[0m\n"; //
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(std::runtime_error &e) //
    {
        std::cerr << "\e[38;2;170;0;0;1m" << e.what() << "\e[0m\n"; //
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand() % 100; //
    }
	numbers.printArray(); //
    delete [] mirror;
    return 0;
}
