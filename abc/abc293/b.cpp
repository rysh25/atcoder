#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    set<int> called;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        A[i]--;
    }

    for (int i = 0; i < N; i++)
    {
        if (!called.count(i))
            called.insert(A[i]);
    }

    cout << N - called.size() << endl;
    for (int i = 0; i < N; i++)
    {
        if (!called.count(i))
            cout << i + 1 << " ";
    }

    cout << endl;

    return 0;
}
