#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Pos {
	int x, y;
	int dist;
};

int n, k;
int map[10][10];
bool check[10][10];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
bool isCut = false;

int ans = 0;

int Max (int a, int b) {
	return a > b ? a : b;
}

void solve (Pos pos)  {
	
	ans = Max (ans, pos.dist);

	for (int i = 0; i < 4; i++) {
		int nx = pos.x + dx[i];
		int ny = pos.y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (!check[nx][ny] && map[nx][ny] < map[pos.x][pos.y]) {
			check[nx][ny] = true;
			solve ({ nx, ny, pos.dist + 1 });
			check[nx][ny] = false;
		}
		else if (!check[nx][ny] && map[nx][ny] >= map[pos.x][pos.y] && !isCut) {
			if (map[nx][ny] - k < map[pos.x][pos.y] && map[pos.x][pos.y] >= 0) {
				check[nx][ny] = true;
				isCut = true;
				int temp = map[nx][ny];
				map[nx][ny] = map[pos.x][pos.y] - 1;
				solve ({ nx, ny, pos.dist + 1 });
				check[nx][ny] = false;
				map[nx][ny] = temp;
				isCut = false;
			}
		}
	}
}

int main(void)
{
	int T;
	freopen ("sample_input.txt", "r", stdin);
	scanf("%d", &T);

	for(int tt = 1;tt<=T;tt++) {
		memset (map, 0, sizeof (map));
		ans = 0;
		scanf("%d %d", &n, &k);
		int maxRoad = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] > maxRoad) maxRoad = map[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] == maxRoad) {
					memset (check, false, sizeof (check));
					check[i][j] = true;
					solve ({ i, j, 0 });
				}
			}
		}
		printf ("#%d %d\n", tt, ans + 1);
	}

	return 0;
}