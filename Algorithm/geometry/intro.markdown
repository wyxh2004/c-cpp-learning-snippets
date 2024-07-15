常用库函数
```c
atan2(x, y)  // 返回x/y的反正切值，范围是[-pi, pi]，即点(x, y)的弧度
const double PI = acosl(-1.0);  // PI的值
```
点的表示
```c++
struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    Point operator + (const Point &a) const { return Point(x + a.x, y + a.y); }
    Point operator - (const Point &a) const { return Point(x - a.x, y - a.y); }
    Point operator * (const double &a) const { return Point(x * a, y * a); }
    double operator * (const Point &a) const { return x * a.x + y * a.y; }  // 点积
    double operator ^ (const Point &a) const { return x * a.y - y * a.x; }  // 叉积
    double operator | (const Point &a) const { return sqrt((*this - a) * (*this - a)); }  // 模长
    bool operator < (const Point &a) const { return x < a.x || (x == a.x && y < a.y); }
    bool operator == (const Point &a) const { return x == a.x && y == a.y; }
    bool operator > (const Point &a) const { return x > a.x || (x == a.x && y > a.y); }
};

// int compare(double x)
// {
//     if (x > EPS)
//         return 1;
//     else if (x < EPS)
//         return -1;
//     else
//         return 0;
// }
```