#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // 包含sleep函数的头文件

int main() {
    srand(time(NULL)); // 设置随机数种子

    const int width = 80; // 终端窗口的宽度
    const int height = 20; // 终端窗口的高度

    int x = width / 2;
    int y = height / 2;

    while (1) {
        system("clear"); // 清屏

        for (int i = 0; i < y; i++) {
            printf("\n");
        }

        for (int i = 0; i < x; i++) {
            printf(" ");
        }

        printf("\033[31m"); // 设置颜色为红色
        printf("I love you forever!"); // 输出表白语句
        printf("\033[0m"); // 恢复默认颜色

        printf("\n");

        int dx = rand() % 3 - 1; // 随机生成-1,0,1
        int dy = rand() % 3 - 1; // 随机生成-1,0,1

        x += dx;
        y += dy;

        x = x < 0 ? 0 : (x > width ? width : x);
        y = y < 0 ? 0 : (y > height ? height : y);

        usleep(100000); // 暂停100毫秒
    }

    return 0;
}

