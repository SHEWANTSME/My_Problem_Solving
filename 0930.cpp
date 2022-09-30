//25421 조건에 맞는 정수개수
#include<iostream>
using namespace std;
int n;
int dp[100001][10];
int ans = 0;
int main() {
	cin >> n;
	for (int i = 1; i < 10; i++)dp[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < 10; j++) {
			for (int l = -2; l <= 2; l++) {
				int len = j + l;
				if (len >= 1 and len <= 9) {
					dp[i][j] += dp[i - 1][len];
					dp[i][j] %= 987654321;
				}
			}
		}
		if (i == n)for (int k = 1; k <= 9; k++)ans = (ans + dp[n][k]) % 987654321;
	}
	if (n == 1) { cout << 9 << endl; exit(0); }
	else cout << ans << endl;
}