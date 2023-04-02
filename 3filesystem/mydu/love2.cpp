#include <iostream>
#include <cmath>

using namespace std;

int main() {
    const int n = 60; // 玫瑰的大小

    for (float i = 0; i < n; i += 0.5) {
        float theta = i / n * 2 * M_PI; // 计算角度
        float r = sin(4 * theta) * cos(2 * theta); // 计算极径

        int x = r * cos(theta) * n + n / 2;
        int y = r * sin(theta) * n + n / 2;

        cout << "\033[" << y << ";" << x << "H"; // 将光标移动到(x,y)位置
        cout << "*"; // 输出一个点
    }

    cout << endl;
    return 0;
}
