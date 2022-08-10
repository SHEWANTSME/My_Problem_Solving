// 1987 alphabet
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n, m;
char arr[21][21];
int alpha[26];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int cnt = 0;
int mmax = -1;
void DFS(int x, int y) {
	char now = arr[x][y];
	if (alpha[now - 'A'] == 1) { cnt--; return; }
	alpha[now - 'A'] = 1;
	cnt++;
	//mmax = max(cnt, mmax);
	cout << cnt << endl;
	//cout << mmax << " " << now << endl;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 or ny < 0 or nx >= n or ny >= m) continue;
		DFS(nx, ny);
	}
	
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> arr[i][j];
	DFS(0, 0);
	
		


}