#include <bits/stdc++.h>

using namespace std;

int digits[7];
int numOfTests;
int n;
int COUNTER = 0;
int geted[7];

void getALl()
{
    for (int i = 0; i < 7; i++)
    {
        cout << digits[i] << " ";
    }
    cout << endl;
}

void resolve()
{
    int T = digits[0], S = digits[1], U = digits[2], H = digits[3], O = digits[4], I = digits[5], C = digits[6];
    int HUST = H * 1000 + U * 100 + S * 10 + T;
    int SOICT = S * 10000 + O * 1000 + I * 100 + C * 10 + T;
    if (HUST + SOICT == n)
    {
        getALl();
        COUNTER++;
    }
}

void TRY(int i)
{
    for (int j = 0; j < 10; j++)
    {
        if (geted[j] == 0)
        {

            geted[j] = 1;
            digits[i] = j;
            if (i == 6)
            {
                resolve();
            }
            else
            {
                TRY(i + 1);
            }
            geted[j] = 0;
        }
    }
}

int main()
{

    // cin >> n;
    n = 17868;
    digits[0] = 4;
    digits[1] = 1;
    geted[1] = 1;
    geted[4] = 1;
    TRY(2);
    cout << COUNTER;
    // for (int i = 0; i < numOfTests; i++)
    // {
    //     cin >> n;

    //     for (int j = 0; j < 7; j++)
    //     {
    //         geted[j] = 0;
    //     }
    //     TRY(0);
    //     cout << COUNTER << endl;
    //     COUNTER = 0;
    // }
}
