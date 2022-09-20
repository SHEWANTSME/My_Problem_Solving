//// 푸앙이와 코인.. 생각을 좀 더 해봐야 할듯?
//#include<iostream>
//#include<algorithm>
//#include<vector>
//using namespace std;
//int n;
//vector<pair<int, int>>cases[401];
//int main() {
//	cin >> n;
////	cases.push_back({ -1,-1 });
//	//cases.push_back({ -1,-1 });
//	cases[2].push_back({ 1,1 });
//	cases[3].push_back({ 1,1 }, { 2,1 });
//	cases[4] = cases[3];
//	cout << cases[2].front().first << " " << cases[3] << " " << cases[4] << endl;
//	//for (int i = 2; i <= n; i++) {
//	//	for (int k = i - 1; k >= 1; k++) {
//	//		
//	//	}
//	//}
//}

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n;
int arr[101][101];
int visited[101][101];
pair<int, int>start;
vector < pair<int, int>>monster;
int dx[4] = { 1,1,-1,-1};
int dy[4] = { -1,1,1,-1 };
int ans = 1e9;
void Back(int x, int y, int cnt, int anss) {
//	if (arr[x][y] == 1)anss++;
	visited[x][y] = cnt;
	if (anss == monster.size()) {
		cout << x << " " << y << " " << cnt<<endl;
		ans = min(ans, cnt);
		return; 
	}
//	if (not visited[x][y])return;
	//visited[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<1 or ny<1 or nx>n or ny>n)continue;
		if (visited[nx][ny])continue;
		if(arr[nx][ny]==1)	Back(nx, ny,cnt+1,anss+1);
		if (arr[nx][ny] != 1)Back(nx, ny, cnt + 1, anss);
		visited[nx][ny] = 0;
	//	if (arr[nx][ny] == 1)anss--;
	//	cout << nx << " " << ny << " " << cnt << " " << anss << endl;

	}
//	ans = min(cnt, ans);
//	cout <<x<<" " <<y<<" "<< cnt <<" "<<anss<< endl;
	//visited[x][y] = 0;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) { start.first = i;  start.second=j; }
			if (arr[i][j] == 1) { monster.push_back({ i,j }); }
		}
	}
	//bool flag = 0;
	//if ((start.first % 2 == 0 and start.second % 2 == 0) or (start.first % 2 == 1 and start.second % 2 == 1)) flag = 1;

	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= n; j++) {
	//		for (auto &m : monster) {
	//			if (flag == 1) {
	//				if ((m.first % 2 == 0 and m.second % 2 == 1) or (m.first % 2 == 1 and m.second % 2 == 0)) {
	//					cout << "Shorei" << endl; exit(0);
	//				}
	//			}
	//			else {
	//				if ((m.first % 2 == 0 and m.second % 2 == 0) or (m.first % 2 == 1 and m.second % 2 == 1)) {
	//					cout << "Shorei" << endl; exit(0);
	//				}
	//			}
	//		}
	//	}
	//}
	cout << "Undertaker" << endl;
	// 아 backtracking이구나 ㅅㅂ
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= n; j++) {
	//		Back(i, j);
	//	}
	//}
	visited[start.first][start.second] = 1;
	Back(start.first, start.second,1,0);
	cout << ans - 1 << endl;
//	cout << ans << endl;
//	for (int i = 1; i <= n; i++) {
//	for (int j = 1; j <= n; j++) {
//		cout << visited[i][j] << " ";
//	}cout << endl;
//}
}
