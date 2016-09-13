/* https://www.acmicpc.net/problem/2644 */

#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
void dfs(int p1);
int arr[111][111];
int cnt, m, n, p2;
bool check[111];
int dist[111];
int main() {
	int p1;
	scanf("%d", &n);
	scanf("%d %d", &p1, &p2);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = arr[b][a] = 1;
	}

	for (int i = 0; i <= n; i++)dist[i] = -1;

	dist[p1] = 0;

	dfs(p1);

	printf("%d\n", dist[p2]);
	return 0;
}
void dfs(int p1) {
	check[p1] = true;

	for (int k = 1; k <= n; k++) {
		if (arr[p1][k] && check[k] != true) {
			dist[k] = dist[p1] + 1;
			dfs(k);
		}
	}
}

/*DFS���*/

/*  Ǯ��.
	����ؾ��ϴ� �̼��� 7, 3�̸� 7�� root�� ���� �ڵ带 �ۼ��Ͽ��µ�,
	�Ÿ��� �����ϴ� �迭�� ���� Ȱ���Ͽ���.�Ÿ��� �����ϴ� �迭�� ������ ������ �κ��� - 1�� ���� Ȯ�� �� �� ������.
	�׸��� ���� ��ȣ�� dist���� + 1�Ͽ� ���� ���״�.
*/