#include <iostream>

using namespace std;

int a, b, c;
int step;
int v_a, v_b;

void swap(int &j1, int &j2)
{
    int temp = j1;
    j1 = j2;
    j2 = temp;
}

void fill_a()
{
    step++;
    v_a = a;
}

void fill_b()
{
    step++;
    v_b = b;
}

void pour_b_a()
{
    step++;
    if (v_a + v_b > a)
    {

        v_b = (v_b + v_a) - a;
        v_a = a;
    }
    else
    {

        v_a += v_b;
        v_b = 0;
    }
}

void pour_a_b()
{
    step++;
    if (v_a + v_b > b)
    {

        v_a = (v_b + v_a) - b;
        v_b = b;
    }
    else
    {

        v_b += v_a;
        v_a = 0;
    }
}

void empty_a()
{

    step++;
    v_a = 0;
}
void empty_b()
{

    step++;
    v_b = 0;
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
        j1 = j1 % j2;
        swap(j1, j2);
    }

    return j1;
}

void water_jug()
{

    int t = gcd();
    if (c % t != 0)
    {
        step = -1;
        return;
    }
    while (v_a != c && v_b != c)
    {
        if (t == 1)
        {

            if (a < b)
            {
                if (v_a == a)
                    empty_a();
                if (v_b == 0)
                    fill_b();
                if (v_a != a && v_b != 0)
                    pour_b_a();
            }
            else
            {
                if (v_b == b)
                    empty_b();
                if (v_a == 0)
                    fill_a();
                if (v_b != b && v_a != 0)
                    pour_a_b();
            }
        }
        else
        {
            if (a > b)
            {
                if (v_a == a)
                    empty_a();
                if (v_b == 0)
                    fill_b();
                if (v_a != a && v_b != 0)
                    pour_b_a();
            }
            else
            {
                if (v_b == b)
                    empty_b();
                if (v_a == 0)
                    fill_a();
                if (v_b != b && v_a != 0)
                    pour_a_b();
            }
        }
    }
}

int main()
{

    cin >> a >> b >> c;
    step = 0;
    water_jug();
    cout << step;
}