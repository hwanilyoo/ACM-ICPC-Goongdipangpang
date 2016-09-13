/* https://www.acmicpc.net/problem/2638 ġ�� */

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

	while (remain()) { /* ��� ġ� 1�� Ž�� �ϰ� ó������ Ž�� ���� */
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				if (arr[y][x] == 2) { /* 2���� ��� �ִ� ġ� 0���� �ʱ�ȭ */
					arr[y][x] = 0;
				}
			}
		}
		memset(check, 0, sizeof(check)); /* �ѹ� �� Ž���߰�, �ٽ� Ž���ϱ����� üũ�迭��, visit �迭��0 ���� �ʱ�ȭ*/
		memset(visit, 0, sizeof(visit));
		q.push(make_pair(0, 0)); /*�ٽ� 0,0 ���� ���� */
		bfs();
		cnt++; /* �� ���� ��������, 1�ð��� ���� */
	}
	printf("%d\n", cnt);
}

/* ġ�� BFSŽ�� */
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
				else if (arr[nextY][nextX] == 1) /* �������� ġ� ������, check�迭�� 1�� ������ */
				{
					check[nextY][nextX] += 1;
					if (check[nextY][nextX] == 2)  /* üũ�迭�� 2 ���Ǹ�, �� 2���� ����� ����ִ��� üũ*/
					{
						arr[nextY][nextX] = 2; /* 2���� ����� ����ִٸ�, ġ���� ��(�ʱ�ȭ 1)�� 2�� �ٲ��ش�.*/
					}
				}
			}
		}
	}
}

/* ġ� ���� �ִ��� ������ Ȯ�� ���ִ� �Լ� */
bool remain() {
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (arr[y][x] == 1)
				return true;
		}
	}
	return false;
}

