#include <iostream>
#include <map>

using namespace std;

int main()
{
    int N, M, H, K;

    cin >> N >> M >> H >> K;

    string S;

    cin >> S;
    map<pair<int, int>, bool> item;

    // cout << "start" << endl;
    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        item[make_pair(x, y)] = true;
    }

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    // cout << "start" << endl;

    pair<int, int> cur = make_pair(0, 0);
    for (int i = 0; i < N; i++)
    {
        // cout << "S[i]: " << S[i] << endl;
        if (S[i] == 'R')
        {
            cur.first += dx[0];
            cur.second += dy[0];
        }
        else if (S[i] == 'L')
        {
            cur.first += dx[1];
            cur.second += dy[1];
        }
        else if (S[i] == 'U')
        {
            cur.first += dx[2];
            cur.second += dy[2];
        }
        else if (S[i] == 'D')
        {
            cur.first += dx[3];
            cur.second += dy[3];
        }

        H--;

        // cout << "x: " << cur.first << ", y: " << cur.second << endl;
        // cout << "H: " << H << endl;
        // cout << "Found item: " << item[make_pair(cur.first, cur.second)] << endl;

        if (H < 0)
        {
            cout << "No" << endl;
            return 0;
        }

        if (H < K &&
            item[make_pair(cur.first, cur.second)])
        {
            H = K;
            // cout << "Use item" << endl;
            // cout << "H: " << H << endl;
            item[make_pair(cur.first, cur.second)] = false;
        }
    }

    cout << "Yes" << endl;

    return 0;
}
