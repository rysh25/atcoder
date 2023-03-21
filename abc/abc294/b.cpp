#include <iostream>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int a;
            cin >> a;
            if (a == 0)
                cout << ".";
            else
                cout << (char)('A' + a - 1);
        }
        cout << endl;
    }

    cout << endl;

    return 0;
}
