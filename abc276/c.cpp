#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int N;

    cin >> N;

    vector<int> P(N);

    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
    }

    int i = N - 1;
    while (i > 0 && P[i - 1] <= P[i])
        i--;

    int j = i - 1;
    while (j + 1 < N && P[j + 1] < P[i - 1])
        j++;

    swap(P[i - 1], P[j]);

    reverse(P.begin() + i, P.end());

    for (auto &p : P)
        cout << p << " ";

    cout << endl;

    return 0;
}
