#include <iostream>

int main()
{
    float f = 10.1;
    int i = f;

    f = i;

    std::cout << i << std::endl;

    return 0;
}
