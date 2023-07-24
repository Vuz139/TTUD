#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> x;

void printSolution()
{
    for (int i = 0; i < n; i++)
    {
        cout << x[i];
    }
    cout << endl;
}

bool check(int k, int i)
{
    if (x[k - 1] == 0)
        return true;
    else
    {
        if (i == 0)
            return true;
    }
    return false;
}

void backtracking(int k)
{
    for (int i = 0; i <= 1; i++)
    {

        if (check(k, i))
        {
            x[k] = i;
            if (k == n - 1)
            {
                printSolution();
            }
            else
            {
                backtracking(k + 1);
            }
        }
    }
}

int main()
{
    cin >> n;
    x.resize(n + 1);
    for (int i = 0; i <= 1; i++)
    {
        x[0] = i;
        backtracking(1);
    }
}