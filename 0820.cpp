// 17144번 미세먼지 안녕!
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, t;
int arr[51][51];
int new_arr[51][51];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
// diffusion  먼저 그 다음 air
void Diffuse(int x, int y) {
	if (arr[x][y] == -1)return;
	int now = arr[x][y];int diffusing = now / 5;
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 or ny < 0 or nx >= n or ny >= m)continue;
		if(arr[nx][ny] == -1)continue;
		cnt++;
		new_arr[nx][ny] = new_arr[nx][ny]+ diffusing;
	}
	new_arr[x][y] = now - cnt * diffusing;
}
void Air(int x, int y, int time) {

}
int main() {
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1)new_arr[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(arr[i][j]>0)	Diffuse(i, j);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << new_arr[i][j] << " ";
		}cout << endl;
	}
	//Air(0,0,t);

		
}

//7 8 1
//0 0 0 0 0 0 0 9
//0 0 0 0 3 0 0 8
//- 1 0 5 0 0 0 22 0
//- 1 8 0 0 0 0 0 0
//0 0 0 0 0 10 43 0
//0 0 5 0 15 0 0 0
//0 0 40 0 0 0 20 0

// 엥 왜 이렇게 나오지.. 밑에거가 나의 diffuse된 결과

//0 0 0 0 0 0 1 10
//0 0 1 0 3 0 4 5
//- 1 1 1 1 0 4 6 4
//- 1 5 1 0 0 2 8 0
//0 1 1 0 3 18 11 8
//0 1 13 3 3 3 4 0
//0 8 16 8 3 4 8 4

// 제대로된 diffuse된 결과
//0 0 0 0 0 0 1 8
//0 0 1 0 3 0 5 6
//-1 2 1 1 0 4 6 5
//-1 5 2 0 0 2 12 0
//0 1 1 0 5 10 13 8
//0 1 9 4 3 5 12 0
//0 8 17 8 3 4 8 4