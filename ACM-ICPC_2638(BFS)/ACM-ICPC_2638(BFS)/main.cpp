/* https://www.acmicpc.net/problem/2638 치즈 */

/* BFS */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

bool remain();
int arr[111][111];
int cnt, m, n;
int check[111][111];
int visit[111][111];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> q;
void bfs();

int main() {

	scanf("%d %d", &n, &m);//n=y, m=x;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			scanf("%d", &arr[y][x]);
		}
	}
	visit[0][0] = 1;
	q.push(make_pair(0, 0)); //first = y , second = x;

	while (remain()) { /* 모든 치즈를 1번 탐색 하고 처음부터 탐색 조건 */
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (arr[y][x] == 2) { /* 2면이 닿아 있는 치즈를 0으로 초기화 */
					arr[y][x] = 0;
				}
			}
		}
		memset(check, 0, sizeof(check)); /* 한번 다 탐색했고, 다시 탐색하기전에 체크배열과, visit 배열을0 으로 초기화*/
		memset(visit, 0, sizeof(visit));
		q.push(make_pair(0, 0)); /*다시 0,0 에서 시작 */
		bfs();
		cnt++; /* 한 바퀴 돌았으니, 1시간이 지남 */
	}
	printf("%d\n", cnt);
}

/* 치즈 BFS탐색 */
void bfs() {

	while (!q.empty())
	{
		pair<int, int> myPair;
		myPair = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nextY = myPair.first + dy[i];
			int nextX = myPair.second + dx[i];

			if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m)
			{
				if (arr[nextY][nextX] == 0 && visit[nextY][nextX] == 0)
				{
					visit[nextY][nextX] = 1;
					q.push(make_pair(nextY, nextX));
				}
				else if (arr[nextY][nextX] == 1) /* 격자위에 치즈가 있으면, check배열에 1을 더해줌 */
				{
					check[nextY][nextX] += 1;
					if (check[nextY][nextX] == 2)  /* 체크배열이 2 가되면, 즉 2면이 공기와 닿아있는지 체크*/
					{
						arr[nextY][nextX] = 2; /* 2면이 공기와 닿아있다면, 치즈의 값(초기화 1)을 2로 바꿔준다.*/
					}
				}
			}
		}
	}
}

/* 치즈가 남아 있는지 없는지 확인 해주는 함수 */
bool remain() {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (arr[y][x] == 1)
				return true;
		}
	}
	return false;
}

