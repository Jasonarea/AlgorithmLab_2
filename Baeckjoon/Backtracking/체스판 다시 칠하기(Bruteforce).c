#include <stdio.h>
#include <limits.h>
#define W    1
#define B   0
#define MIN(a, b)   (a>b)?b:a

int map1[8][8] = {
        {W, B, W, B, W, B, W, B},
        {B, W, B, W, B, W, B, W},
        {W, B, W, B, W, B, W, B},
        {B, W, B, W, B, W, B, W},
        {W, B, W, B, W, B, W, B},
        {B, W, B, W, B, W, B, W},
        {W, B, W, B, W, B, W, B},
        {B, W, B, W, B, W, B, W}
};

int map2[8][8] = {
        {B, W, B, W, B, W, B, W},
        {W, B, W, B, W, B, W, B},
        {B, W, B, W, B, W, B, W},
        {W, B, W, B, W, B, W, B},
        {B, W, B, W, B, W, B, W},
        {W, B, W, B, W, B, W, B},
        {B, W, B, W, B, W, B, W},
        {W, B, W, B, W, B, W, B}
};

char originalMap[51][51];


int checkCount(int row, int col) {
    int count = 0, count1 = 0;

    for(int i = row;i<row + 8;i++) {
        for(int j = col;j<col + 8;j++) {
            int Origin = originalMap[i][j]=='W'?W:B;
            int Origin2 = Origin;
            if(Origin != map1[i - row][j - col]) count++;
            if(Origin2 != map2[i - row][j - col]) count1++;
        }
    }

    return MIN(count, count1);
}

int main(void)
{
    int w, h;
    scanf("%d %d", &h, &w);

    char c;

    for(int i = 0;i<h;i++) {
        scanf("%c", &c);
        for(int j = 0;j<w;j++)
            scanf("%c", &originalMap[i][j]);
    }

    int ans = INT_MAX;
    for(int i = 0;i<=h - 8;i++) {
        for(int j = 0;j<=w - 8;j++) {
            int temp = checkCount(i, j);
            ans = MIN(temp, ans);
        }
    }

    printf("%d\n", ans);

    return 0;
}