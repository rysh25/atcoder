#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<string> S(N);

    for (int i = 0; i < N; i++)
    {
        cin >> S[i];
    }

    sort(S.begin(), S.begin() + K);

    for (int i = 0; i < K; i++)
    {
        cout << S[i] << endl;
    }

    return 0;
}
