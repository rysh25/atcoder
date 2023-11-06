#include <iostream>

using namespace std;

int main()
{
    string S;

    cin >> S;

    int res = 0;
    for (auto &c : S)
    {
        switch (c)
        {
        case 'w':
            res += 2;
            break;
        case 'v':
            res += 1;
            break;
        }
    }

    cout << res << endl;

    return 0;
}
