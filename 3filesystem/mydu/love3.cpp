#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h> // 包含sleep函数的头文件

using namespace std;

void printHeart(int x, int y) {
    const int n = 30; // 爱心的大小
    for (int i = n/2; i <= n; i+=2) {
        for (int j = 1; j < n-i; j += 2) {
            cout << " ";
        }

        for (int j = 1; j <= i; j++) {
            cout << "\033[1;31m"; // 设置颜色为红色
            cout << "*";
            cout << "\033[0m"; // 恢复默认颜色
        }

        for (int j = 1; j <= n-i; j++) {
            cout << " ";
        }

        for (int j = 1; j <= i; j++) {
            cout << "\033[1;31m"; // 设置颜色为红色
            cout << "*";
            cout << "\033[0m"; // 恢复默认颜色
        }

        cout << endl;
    }

    for (int i = n; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            cout << " ";
        }

        for (int j = 1; j <= ((i * 2) - 1); j++) {
            if ((i > n/2) && (j == 1 || j == ((i * 2) - 1))) {
                cout << "\033[1;31m"; // 设置颜色为红色
                cout << "*";
                cout << "\033[0m"; // 恢复默认颜色
            } else {
                cout << " ";
            }
        }

        cout << endl;
    }

    cout << "\033[" << y << ";" << x << "H"; // 将光标移动到(x,y)位置
}

int main() {
    srand(time(NULL)); // 设置随机数种子

    const int width = 80; // 终端窗口的宽度
    const int height = 20; // 终端窗口的高度

    int x = width / 2;
    int y = height / 2;

    while (true) {
        system("clear"); // 清屏

        printHeart(x, y);

        if (x == width / 2 && y == height / 2) {
            cout << "\033[33m"; // 设置颜色为黄色
            cout << "I love you forever!"; // 输出表白语句
            cout << "\033[0m"; // 恢复默认颜色
        }

        int dx = rand() % 3 - 1; // 随机生成-1,0,1
        int dy = rand() % 3 - 1; // 随机生成-1,0,1

        x += dx;
        y += dy;

        x = max(0, min(x, width - 1));
        y = max(0, min(y, height - 1));

        usleep(100000); // 暂停100毫秒
    }

    return 0;
}

