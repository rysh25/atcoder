#include <iostream>
#include <vector>

using namespace std;

int main()
{

    for (int i = 0; i < 8; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < 8; j++)
        {
            if (s[j] == '*')
            {
                cout << (char)('a' + j) << 8 - i << endl;
            }
        }
    }

    return 0;
}
