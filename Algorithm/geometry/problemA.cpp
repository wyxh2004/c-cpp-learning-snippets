// #include <iostream>
// #include <cmath>
// #include <vector>
// #include <algorithm>

// const double EPS = 1e-9;

// using namespace std;

// struct Point
// {
//     double x, y;
//     Point() {}
//     Point(double x, double y) : x(x), y(y) {}
//     Point operator+(const Point &a) const { return Point(x + a.x, y + a.y); }
//     Point operator-(const Point &a) const { return Point(x - a.x, y - a.y); }
//     Point operator*(const double &a) const { return Point(x * a, y * a); }
//     double operator*(const Point &a) const { return x * a.x + y * a.y; }               // 点积
//     double operator^(const Point &a) const { return x * a.y - y * a.x; }               // 叉积
//     double operator|(const Point &a) const { return sqrt((*this - a) * (*this - a)); } // 模长
//     bool operator<(const Point &a) const { return x < a.x || (x == a.x && y < a.y); }
//     bool operator==(const Point &a) const { return x == a.x && y == a.y; }
//     bool operator>(const Point &a) const { return x > a.x || (x == a.x && y > a.y); }
// };

// bool cmp(const Point &a, const Point &b)
// {
//     if (a.x == b.x)
//         return a.y < b.y;
//     return a.x < b.x;
// }

// bool ccw(const Point &a, const Point &b, const Point &c)
// {
//     // 对于二维向量 a 和 b，它们的叉积可以简化为 a1b2 - a2b1
//     // 计算 ab和 ac的叉积，大于0，逆时针，否则顺时针
//     return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) > 0;
// }

// vector<Point> convexHull(vector<Point> p) // 返回凸包上的点
// {
//     sort(p.begin(), p.end(), cmp); // 按照x坐标排序
//     vector<Point> hull;            // 存储凸包上的点
//     for (int i = 0; i < p.size(); i++)
//     {
//         while (hull.size() >= 2 && !ccw(hull[hull.size() - 2], hull[hull.size() - 1], p[i]))
//             hull.pop_back();
//         hull.push_back(p[i]);
//     }
//     for (int i = p.size() - 2, t = hull.size() + 1; i >= 0; i--)
//     {
//         while (hull.size() >= t && !ccw(hull[hull.size() - 2], hull[hull.size() - 1], p[i]))
//         {
//             hull.pop_back();
//         }
//     }
// }

// int main()
// {
//     int n;
//     vector<Point> p;
//     while (cin >> n)
//     {
//         int x, y;
//         for (int i = 0; i < n; i++)
//             cin >> x >> y, p.push_back(Point(x, y));
//     }

//     vector<Point> ans = convexHull(p);

//     return 0;
// }

#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
    }
    cout << (n - 4) / 2;
    return 0;
}