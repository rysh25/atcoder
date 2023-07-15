#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

vector<int> BFS(const Graph &G, int s)
{
    int n = (int)G.size();
    vector<int> dist(n, -1);
    queue<int> que;

    dist[s] = 0;
    que.push(s);

    while (!que.empty())
    {
        int v = que.front();
        que.pop();

        for (int x : G[v])
        {
            if (dist[x] != -1)
                continue;
            dist[x] = dist[v] + 1;
            que.push(x);
        }
    }

    return dist;
}

int getDiameter(const Graph &G)
{
    vector<int> dist_s = BFS(G, 0);
    int maxDist = 0, maxPt = 0;
    for (int i = 0; i < dist_s.size(); i++)
    {
        if (dist_s[i] > maxDist)
        {
            maxDist = dist_s[i];
            maxPt = i;
        }
    }
    vector<int> dist_t = BFS(G, maxPt);
    maxDist = 0;
    for (int i = 0; i < dist_t.size(); i++)
    {
        maxDist = max(maxDist, dist_t[i]);
    }
    return maxDist;
}

int main()
{
    int N1, N2, M;
    cin >> N1 >> N2 >> M;
    Graph G1(N1), G2(N2);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        if (b < N1)
        {
            G1[a].push_back(b);
            G1[b].push_back(a);
        }
        else
        {
            G2[a - N1].push_back(b - N1);
            G2[b - N1].push_back(a - N1);
        }
    }
    int D1 = getDiameter(G1);
    int D2 = getDiameter(G2);
    cout << "D1=" << D1 << ", D2=" << D2 << endl;
    cout << D1 + D2 + 1 << endl;

    return 0;
}
