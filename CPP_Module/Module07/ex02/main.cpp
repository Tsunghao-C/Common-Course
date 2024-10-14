#include <iostream>
#include <Array.hpp>
// #include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    /* main test from subject */
    {
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
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
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    }
    /* My tests */
    std::cout << " -------------- Below is my personal tests --------------- " << std::endl;
    Array<std::string>  messages(10);
    for (int i = 0; i < 10; i++) {
        messages[i] = "I am a message ";
        std::stringstream   ss;
        ss << i;
        messages[i].append(ss.str());
    }
    std::cout << "Array size: " << messages.size() << std::endl;
    std::cout << "Array content: " << std::endl << messages;
    return 0;
}