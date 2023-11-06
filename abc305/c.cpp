#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int H, W;

    cin >> H >> W;

    vector<string> S;

    for (int i = 0; i < H; i++)
    {
        string s;
        cin >> s;
        S.emplace_back(s);
    }

    int min_h = 510;
    int min_w = 510;
    int max_h = 0;
    int max_w = 0;

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (S[i][j] == '#')
            {
                min_h = min(min_h, i);
                min_w = min(min_w, j);
                max_h = max(max_h, i);
                max_w = max(max_w, j);
            }
        }
    }

    for (int i = min_h; i <= max_h; i++)
    {
        for (int j = min_w; j <= max_w; j++)
        {
            if (S[i][j] == '.')
            {
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }

    return 0;
}
