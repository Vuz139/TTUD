#include <iostream>

using namespace std;

int n;
int x[21];

void print_sol()
{
    for (int i = 0; i < n; i++)
    {
        cout << x[i];
    }
    cout << endl;
}

void generate_binary(int i)
{
    if (x[i - 1] == 1)
    {
        x[i] = 0;
        if (i == n - 1)
            print_sol();
        else
        {
            generate_binary(i + 1);
        }
    }
    else
    {

        for (int j = 0; j <= 1; j++)
        {
            x[i] = j;
            if (i == n - 1)
                print_sol();
            else
            {
                generate_binary(i + 1);
            }
        }
    }
}

int main()
{
    cin >> n;
    if (n < 1)
        return 1;
    generate_binary(0);
}