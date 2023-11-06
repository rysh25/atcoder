#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int H, W;

    cin >> H >> W;

    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<int>> visited(H, vector<int>(W, false));

    set<int> st;

    for (int h = 0; h < H; h++)
    {
        for (int w = 0; w < W; w++)
        {
            cin >> A[h][w];
        }
    }

    int res = 0;

    auto dfs = [&](auto dfs, int c, int ch, int cw) -> bool
    {
        // cout << "c=" << c << ", (" << ch << ", " << cw << ")" << endl;

        st.insert(A[ch][cw]);

        if (c + 1 != st.size())
        {
            // cout << "no: c=" << c << ", (" << ch << ", " << cw << ")" << endl;
            return false;
        }

        if (ch == H - 1 && cw == W - 1)
        {
            // cout << "goal: c=" << c << ", (" << ch << ", " << cw << ")" << endl;
            res++;
            st.erase(A[ch][cw]);
            return true;
        }

        if (ch + 1 < H && !visited[ch + 1][cw])
        {
            dfs(dfs, c + 1, ch + 1, cw);
        }

        if (cw + 1 < W && !visited[ch][cw + 1])
        {
            dfs(dfs, c + 1, ch, cw + 1);
        }

        st.erase(A[ch][cw]);
        return true;
    };

    dfs(dfs, 0, 0, 0);

    cout << res << endl;

    return 0;
}
