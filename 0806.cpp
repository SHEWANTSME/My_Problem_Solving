#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
// 2644 촌수계산
// have to make tree for sure..
//그냥 이차원 배열로 하면 될..수도?
int n, dad, son, m;
int arr[101][101];
int visited[101];

int main() {
	cin >> n >> dad >> son >> m;
	for (int i = 0; i < m; i++) {
		int x, y;	 cin >> x >> y;
		arr[x][y] = 1; arr[y][x] = 1;
	}
	queue<int>q;
	q.push(dad);
	while (not q.empty()) {
		int fr = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (arr[fr][i] != 0 and not visited[i]) {
				q.push(i);
				visited[i] = visited[fr] + 1;
			}
		}
	}
	if (visited[son] == 0) cout << -1 << endl;
	else cout << visited[son] << endl;
}

