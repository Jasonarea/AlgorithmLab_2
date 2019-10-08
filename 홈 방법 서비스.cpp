#include <cstdio>
#include <cstring>
using namespace std;

// BFS 문제 아님 주의 (BFS : 시간초과)
int map[21][21];
int n, m;

int Max (int a, int b) { return a > b ? a : b; }
int Abs (int a) { return a > 0 ? a : -a; }

int findHouse (int x, int y) {
	int K = 0; // range
	int res = 0; 
	int profit = 0; 
	int cost = 0;
	int ans = 0;

	while (K < n * 2) {
		cost = K * K + (K - 1) *(K - 1);
		res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int nx = i, ny = j;
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				int dist = Abs (nx - x) + Abs (ny - y); // ** 핵심
				if (dist < K && map[nx][ny]) res++;
			}
		}
		profit = m * res - cost;
		if (profit >= 0) ans = Max (ans, res);
		K++;
	}
	return ans;
}

int main (void)
{
	freopen ("sample_input.txt", "r", stdin);
	int T;
	scanf ("%d", &T);
	
	for (int tt = 1; tt <= T; tt++) {
		scanf ("%d %d", &n, &m);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				scanf ("%d", &map[i][j]);
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int house = findHouse (i, j);
				ans = Max (ans, house);
			}
		}
		printf ("%d\n", ans);
	}
	return 0;
}