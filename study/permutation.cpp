#include <iostream>
#include <vector>

using namespace std;

void print_perm(vector<int> &prem)
{
    for (int i = 0; i < prem.size(); i++)
        printf("%d ", prem[i]);
    printf("\n");
}

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void rotate(vector<int> &a, int s, int e)
{
    // cout << "rotate s=" << s << ", e=" << e << endl;
    // cout << "before rotate: ";
    // print_perm(a);

    int t = a[e];
    for (int j = e; j > s; j--)
        a[j] = a[j - 1];
    a[s] = t;

    // cout << "alter rotate: ";
    // print_perm(a);
}

void rotate_r(vector<int> &a, int s, int e)
{
    int t = a[s];
    for (int j = s; j < e; j++)
        a[j] = a[j + 1];
    a[e] = t;
}

void permutation(vector<int> &a, int l)
{
    if (l == a.size() - 1)
    {
        print_perm(a);
        return;
    }

    for (int i = l; i < a.size(); i++)
    {
        swap(a[l], a[i]);
        // rotate(a, l, i);

        permutation(a, l + 1);

        swap(a[l], a[i]);
        // rotate_r(a, l, i);
    }
}

int main()
{
    vector<int> a{1, 2, 3};
    // print_perm(a);
    permutation(a, 0);
}
