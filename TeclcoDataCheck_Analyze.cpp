#include <bits/stdc++.h>

using namespace std;

map<string, pair<int, int>> call_from; // phoneNo, time-count

long long convertDatetoTime(int hourStart, int minuteStart, int secondSta)
{
    long long res = hourStart * 3600 + minuteStart * 60 + secondSta;
    return res;
}
long long deltaTime(int hourStart, int minuteStart, int secondSta, int hourEnd, int minuteEnd, int secondEnd)
{
    return convertDatetoTime(hourEnd, minuteEnd, secondEnd) - convertDatetoTime(hourStart, minuteStart, secondSta);
}

void insertTelco(string phoneNo1, string phoneNo2, int hourStart, int minuteStart, int secondSta, int hourEnd, int minuteEnd, int secondEnd)
{
    if (call_from.find(phoneNo1) != call_from.end())
    {
        call_from[phoneNo1].first += deltaTime(hourStart, minuteStart, secondSta, hourEnd, minuteEnd, secondEnd);
        call_from[phoneNo1].second += 1;
    }
    else
    {
        call_from[phoneNo1].first = deltaTime(hourStart, minuteStart, secondSta, hourEnd, minuteEnd, secondEnd);
        call_from[phoneNo1].second = 1;
    }
    // cout << call_from[phoneNo1].first << call_from[phoneNo1].second << endl;
}
void totalOfCalls()
{
    int sum = 0;
    for (auto v : call_from)
    {
        sum += v.second.second;
    }
    cout << sum << endl;
}

void solve()
{
    string phoneNo1, phoneNo2;
    int hourStart, minuteStart, secondSta, hourEnd, minuteEnd, secondEnd;
    string date_call;
    string query;

    while (true)
    {
        cin >> query;
        if (query == "call")
        {
            cin >> phoneNo1 >> phoneNo2;
            cin >> date_call;
            scanf("%d:%d:%d", &hourStart, &minuteStart, &secondSta);
            scanf("%d:%d:%d", &hourEnd, &minuteEnd, &secondEnd);
            // cout << hourStart << ":" << minuteStart << ":" << secondSta << endl;
            insertTelco(phoneNo1, phoneNo2, hourStart, minuteStart, secondSta, hourEnd, minuteEnd, secondEnd);
        }
        else
        {
            break;
        }
    }
    while (1)
    {
        cin >> query;
        if (query[0] == '?')
        {
            if (query.substr(1) == "check_phone_number")
            {
                cout << (call_from.size() > 0 ? 1 : 0) << endl;
            }
            else if (query.substr(1) == "number_calls_from")
            {
                cin >> phoneNo1;
                cout << call_from[phoneNo1].second << endl;
            }
            else if (query.substr(1) == "number_total_calls")
            {
                totalOfCalls();
            }
            else if (query.substr(1) == "count_time_calls_from")
            {
                cin >> phoneNo1;
                cout << call_from[phoneNo1].first << endl;
            }
        }
        else if (query == "#")
        {
            break;
        }
    }
}
int main()
{
    freopen("input.inp", "r", stdin);
    solve();
}
