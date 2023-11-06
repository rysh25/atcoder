#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int M;
    cin >> M;
    vector<int> A(M);

    int days = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> A[i];
        days += A[i];
    }

    int mid = days / 2;

    int count = 0;
    for (int i = 0; i < M; i++)
    {
        count += A[i];
        if (count > mid)
        {
            cout << i + 1 << " ";
            cout << mid - (count - A[i]) + 1 << endl;
            return 0;
        }
    }

    return 0;
}
