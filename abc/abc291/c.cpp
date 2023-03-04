#include <iostream>
#include <set>

using namespace std;

int main()
{
    int N;

    cin >> N;

    set<pair<int, int>> visited{{0, 0}};

    int x = 0, y = 0;

    bool res = false;
    for (int i = 0; i < N; i++)
    {
        char s;
        cin >> s;
        switch (s)
        {
        case 'R':
            x += 1;
            break;
        case 'L':
            x -= 1;
            break;
        case 'U':
            y -= 1;
            break;
        case 'D':
            y += 1;
            break;
        }

        if (visited.count({x, y}))
        {
            cout << "Yes" << endl;
            return 0;
        }

        visited.insert({x, y});
    }

    cout << "No" << endl;

    return 0;
}
