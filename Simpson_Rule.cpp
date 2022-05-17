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

class Simpson
{
private:
    vector<Point> points;
    double high, low;
    int h;

    double f(double x)
    {
        return sqrt(sin(x));
    }

    void make_points()
    {
        double width = (high - low) / h;

        for (int i = 0; i <= h; i++)
        {
            double x = low + i * width;
            double y = f(x);
            points.push_back(Point(x, y));
        }
    }

public:
    Simpson(double high, double low, int h)
    {
        this->high = high;
        this->low = low;
        this->h = h;
    }

    void solve()
    {
        make_points();
        double width = (high - low) / h;
        double res = 0;
        for (int i = 1; i < points.size() - 1; i++)
        {
            if (i % 2 == 0)
                res += 2 * points[i].y;
            else
                res += 4 * points[i].y;
        }

        res += (points[0].y + points[points.size() - 1].y);
        res *= (width / 3);

        cout << res << endl;
    }
};

int main()
{
    Simpson *sim = new Simpson(1, 0, 24);

    sim->solve();

    return 0;
}