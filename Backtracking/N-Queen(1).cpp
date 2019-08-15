#include <cstdio>
using namespace std;

int n;
int map[15][15];
int queen;

bool check(int row, int col) {
    // 세로 체크
    for(int i = 0;i<row;i++) {
        if(map[i][col])
            return false;
    }

    // 왼쪽 위 대각선
    int x = row - 1;
    int y = col - 1;
    while(x >= 0 && y >= 0) {
        if(map[x][y]) return false;
        x--; y--;
    }


    // 오른쪽 위 대각선
    x = row - 1;
    y = col + 1;
    while(x >= 0 && y < n) {
        if(map[x][y]) return false;
        x--; y++;
    }

    return true;
}

void solve(int row) {
    // base condition
    if(row == n) {
        queen++;
        return;
    }


    // recursive
    for(int col = 0;col < n;col ++) {
        if(check(row, col)) {
            map[row][col] = true;
            solve(row + 1);
            map[row][col] = false;
        }
    }
}

int main(void)
{
    scanf("%d", &n);
    solve(0);

    printf("%d\n", queen);

    return 0;
}