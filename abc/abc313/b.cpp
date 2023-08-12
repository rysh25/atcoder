#include <iostream>
#include <set>

using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;

    set<int> S;

    for (int i = 0; i < N; i++)
    {
        S.insert(i + 1);
    }

    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;

        S.erase(B);
    }

    // cout << S.size() << endl;

    if (S.size() == 1)
    {
        cout << *S.begin() << endl;
        return 0;
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
