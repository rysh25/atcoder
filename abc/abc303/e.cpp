#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> degree(N + 1, 0); // 頂点の次数を保存する配列
    for (int i = 0; i < N - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        ++degree[u];
        ++degree[v];
    }

    vector<int> levels; // 星のレベルを保存する配列
    for (int i = 1; i <= N; ++i)
    {
        if (degree[i] > 1)
        { // 次数が2以上のノードが星の中心
            levels.push_back(degree[i] - 1);
        }
    }

    // レベルの昇順ソート
    sort(levels.begin(), levels.end());

    // レベルを空白区切りで出力
    for (int i = 0; i < levels.size(); ++i)
    {
        cout << levels[i] << (i + 1 == levels.size() ? '\n' : ' ');
    }

    return 0;
}
