#include <iostream>
#include "strutil.h"

char
    originalString[100] = {0},
    strToSearch[100] = {0};

int main()
{
    std::cin >> strToSearch >> originalString;
    std::cout << strConteins(strToSearch, originalString) << std::endl;
}
