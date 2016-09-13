/*2�� BFS�� ������. ������ �������� �����ϴµ� �� ó�� �������� ������ �����, �� ������ ���� �ָ� �ִ� ������ �˾Ƴ���.
�˾Ƴ� �������� �ٽ� BFS�� ������ Ʈ���� �ִ� �Ÿ�(����)�� �� �� �ִ�.*/

#include<cstdio>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
#define INF 987654321
vector<pair<int, int> > adj[10]; 
bool check[100001];
int degree = 0;
int n;

pair<int, int> bfs(int now) {
	queue<pair<int,int> > myQ;
	check[now] = true;
	myQ.push(make_pair(now, 0));
	
	pair<int, int >a(0, -1); //���ؼ� �������ֱ����ؼ�
	
	while (!myQ.empty()) {
		pair<int, int> myP = myQ.front(); myQ.pop();
		if (myP.second > a.second)a = myP; //���ݱ����°� ������ ��� ����
		
		for (int i = 0; i < adj[myP.first].size(); i++) {
			if (check[adj[myP.first][i].first]==false) {
				pair<int, int> temp;
				temp.first = adj[myP.first][i].first;
				temp.second = myP.second + adj[myP.first][i].second; //���� weight(����)�� ���� ����� ������ weight�� ���ļ� ť�� �־��ش�.
				check[adj[myP.first][i].first] = true;
				myQ.push(temp);
			}
		}
	}
	return a;
}



int main() {
	
	
	scanf("%d",&n);
	
	for (int i = 0; i < n; i++) {
		int a, b, c;
		scanf("%d",&a);
		for (;;) {
			scanf("%d",&b);
			if (b == -1)break;
			scanf("%d",&c);
			adj[a].push_back(make_pair(b, c));
			
		}
	}
	
	pair<int,int> aa = bfs(1); //�ƹ������� ������, ���� �� ������ ����!
	memset(check, 0, sizeof(check));
	pair<int, int> res = bfs(aa.first); // �����ѰŸ� �ٽ� bfs�� ������ �����ϴ� ���� ���� ��!
	printf("%d\n",res.second);
	return 0;
}

