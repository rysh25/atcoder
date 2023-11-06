// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

bool dfs(const vector<vector<int>> &G, vector<bool> &visited, deque<int> &path, int now, int pre, int goal)
{
    visited[now] = true;
    // cout << "now: " << now + 1 << endl;

    if (now == goal)
    {
        // cout << now + 1;
        path.push_front(now);
        return true;
    }

    for (auto &next : G[now])
    {
        // cout << "next: " << next + 1 << endl;
        if (!visited[next])
        {
            if (dfs(G, visited, path, next, now, goal))
            {
                // cout << " " << now + 1;
                path.push_front(now);
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int N, X, Y;
    // vector<int> U(N - 1), V(N - 1);
    cin >> N >> X >> Y;

    vector<vector<int>> G(N, vector<int>());
    vector<bool> visited(N, false);
    deque<int> path;

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        // cout << "u: " << u << ", v: " << v << endl;

        G[u - 1].push_back(v - 1);
        G[v - 1].push_back(u - 1);
    }

    dfs(G, visited, path, X - 1, -1, Y - 1);

    for (auto &p : path)
    {
        cout << p + 1 << " ";
    }

    cout << endl;

    return 0;
}
