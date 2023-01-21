#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int N;
    cin >> N;
    set<string> S;
    vector<string> T;

    for (int i = 0; i < N; i++)
    {
        string s, t;
        cin >> s >> t;
        S.insert(s);
        T.emplace_back(t);
    }

    for (int i = 0; i < N; i++)
    {
        T[i]
    }

    return 0;
}
