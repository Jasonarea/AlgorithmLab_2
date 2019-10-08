#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

struct Pos {
	int x, y;
	int time;
};

int tunnel[8][4] = {
	{0, 0, 0, 0 },
	{1, 1, 1, 1},
	{1, 1, 0, 0},
	{0, 0, 1, 1},
	{1, 0, 0, 1},
	{0, 1, 0, 1},
	{0, 1, 1, 0},
	{1, 0, 1, 0}
};

int map[51][51][4]; // 터널의 유형까지 포함하는 3차원 배열을 만든다.
bool check[51][51];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int main (void)
{
	freopen ("sample_input.txt", "r", stdin);
	int T;
	scanf ("%d", &T);

	for (int tt = 1; tt <= T; tt++) {
		int N, M, R, C, L;
		scanf ("%d %d %d %d %d", &N, &M, &R, &C, &L);
		memset (check, false, sizeof (check));

		Pos start{};
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int type;
				scanf ("%d", &type);
				for (int k = 0; k < 4; k++)
					map[i][j][k] = tunnel[type][k]; // map[i][j] 위치의 터널 타입은 k
				if (i == R && j == C) start = { i, j, 0 };
			}
		}

		queue<Pos> q;
		q.push (start);
		check[start.x][start.y] = true;

		int ans = 0;
		while (!q.empty ()) {
			Pos cur = q.front ();
			q.pop ();
			if (cur.time >= L) break; // L시간이 지나면 break

			ans++;
			for (int i = 0; i < 4; i++) {
				if (map[cur.x][cur.y][i]) {
					int nx = cur.x + dx[i];
					int ny = cur.y + dy[i];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

					if (!check[nx][ny]) {
						if ((i == 0 && map[nx][ny][1]) || (i == 1 && map[nx][ny][0]) || (i == 2 && map[nx][ny][3]) || (i == 3 && map[nx][ny][2])) {
							check[nx][ny] = true;
							q.push ({ nx, ny, cur.time + 1 });
						}
					}
				}
			}
		}
		printf ("#%d %d\n", tt, ans);
	}
	return 0;
}