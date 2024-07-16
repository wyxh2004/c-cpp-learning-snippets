#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
    double x, y;
};

double distance(Point a, Point b) // 平方距离
{
    return (double)((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
    vector<Point> points(8);
    for (int i = 0; i < points.size(); i++)
        cin >> points[i].x >> points[i].y;

    vector<double> perm = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    do
    {
        if (distance(points[perm[0]], points[perm[1]]) == distance(points[perm[1]], points[perm[2]]) &&
            distance(points[perm[1]], points[perm[2]]) == distance(points[perm[2]], points[perm[3]]) &&
            distance(points[perm[2]], points[perm[3]]) == distance(points[perm[3]], points[perm[0]]) &&
            distance(points[perm[0]], points[perm[2]]) == distance(points[perm[1]], points[perm[3]]) &&
            distance(points[perm[4]], points[perm[5]]) == distance(points[perm[6]], points[perm[7]]) &&
            distance(points[perm[4]], points[perm[6]]) == distance(points[perm[5]], points[perm[7]]) &&
            distance(points[perm[4]], points[perm[7]]) == distance(points[perm[5]], points[perm[6]]))
        {
            cout << "YES" << endl;
            cout << perm[0] + 1 << " " << perm[1] + 1 << " " << perm[2] + 1 << " " << perm[3] + 1 << endl;
            cout << perm[4] + 1 << " " << perm[5] + 1 << " " << perm[6] + 1 << " " << perm[7] + 1 << endl;
            return 0; // 找到合法解后立即返回
        }
    } while (next_permutation(perm.begin(), perm.end()));
    cout << "NO" << endl;
    return 0;
}
