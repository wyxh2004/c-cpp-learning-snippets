#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
    int x, y;
};

bool check(Point a, Point b) // 检查点是否重合
{
    return (a.x == b.x && a.y == b.y);
}
bool right(Point a, Point b, Point c)
{
    int _ab = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    int _ac = (a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y);
    int _bc = (b.x - c.x) * (b.x - c.x) + (b.y - c.y) * (b.y - c.y);
    return (_ab + _ac == _bc || _ab + _bc == _ac || _ac + _bc == _ab);
}

bool almost(Point a, Point b, Point c)
{
    return (!check(Point{a.x + 1, a.y}, b) && !check(Point{a.x + 1, a.y}, c) && right(Point{a.x + 1, a.y}, b, c)) ||
           (!check(Point{a.x - 1, a.y}, b) && !check(Point{a.x - 1, a.y}, c) && right(Point{a.x - 1, a.y}, b, c)) ||
           (!check(a, Point{b.x + 1, b.y}) && !check(c, Point{b.x + 1, b.y}) && right(a, Point{b.x + 1, b.y}, c)) ||
           (!check(a, Point{b.x - 1, b.y}) && !check(c, Point{b.x - 1, b.y}) && right(a, Point{b.x - 1, b.y}, c)) ||
           (!check(a, b) && !check(Point{c.x + 1, c.y}, b) && right(a, b, Point{c.x + 1, c.y})) ||
           (!check(a, b) && !check(Point{c.x - 1, c.y}, b) && right(a, b, Point{c.x - 1, c.y})) ||
           (!check(Point{a.x, a.y + 1}, b) && !check(Point{a.x, a.y + 1}, c) && right(Point{a.x, a.y + 1}, b, c)) ||
           (!check(Point{a.x, a.y - 1}, b) && !check(Point{a.x, a.y - 1}, c) && right(Point{a.x, a.y - 1}, b, c)) ||
           (!check(a, Point{b.x, b.y + 1}) && !check(c, Point{b.x, b.y + 1}) && right(a, Point{b.x, b.y + 1}, c)) ||
           (!check(a, Point{b.x, b.y - 1}) && !check(c, Point{b.x, b.y - 1}) && right(a, Point{b.x, b.y - 1}, c)) ||
           (!check(a, b) && !check(Point{c.x, c.y + 1}, b) && right(a, b, Point{c.x, c.y + 1})) ||
           (!check(a, b) && !check(Point{c.x, c.y - 1}, b) && right(a, b, Point{c.x, c.y - 1}));
}

int main()
{

    vector<Point> p(3);
    for (int i = 0; i < 3; i++)
        cin >> p[i].x >> p[i].y;

    if (check(p[0], p[1]) || check(p[0], p[2]) || check(p[1], p[2]))
        cout << "NEITHER";
    else if (right(p[0], p[1], p[2]))
        cout << "RIGHT";
    else if (almost(p[0], p[1], p[2]))
        cout << "ALMOST";
    else
        cout << "NEITHER";

    return 0;
}