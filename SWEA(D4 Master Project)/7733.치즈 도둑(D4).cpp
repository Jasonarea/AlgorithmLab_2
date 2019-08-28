#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int cheese[101][101];
bool check[101][101];
int n;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs(int x, int y, int flavor) {
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    check[x][y] = true;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(!check[nx][ny] && cheese[nx][ny] > flavor) {
                check[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

int main(void)
{
    int T;
    scanf("%d", &T);

    for(int tt = 1;tt<=T;tt++) {
        scanf("%d", &n);
        int maxFlavor = 0;
        memset(check, 0, sizeof(check));
        memset(cheese, 0, sizeof(cheese));

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                scanf("%d", &cheese[i][j]);
                if(cheese[i][j] > maxFlavor)
                    maxFlavor = cheese[i][j];
            }
        }

        int maxCnt = 0;
        for(int k = 0;k<=maxFlavor;k++) {
            int cot = 0;
            memset(check, 0, sizeof(check));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (!check[i][j] && cheese[i][j] > k) {
                        cot++;
                        bfs(i, j, k);
                    }
                }
            }
            if(maxCnt < cot)
                maxCnt = cot;
        }
        printf("#%d %d\n", tt, maxCnt);
    }
    return 0;
}