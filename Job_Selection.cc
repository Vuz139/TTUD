#include <bits/stdc++.h>

using namespace std;

const int MAX_ = 1e5 + 1;

struct Job
{
    int deadline;
    int profit;
};

int n;
vector<Job> jobs;
vector<bool> filled;
void greedy()
{
    int result = 0;
    for (Job j : jobs)
    {
        for (int jj = min(j.deadline, n) - 1; jj >= 0; jj--)
        {
            if (!filled[jj])
            {
                filled[jj] = true;
                result += j.profit;
                break;
            }
        }
    }
    cout << result << endl;
}
bool compare(Job &x, Job &y)
{
    return x.profit > y.profit;
}

void solve()
{
    cin >> n;
    jobs.resize(n + 1);
    filled.resize(n + 1, false);
    for (int i = 0; i < n; i++)
    {
        cin >> jobs[i].deadline;
        cin >> jobs[i].profit;
    }

    sort(jobs.begin(), jobs.begin() + n, compare);

    greedy();
}
int main()
{
    // freopen("input.inp", "r", stdin);
    solve();
}