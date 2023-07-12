#include <bits/stdc++.h>

using namespace std;

int a, b, c;
int curr_a = 0, curr_b = 0;
int steps = 0;

void fill_b()
{
    steps++;
    curr_b = b;
}
void fill_a()
{
    steps++;
    curr_a = a;
}
void a_to_b()
{
    steps++;
    if (curr_a + curr_b > b)
    {
        curr_a = curr_a + curr_b - b;
        curr_b = b;
    }
    else
    {
        curr_b = curr_b + curr_a;
        curr_a = 0;
    }
}
void b_to_a()
{
    steps++;
    if (curr_a + curr_b > a)
    {
        curr_b = curr_a + curr_b - a;
        curr_a = a;
    }
    else
    {
        curr_a = curr_b + curr_a;
        curr_b = 0;
    }
}
void empty_a()
{
    steps++;
    curr_a = 0;
}

void empty_b()
{
    steps++;
    curr_b = 0;
}
void swap(int &t1, int &t2)
{
    int temp = t1;
    t1 = t2;
    t2 = temp;
}
int gcd()
{
    int j1 = a, j2 = b;
    if (j1 < j2)
    {
        swap(j1, j2);
    }
    while (j2 != 0)
    {
        j1 %= j2;
        swap(j1, j2);
    }
    return j1;
}

void solve()
{
    cin >> a >> b >> c;
    int gcd_a_b = gcd();
    if (c % gcd_a_b != 0)
    {
        cout << -1;
        return;
    }
    while (curr_a != c && curr_b != c)
    {
        if (gcd_a_b == 1)
        {
            if (a < b)
            {
                if (curr_b == 0)
                {
                    fill_b();
                }
                if (curr_a == a)
                {
                    empty_a();
                }
                if (curr_b != 0 && curr_a != a)
                {
                    b_to_a();
                }
            }
            else
            {
                if (curr_a == 0)
                {
                    fill_a();
                }
                if (curr_b == b)
                {
                    empty_b();
                }
                if (curr_a != 0 && curr_b != b)
                {
                    a_to_b();
                }
            }
        }
        else
        {
            if (a > b)
            {
                if (curr_b == 0)
                {
                    fill_b();
                }
                if (curr_a == a)
                {
                    empty_a();
                }
                if (curr_b != 0 && curr_a != a)
                {
                    b_to_a();
                }
            }
            else
            {
                if (curr_a == 0)
                {
                    fill_a();
                }
                if (curr_b == b)
                {
                    empty_b();
                }
                if (curr_a != 0 && curr_b != b)
                {
                    a_to_b();
                }
            }
        }
    }
    cout << steps;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    solve();
}