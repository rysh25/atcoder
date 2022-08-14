#include <iostream>

class Pos
{
public:
    int x;
    int y;

    Pos();
    Pos(int tmpx, int tmpy);
    Pos(const Pos &pos);
};

Pos::Pos() : Pos(0, 0)
{
}

Pos::Pos(int tmpx, int tmpy)
{
    std::cout << "Pos::Pos("
              << "tmpx=" << tmpx << ", tmpy=" << tmpy
              << ")" << std::endl;
    x = tmpx;
    y = tmpy;
}

Pos::Pos(const Pos &pos)
{
    std::cout << "Pos::Pos("
              << "pos.x=" << pos.x << ", pos.y=" << pos.y
              << ")" << std::endl;
    x = pos.x;
    y = pos.y;
}

Pos getPos()
{
    std::cout << "getPos()" << std::endl;
    Pos p;
    std::cout << "p.x: " << p.y << ", p.y: " << p.y << std::endl;
    return p;
}

Pos getPos(Pos pos)
{
    std::cout << "getPos("
              << "pos.x=" << pos.x << ", pos.y=" << pos.y
              << ")" << std::endl;
    return pos;
}

int main()
{
    std::cout << "int main()" << std::endl;
    // Pos posA(100, 200); //  posAに対するコンストラクタ呼び出し

    // Pos posB = posA; //  posBに対するコピーコンストラクタ呼び出し

    // std::cout << "posB.x: " << posB.y << ", posB.y: " << posB.y << std::endl;

    // Pos posC = getPos();
    // Pos posD = posC;

    Pos posE;
    // Pos posF = getPos(posE);

    const Pos &posG = getPos(posE);
    Pos posH = Pos();
    posH.x = 20;
    return 0;
}
