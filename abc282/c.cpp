#include <iostream>

using namespace std;

int main()
{
    int N;
    string S;

    cin >> N >> S;

    bool in = false;

    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == '"')
        {
            if (in)
                in = false;
            else
                in = true;
        }
        else if (S[i] == ',')
        {
            if (!in)
                S[i] = '.';
        }
    }

    cout << S << endl;

    return 0;
}
