#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define ll long long
#define ME "lzr010506"
using namespace std;

ll n, m;

struct Team
{
    string name;
    int problems;
    int penalty;
};

bool compareTeams(const Team &a, const Team &b)
{
    if (a.problems != b.problems)
        return a.problems > b.problems;
    return a.penalty < b.penalty;
}

vector<Team> contest1(n), contest2(m);

int find_common_teams(const std::vector<Team> &contest1, const std::vector<Team> &contest2)
{
    std::unordered_map<string, int> teamCount;
    int commonCount = 0;

    for (const auto &team : contest1)
    {
        teamCount[team.name]++;
    }

    for (const auto &team : contest2)
    {
        if (teamCount.find(team.name) != teamCount.end())
        {
            commonCount++;
        }
    }
    return commonCount;
}

int main()
{
    cin >> n;
    contest1.resize(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> contest1[i].name >> contest1[i].problems >> contest1[i].penalty; // 46th name, predicted number of solved problems,time penalty
    }
    sort(contest1.begin(), contest1.end(), compareTeams);

    cin >> m;
    contest2.resize(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> contest2[i].name >> contest2[i].problems >> contest2[i].penalty; // 47th name, predicted number of solved problems,time penalty
    }
    sort(contest2.begin(), contest2.end(), compareTeams);

    int common_teams = find_common_teams(contest1, contest2);

    int my_rank_contest1 = distance(contest1.begin(), find_if(contest1.begin(), contest1.end(),
                                                              [&](const Team &team)
                                                              { return team.name == ME; }));

    int my_rank_contest2 = distance(contest2.begin(), find_if(contest2.begin(), contest2.end(),
                                                              [&](const Team &team)
                                                              { return team.name == ME; }));

    if (my_rank_contest1 < my_rank_contest2)
        cout << my_rank_contest1 - common_teams << endl;
    else
        cout << my_rank_contest2 - common_teams << endl;

    return 0;
}