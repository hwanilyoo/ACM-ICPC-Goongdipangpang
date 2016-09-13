/*
	https://www.acmicpc.net/problem/9252, 역추적
	2016/09/13
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

#define INF 987654321
using namespace std;
int dp[1024][1024];
int back[1024][1024];
//대각선 : 3, 왼쪽 : 2, 위쪽 : 1 
int max2(int a, int b);
void back_track(int str1_len, int str2_len);
string str1, str2;
int main() {
	

	cin >> str1;
	cin >> str2;
	int str1_len = str1.length();
	int str2_len = str2.length();

	str1 = " " + str1;
	str2 = " " + str2;

	for (int i = 1; i <= str1_len; i++) {
		for (int j = 1; j <= str2_len; j++) {
			if (str1[i] == str2[j]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
				back[i][j] = 3;
				
			}
			if (str1[i] != str2[j]) {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]); 
				back[i][j] = max2(dp[i][j - 1], dp[i - 1][j]);
			}

		}
	}

	printf("%d\n",dp[str1_len][str2_len]);
	back_track(str1_len, str2_len);

	return 0;
}
int max2(int a, int b) {
	if (a > b)return 2;
	else return 1;
}
void back_track(int str1_len, int str2_len) {
	int x=str1_len;
	int y=str2_len;
	vector<char> parent;
	while (x&&y) {
		if (back[x][y] == 3) {
			parent.push_back(str1[x]);
			x = x - 1; y = y - 1;
		}
		if (back[x][y] == 2) {
			y = y - 1; //왼쪽에서 왔으니 y를 왼쪽으로
		}
		if (back[x][y] == 1) {
			x = x - 1; //위에서 왔으니 x를 위로
		}
	}

	for (int i = parent.size()-1; i >=0; i--) {
		printf("%c",parent[i]);
	}
	printf("\n");
}