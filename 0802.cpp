// 1937 욕심쟁이 PANDA
// 조건1 : 처음 지점에서 상하좌우로 이동가능한데
//옮기는 지역의 숫자가 더 커야함
// 그냥 DFS하면 시간초과가 걸리겠지?
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define endl "\n"
using namespace std;
int arr[501][501];
int dp[501][501];
int n;
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int ans = 0;
int DFS(int x, int y) {
	if (dp[x][y]) return dp[x][y];
	dp[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (arr[nx][ny] > arr[x][y]) {
			dp[x][y] = (dp[x][y] >DFS(nx,ny)+1) ? dp[x][y] : DFS(nx, ny) + 1;
		}
	}
	return dp[x][y];
}

int main() {
	// Restarting PS
	fastio;
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> arr[i][j];		
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ans = (ans > DFS(i, j)) ? ans : DFS(i, j);
	cout << ans << endl;	
}