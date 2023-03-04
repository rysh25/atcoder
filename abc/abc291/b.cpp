#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> X(5 * N);

    for (int i = 0; i < 5 * N; i++)
    {
        cin >> X[i];
    }

    sort(X.begin(), X.end());

    int sum = 0;

    for (int i = 0; i < 5 * N; i++)
    {
        if (i >= N && i < 4 * N)
            sum += X[i];
    }

    cout << sum / (3.0 * N) << endl;

    return 0;
}
