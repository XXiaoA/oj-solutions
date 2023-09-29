#include <bits/stdc++.h>
using namespace std;

// 假设地球上的新生资源按恒定速度增长。照此测算，地球上现有资源加上新生资源可供
// x 亿人生活 a 年，或供 y 亿人生活 b 年。
// 为了能够实现可持续发展，避免资源枯竭，地球最多能够养活多少亿人？

// 可持续发展：只用新生资源
// 设单位时间内新生资源q,
// aq - ax = bq - by
// q = （ax − by）/ (a - b)
// 等量关系：现存资源
// 例子：110 90 90 210 -> 75.00

int main(int argc, char *argv[]) {
    double x, a, y, b;
    cin >> x >> a >> y >> b;
    printf("%.2f", (x * a - y * b) / (a - b));

    return 0;
}
