#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WIDTH 70
#define HEIGHT 30

void fill_heart(char heart[HEIGHT][WIDTH], int x, int y, int size);
void print_heart(char heart[HEIGHT][WIDTH], char *name);

int main()
{
    char heart[HEIGHT][WIDTH];
    char *name = "YWM LOVE HJW";

    memset(heart, ' ', sizeof(heart)); // 初始化心形矩阵为空格
    fill_heart(heart, WIDTH / 2, HEIGHT / 2 - 6, 12); // 填充心形
    print_heart(heart, name); // 在心形中打印名字

    return 0;
}

void fill_heart(char heart[HEIGHT][WIDTH], int x, int y, int size)
{
    int i, j;
    double distance;

    for (i = y - size; i <= y; i++)
    {
        for (j = x - size; j <= x + size; j++)
        {
            distance = (j - x) * (j - x) + (i - y) * (i - y);

            if (distance <= size * size && j != x)
            {
                heart[i][j] = '*'; // 填充心形区域
            }
        }
    }

    for (i = y; i <= y + size; i++)
    {
        for (j = x - size; j <= x + size; j++)
        {
            distance = (j - x) * (j - x) + (i - y) * (i - y);

            if (distance <= size * size && j != x)
            {
                heart[i][j] = '*'; // 填充心形区域
            }
        }
    }
}

void print_heart(char heart[HEIGHT][WIDTH], char *name)
{
    int i, j, k, len;
    len = strlen(name);

    // 在心形中央打印名字
    i = HEIGHT / 2 + 2;
    j = (WIDTH - len) / 2;

    for (k = 0; k < len; k++)
    {
        heart[i][j + k] = name[k];
    }

    // 输出心形矩阵
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            putchar(heart[i][j]);
        }
        putchar('\n');
    }
}

