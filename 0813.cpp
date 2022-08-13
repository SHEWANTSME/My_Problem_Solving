// 백준 1514 자물쇠 
// 이 문제도 일단 풀이를 적어두고 나중에 다시 풀어보든가.. 해야할듯
// 오늘 pro시험에서 푼 문제와 가장 유사한 문젠데 어렵다

#include<iostream>
#include<algorithm>
#define pp pair<int,int>
using namespace std;
int n;
int a[101];
int b[101];
int dp[101][10][10];
int get_weight(int turn) {
	int move = (turn > 10 - turn) ? 10 - turn : turn;
	return (move % 3 == 0) ? move / 3 : move / 3 + 1;
}
int Rec(int idx, int n, int t1, int t2) {
	if (idx > n)return 0;
	int &ans = dp[idx][t1][t2];
	if (ans != -1)return ans;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int now = (a[idx] + i + j + t1) % 10;
			int now_t1 = (t2 + i + j) % 10;
			int now_t2 = j;
			int gap = b[idx] - now;
			int fir = (gap < 0) ? gap + 10 : gap;
			int realans = get_weight(fir) + get_weight(i) + get_weight(j) + Rec(idx + 1, n, now_t1, now_t2);
			if (ans != -1)ans = min(ans, realans);
			else ans = realans;
		}
	}
	return ans;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf_s("%1d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf_s("%1d", &b[i]);
	}
	for (int i = 0; i <= 100; i++)
		for (int j = 0; j < 10; j++) 
			for (int k = 0; k < 10; k++) 
				dp[i][j][k] = -1;
	cout << Rec(1, n, 0, 0) << endl;
}