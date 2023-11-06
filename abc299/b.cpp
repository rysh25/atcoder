#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int N, T;
    cin >> N >> T;
    set<pair<int, int>> st;
    vector<int> C(N);

    bool found = false;
    for (int i = 0; i < N; i++)
    {
        cin >> C[i];
        if (C[i] == T)
            found = true;
    }

    if (!found)
        T = C[0];

    for (int i = 0; i < N; i++)
    {
        int R;
        cin >> R;
        if (C[i] == T)
        {
            st.insert({R, i + 1});
        }
    }

    cout << st.rbegin()->second << endl;

    return 0;
}
