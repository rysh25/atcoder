#include <iostream>

class Pos
{
private:
    int x;
    int y;
};

int main()
{
    int *ptr = new int[10];
    delete[] ptr;
    ptr = nullptr;
    delete[] ptr;

    Pos p1;
    Pos *p2 = new Pos();

    delete p2;
    p2 = nullptr;
    delete p2;

    return 0;
}
