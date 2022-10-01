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

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int arr[5][5];
int visited[5][5];
int r, c;
queue<pair<int, int>>q;
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
void BFS(int x, int y) {
	while (not q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (arr[nx][ny] == -1)continue;
			if (nx < 0 or ny < 0 or nx >= 5 or ny >= 5)continue;
			if (visited[nx][ny])continue;
			q.push({ nx,ny });
			visited[nx][ny] = visited[xx][yy] + 1;
		}
	}
}
int main() {
	int cx, cy;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)cx = i, cy = j;
		}
	}
	cin >> r >> c;
	q.push({ r,c });
	visited[r][c] = 1;
	BFS(r, c);
	/*for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << visited[i][j] << " ";
		}cout << endl;
	}*/
	cout << visited[cx][cy] - 1 << endl;
}

