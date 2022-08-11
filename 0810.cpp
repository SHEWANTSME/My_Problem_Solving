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
	if (alpha[now - 'A'] == 1) { return; }
	alpha[now - 'A'] = 1;
	cnt++;
	mmax = max(cnt, mmax);
	//cout << cnt << endl;
	//cout << cnt << " " << now << endl;
	//cout << mmax << " " << now << endl;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 or ny < 0 or nx >= n or ny >= m) continue;
		if (alpha[arr[nx][ny] - 'A'] == 1)continue;
		DFS(nx, ny);
	}
	alpha[arr[x][y] - 'A'] = 0;
	cnt--;
	
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> arr[i][j];

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		DFS(i, j);
	//	}
	//}
	DFS(0, 0);
	//cout << cnt << endl;
	cout << mmax << endl;
}
// 이게 왜 가능하냐면, 현재 dx,dy는  -> , down , up , <-의 순서를 가지고있고
// 저 for문을 다 돌아서 노답이면 for문 밖으로 나와서 visited인 alpha의 체크를 풀어줘야
// 원상태로 갈 수 있고, cnt도 -- 해줘야 진정한 원상태로 가는거임
// 근데 cnt의 최댓값이 답이니까 mmax를 구해주면 답


2 3
ADE
BCA
답은 5
-> , down, up, <- 이렇게  