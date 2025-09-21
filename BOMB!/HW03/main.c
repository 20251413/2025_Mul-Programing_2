#include <stdio.h>
#include <math.h>
#include <Windows.h>

#define PI 3.14159226535897

void moveCursor(int x, int y)
{
    printf("\x1b[%d;%dH", y, x);
}

//�Ű����� isExploded
//0: ������ ��ź
//1: ������
void printBomb(int isExploded)
{
    //��ź�� �׻� 7ĭ
    if (isExploded)
    {
        printf("\x1b[A^^^^^^^");
        printf("\x1b[B\x1b[7D!!BAM!!");
        printf("\x1b[B\x1b[7D^^^^^^^");
    }
    else
        printf("(  b  )"); 
}

int main()
{
    // ������� �ڵ带 �ۼ��ϼ���----------------------   
    int path_x[100], path_y[100];
    int x = 14, y = 9;
    int count = 0;
    int length = 2;
    path_x[count] = x;
    path_y[count] = y;
    count++;

    while (length <= 12) {
      
        for (int i = 0; i < length; i++) { y++; path_x[count] = x; path_y[count] = y; count++; }
        for (int i = 0; i < length; i++) { x++; path_x[count] = x; path_y[count] = y; count++; }
        length += 2;
        for (int i = 0; i < length; i++) { y--; path_x[count] = x; path_y[count] = y; count++; }
        for (int i = 0; i < length; i++) { x--; path_x[count] = x; path_y[count] = y; count++; }
        length += 2;
    }
    int fuse_end_x = path_x[count - 1];
    int fuse_end_y = path_y[count - 1];
    int bomb_x = fuse_end_x - 7;
    int bomb_y = fuse_end_y;

    for (int i = 1; i < count; i++) {
        moveCursor(path_x[i], path_y[i]);
        printf("#");
    }

    moveCursor(bomb_x, bomb_y);
    printBomb(0);

    for (int i = 0; i < count; i++) {
        if (i > 0) {
            moveCursor(path_x[i - 1], path_y[i - 1]);
            printf(" ");
        }
        moveCursor(path_x[i], path_y[i]);
        printf("*");
        Sleep(200);
    }
    moveCursor(fuse_end_x, fuse_end_y);
    printf(" ");
    Sleep(200);
    moveCursor(bomb_x, bomb_y);
    printBomb(1);
    // ������� �ڵ带 �ۼ��ϼ���----------------------   
    moveCursor(10, 20);
    return 0;
}
/*�Ӹ��� ���Ŀ�*/