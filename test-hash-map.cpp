#include "hash-map.h"
#include <iostream>
#include <ctime>
int main()
{
    srand(time(NULL));
    HashMap<int, int> test;
    test.insert(1435, 123);
    test.insert(4535435, 123);
    test.insert(23858, 123);
    test.insert(2346345, 123123);
    std::cout << "coef = " << test.getCoef() << " amountElements = " << test.getSize() << std::endl;
    test.setCoef(0.2);
    test.insert(1439756, 994323);
    test.insert(734573, 129293423);
    test.insert(8335463, 1223423);
    std::cout << test[2346345] << std::endl;
    std::cout << "coef = " << test.getCoef() << " amountElements = " << test.getSize() << std::endl;
    test.print();
    test.del(23858);
    std::cout << "coef = " << test.getCoef() << " amountElements = " << test.getSize() << std::endl;
    std::cout << "___________\n";
    test.print();
    for (int i = 0; i < 100000; i++)
    {
        test.insert(rand() % 100000000, 9999);
    }
    test.print();
    std::cout << test[2346345] << std::endl;
    std::cout << "coef = " << test.getCoef() << " amountElements = " << test.getSize() << std::endl;
    test.setCoef(1.99);
    std::cout << "coef = " << test.getCoef() << " amountElements = " << test.getSize() << std::endl;
    test.print();

    return 0;
}