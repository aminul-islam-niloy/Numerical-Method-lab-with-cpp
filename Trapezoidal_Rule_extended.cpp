//Trapezoidal points are given in form of x and y.
#include <bits/stdc++.h>

using namespace std;

class Point
{
public:
    double x;
    double y;

    Point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
};

class Trapezoidal
{
private:
    vector<Point> points;

public:
    Trapezoidal(vector<Point> points)
    {
        this->points = points;
    }

    void solve()
    {
        double h = abs(points[0].x - points[1].x);
        double res = 0;

        for (int i = 1; i < points.size() - 1; i++)
        {
            res += h * points[i].y;
        }

        res += h / 2 * (points[0].y + points[points.size() - 1].y);

        cout << res << endl;
    }
};

int main()
{
    vector<Point> p;
    p.push_back(Point(0, 23));
    p.push_back(Point(0.5, 19));
    p.push_back(Point(1, 14));
    p.push_back(Point(1.5, 11));
    p.push_back(Point(2, 12.5));
    p.push_back(Point(2.5, 16));
    p.push_back(Point(3, 19));
    p.push_back(Point(3.5, 20));
    p.push_back(Point(4, 20));

    Trapezoidal *tz = new Trapezoidal(p);

    tz->solve();

    return 0;
}