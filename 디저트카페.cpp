#include <cstring>
#include <cstdio>
using namespace std;

struct Pos {
	int x, y;
	int dist;
	int direction;
};

int map[51][51];
bool check[51][51];
bool eat[101];

int maxDessert = -1;
int startX, startY, N;

int dx[] = { -1, 1, 1, -1 };
int dy[] = { -1, -1, 1, 1 };

int Max (int a, int b) {
	return a > b ? a : b;
}

// dfs
void solve (Pos pos) {
	int x = pos.x;
	int y = pos.y;
	int dist = pos.dist;
	int direction = pos.direction;
	// base condition
	if (x == startX && y == startY && dist >= 4) {
		maxDessert = Max (maxDessert, dist);
		return;
	}

	// recursive
	for (int i = 0; i < 2; i++) {
		int nx = x + dx[(direction + i >= 4) ? 0 : direction + i];
		int ny = y + dy[(direction + i >= 4) ? 0 : direction + i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
		if (!check[nx][ny] && !eat[map[nx][ny]]) {
			check[nx][ny] = true;
			eat[map[nx][ny]] = true;
			solve ({ nx, ny, dist + 1, direction + i });
			check[nx][ny] = false;
			eat[map[nx][ny]] = false;
		}
		else if (startX == nx && startY == ny) {
			solve ({ nx, ny, dist + 1, direction + i });
		}
	}
}
int main (void)
{
	int T;
	scanf ("%d", &T);
	for (int tt = 1; tt <= T; tt++) {
		memset (check, false, sizeof (check));
		memset (eat, false, sizeof (eat));
		memset (map, 0, sizeof (map));
		maxDessert = -1;
		scanf ("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf ("%d", &map[i][j]);
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				check[i][j] = true;
				eat[map[i][j]] = true;
				startX = i; startY = j;
				solve ({ i, j, 0, 0 });
				check[i][j] = false;
				eat[map[i][j]] = false;
			}
		}
		printf ("#%d %d\n", tt, maxDessert);
	}
	return 0;
}