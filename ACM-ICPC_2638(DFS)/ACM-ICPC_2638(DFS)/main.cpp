/* https://www.acmicpc.net/problem/2638 ДЎБо */

/* DFS */
#include <iostream>
#include <utility>
#include <limits.h>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#define INF 987654321
using namespace std;

void dfs(int o, int q);
bool remain();
int n, m;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int dist[111][111];
int visit[111][111];
int check[111][111];

int main() {
	scanf("%d %d", &n, &m);
	int cnt = 0;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			scanf("%d", &dist[y][x]);
		}
	}

	while (remain()) {
		dfs(0, 0);
		cnt++;
		memset(visit, 0, sizeof(visit));
		memset(check, 0, sizeof(check));
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (dist[y][x] == 2)
					dist[y][x] = 0;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}

void dfs(int a, int b) {
	visit[a][b] = 1;

	for (int i = 0; i < 4; i++) {
		int	nextY = a + dy[i];
		int	nextX = b + dx[i];

		if (nextX >= 0 && nextX < m && nextY >= 0 && nextY < n) {
			if (dist[nextY][nextX] == 0 && visit[nextY][nextX] == 0) {
				dfs(nextY, nextX);
			}
			else if (dist[nextY][nextX] == 1) {
				check[nextY][nextX] += 1;
				if (check[nextY][nextX] == 2) {
					dist[nextY][nextX] = 2;
				}
			}
		}
	}
}

bool remain() {

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (dist[y][x] == 1)
				return true;
		}
	}
	return false;
}
