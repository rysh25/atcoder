#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, Q;
string S;

void toLower()
{
    for (int j = 0; j < N; j++)
    {
        if (S[j] >= 'A' && S[j] <= 'Z')
        {
            S[j] += 32;
        }
    }
}

void toUpper()
{
    for (int j = 0; j < N; j++)
    {
        if (S[j] >= 'a' && S[j] <= 'z')
        {
            S[j] -= 32;
        }
    }
}

int main()
{

    map<int, char> m;

    cin >> N;
    cin >> S;
    cin >> Q;

    bool lower = false;
    bool upper = false;

    for (int i = 0; i < Q; ++i)
    {
        int t, x;
        char c;
        cin >> t >> x >> c;
        x--;

        if (t == 1)
        {
            m[x] = c;
            S[x] = c;
        }
        else if (t == 2)
        {
            upper = false;
            lower = true;
            if (m.size() != 0)
            {
                m.clear();
            }
        }
        else if (t == 3)
        {
            upper = true;
            lower = false;
            if (m.size() != 0)
            {
                m.clear();
            }
        }
    }

    if (lower)
    {
        lower = false;
        toLower();
    }
    if (upper)
    {
        upper = false;
        toUpper();
    }

    for (auto ittr = m.begin(); ittr != m.end(); ++ittr)
    {
        S[ittr->first] = ittr->second;
    }

    cout << S << endl;

    return 0;
}
