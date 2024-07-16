#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
    int x, y;
};

struct Line
{
    Point start, end;
    int k = (start.x - end.x) / (start.y - end.y);
};

bool cross(Line a, Line b)
{
    return a.k != b.k;
}

bool coincide(Line a, Line b)
{
    return (a.k == b.k && (a.start.x - b.end.x) / (a.start.y - b.end.y) != a.k);
}

bool parallel(Line a, Line b)
{
    return (!cross(a, b) && !coincide(a, b));
}

int main()
{
    int n;
    cin >> n;

    vector<Point> points(4);
    vector<Line> line(2);

    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < line.size() * points.size(); i++)
        {
            cin >> points[i].x >> points[i].y;
            line[1].start = point[]
        }
    }
    cout << "INTERSECTING LINES OUTPUT" << endl;

    for (int i = 0; i < n; i++)
    {
        if (cross)
        {
        }
        if (coincide)
        {
        }
        if (parallel)
        {
        }
    }

    cout << "END OF OUTPUT" << endl;
    return 0;
}