#include <iostream>

#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


#define PI 3.14159265358979323846

struct Point {
    double x, y;
};

// 旋转向量 (dx, dy) 60度
pair<double, double> rotate60(double dx, double dy) {
    double theta =PI/ 3.0;
    double cosTheta = cos(theta);
    double sinTheta = sin(theta);
    return {dx * cosTheta - dy * sinTheta, dx * sinTheta + dy * cosTheta};
}

// 递归生成科赫曲线的点
void kochCurve(int depth, Point p1, Point p2, vector<Point>& points) {
    if (depth == 0) {
        points.push_back(p1);
        return;
    }

    double dx = (p2.x - p1.x) / 3.0;
    double dy = (p2.y - p1.y) / 3.0;

    Point s = {p1.x + dx, p1.y + dy};
    Point t = {p2.x - dx, p2.y - dy};

    auto [rotatedX, rotatedY] = rotate60(dx, dy);
    Point u = {s.x + rotatedX, s.y + rotatedY};

    kochCurve(depth - 1, p1, s, points);
    kochCurve(depth - 1, s, u, points);
    kochCurve(depth - 1, u, t, points);
    kochCurve(depth - 1, t, p2, points);
}

int main() {
    int n;
    cin >> n;

    vector<Point> points;
    Point p1 = {0, 0};
    Point p2 = {100, 0};

    kochCurve(n, p1, p2, points);
    points.push_back(p2); // 添加最后一个点

    // 输出所有点的坐标
    for (const auto& point : points) {
        cout.precision(8);
        cout << fixed << point.x << " " << point.y << endl;
    }

    return 0;
}    