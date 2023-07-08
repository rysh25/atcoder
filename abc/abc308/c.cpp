#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Player
{
    ll a, b, idx;
};

int main()
{

    int N;
    cin >> N;

    vector<Player> players(N);

    for (int i = 0; i < N; i++)
    {
        cin >> players[i].a >> players[i].b;
        players[i].idx = i + 1;
    }

    sort(players.begin(), players.end(), [](const Player &x, const Player &y)
         {
        if(x.a * (y.a + y.b) != y.a * (x.a + x.b)) {
            return x.a * (y.a + y.b) > y.a * (x.a + x.b);
        } else {
            return x.idx < y.idx;
        } });

    for (const auto &player : players)
    {
        cout << player.idx << " ";
    }

    cout << endl;

    return 0;
}
