#include <bits/stdc++.h>

using namespace std;

time_t stringToTimestamp(const string &dateString)
{
    tm timeStruct = {};
    istringstream iss(dateString);

    iss >> get_time(&timeStruct, "%Y-%m-%d %H:%M:%S");
    time_t timestamp = mktime(&timeStruct);

    return timestamp;
}

string timestampToString(time_t timestamp)
{
    tm *timeStruct = localtime(&timestamp);
    ostringstream oss;

    oss << put_time(timeStruct, "%Y-%m-%d %H:%M:%S");
    string dateString = oss.str();

    return dateString;
}

int main()
{
    freopen("input.inp", "r", stdin);

    string day;

    while (getline(cin, day) && day != "*")
    {
    }

    vector<pair<string, int>> tasks;
    string taskString;

    while (getline(cin, taskString) && taskString != "***")
    {
        istringstream iss(taskString);
        string startingTime;
        int duration;

        if (iss >> startingTime >> duration)
        {
            tasks.push_back({startingTime, duration});
        }
    }

    for (const auto &task : tasks)
    {
        time_t startingTimestamp = stringToTimestamp(task.first);
        time_t finishingTimestamp = startingTimestamp + task.second;
        string finishingTime = timestampToString(finishingTimestamp);

        cout << finishingTime << endl;
    }

    return 0;
}
