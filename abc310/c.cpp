#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    int N;
    cin >> N;

    set<string> strings;

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        string reversed_s = s;
        reverse(reversed_s.begin(), reversed_s.end());

        strings.insert(min(s, reversed_s));
    }

    cout << strings.size() << endl;

    return 0;
}
