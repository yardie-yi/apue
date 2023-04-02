#include <iostream>
#include <string>
#include <cmath>
#include <unistd.h>

using namespace std;

const int WIDTH = 80; //终端宽度
const int HEIGHT = 25; //终端高度

void fillHeart(char heart[HEIGHT][WIDTH], int x, int y, int size) {
    double distance;
    for (int i = y - size; i <= y; ++i) {
        for (int j = x - size; j <= x + size; ++j) {
            distance = sqrt(pow(j - x, 2) + pow(i - y, 2));
            if (distance <= size && j != x) {
                heart[i][j] = '*'; //填充心形区域
            }
        }
    }

    for (int i = y; i <= y + size; ++i) {
        for (int j = x - size; j <= x + size; ++j) {
            distance = sqrt(pow(j - x, 2) + pow(i - y, 2));
            if (distance <= size && j != x) {
                heart[i][j] = '*'; //填充心形区域
            }
        }
    }
}

void printHeart(char heart[HEIGHT][WIDTH], string name) {
    int x = WIDTH / 2 - name.size() / 2; //计算名字的起始位置
    int y = HEIGHT / 2;
    for (int i = 0; i < name.size(); ++i) {
        heart[y][x + i] = name[i]; //在心形中央打印名字
    }

    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            cout << heart[i][j];
        }
        cout << endl;
    }
}

int main() {
    char heart[HEIGHT][WIDTH];
    string name;
    cout << "请输入你的名字: ";
    cin >> name;

    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            heart[i][j] = ' '; //初始化心形矩阵为空格
        }
    }

    fillHeart(heart, WIDTH / 2, HEIGHT / 2 - 4, 10); //填充心形
    printHeart(heart, name); //在心形中央打印名字

    return 0;
}

