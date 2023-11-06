#include <iostream>
#include <vector>

using namespace std;

int Ha, Wa, Hb, Wb, Hx, Wx;

bool is_valid(int i, int j, int H, int W, vector<vector<char>> S, vector<vector<char>> X)
{
    if (i < 0 || i + H > Hx || j < 0 || j + W > Wx)
        return false;
    for (int p = 0; p < H; ++p)
    {
        for (int q = 0; q < W; ++q)
        {
            if (S[p][q] == '#' && X[i + p][j + q] == '#')
                return false;
            if (S[p][q] == '#' && X[i + p][j + q] == '.')
                X[i + p][j + q] = '#';
        }
    }
    return true;
}

int main()
{

    cin >> Ha >> Wa;
    vector<vector<char>> A(Ha, vector<char>(Wa));
    for (int i = 0; i < Ha; i++)
    {
        for (int j = 0; j < Wa; j++)
        {
            cin >> A[i][j];
        }
    }

    cin >> Hb >> Wb;
    vector<vector<char>> B(Hb, vector<char>(Wb));
    for (int i = 0; i < Hb; i++)
    {
        for (int j = 0; j < Wb; j++)
        {
            cin >> B[i][j];
        }
    }

    cin >> Hx >> Wx;
    vector<vector<char>> X(Hx, vector<char>(Wx));
    for (int i = 0; i < Hx; i++)
    {
        for (int j = 0; j < Wx; j++)
        {
            cin >> X[i][j];
        }
    }

    vector<vector<char>> C(Hx + Ha + Hb, vector<char>(Wx + Wa + Wb));
    // cout << "Ha=" << Ha << " Wa=" << Wa << " Hb=" << Hb << " Wb=" << Wb << endl;
    // cout << "Ha+Hb=" << Ha + Hb << " Wa+Wb=" << Wa + Wb << endl;
    for (int i = 0; i <= Ha; i++)
    {
        for (int j = 0; j <= Wa; j++)
        {
            for (int p = 0; p < Hx + Ha + Hb; p++)
            {
                for (int q = 0; q < Wx + Wa + Wb; q++)
                {
                    C[p][q] = '.';
                }
            }

            for (int p = 0; p < Ha; p++)
            {
                for (int q = 0; q < Wa; q++)
                {
                    C[Hx + p][Wx + q] = A[p][q];
                }
            }

            for (int p = 0; p < Hb; p++)
            {
                for (int q = 0; q < Wb; q++)
                {
                    // cout << "i=" << i << " j=" << j << " p=" << p << " q=" << q << endl;
                    // cout << "i+p=" << i + p << " j+q=" << j + q << endl;
                    // cout << "C[i+p][j+q]=" << C[i + p][j + q] << endl;
                    // cout << " B[p][q]=" << B[p][q] << endl;
                    if (C[Hx + i + p][Wx + j + q] != '#')
                        C[Hx + i + p][Wx + j + q] = B[p][q];
                }
            }

            // cout << "C:" << endl;
            // for (int p = 0; p < Ha + Hb; p++)
            // {
            //     for (int q = 0; q < Wa + Wb; q++)
            //     {
            //         cout << C[p][q];
            //     }
            //     cout << endl;
            // }
            // return 0;
        }
    }

    for (int i = 0; i < Hx * 2; i++)
    {
        for (int j = 0; j < Wx * 2; j++)
        {
            if (is_valid(i, j, Ha, Wa, C, X))
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
