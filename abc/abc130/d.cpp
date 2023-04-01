#include <iostream>
#include <vector>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)

int main()
{
    int N;
    long long K;
    cin >> N >> K;

    vector<int> a(N);

    rep(i, N) cin >> a[i];

    long long res = 0;

    int left = 0;
    int right = left + 1;
    long long sum = a[0];
    while (true)
    {
        // cout << "left=" << left << ", right=" << right << ", a[" << right << "]=" << a[right - 1] << ", sum=" << sum << endl;
        if (sum >= K)
        {
            res += N - (right - 1);
            sum -= a[left];
            left++;
        }
        else
        {
            if (right >= N)
                break;
            sum += a[right];
            right++;
        }
    }

    cout << res << endl;

    return 0;
}
