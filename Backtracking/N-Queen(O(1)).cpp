#include <cstdio>
using namespace std;

int n;
int queen;
bool check_col[15], check_dig[40], check_dig2[40];
bool map[15][15];

bool check(int row, int col) {
    if(check_col[col]) return false;
    if(check_dig[row + col]) return false;
    if(check_dig2[row - col + n]) return false;

    return true;
}

void solve(int row) {
    if(row == n) {
        queen++;
        return;
    }

    for(int col = 0;col < n;col++) {
        if(check(row, col)) {
            check_col[col] = check_dig[row + col] = check_dig2[row -col + n] = map[row][col] = true;
            solve(row + 1);
            check_col[col] = check_dig[row + col] = check_dig2[row -col + n] = map[row][col] = false;
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