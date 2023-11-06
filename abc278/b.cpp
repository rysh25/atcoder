#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int H, M;

    cin >> H >> M;

    if (0 <= H && H < 20)
    {
        if (H % 10 < 6)
        {
            cout << H << " " << M << endl;
        }
        else
        {
            cout << H - (H % 10) + 10 << " 0" << endl;
        }
    }
    else
    {
        if (M < 40)
        {
            cout << H << " " << M << endl;
        }
        else
        {
            if (H < 23)
            {
                cout << H + 1 << " "
                     << "0" << endl;
            }
            else
            {
                cout << "0 0" << endl;
            }
        }
    }

    return 0;
}
