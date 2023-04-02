#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL)); // 设置随机数种子

    int n = 50; // 爱心的大小
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
            int r = rand() % 2; // 随机生成0或1，用于输出空格或*
            if (r == 0) {
                cout << " ";
            } else {
                cout << "\033[1;31m"; // 设置颜色为红色
                cout << "*";
                cout << "\033[0m"; // 恢复默认颜色
            }
        }

        cout << endl;
    }

    return 0;
}
