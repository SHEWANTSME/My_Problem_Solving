#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
// 2644 ÃÌ¼ö°è»ê
// have to make tree for sure..
int n, dad, son, m;
vector<int>v[101];
void check(int x, int y) {

}

int main() {
	cin >> n >> dad >> son >> m;
	for (int i = 0; i < m; i++) {
		int x, y;	 cin >> x >> y;
		v[x].push_back(y);
	}

	for (int i = 0; i <= 100; i++) {
		if (v[i].empty())continue;
		else {
			for (auto &e : v[i]) {
				
			}
		}
	}
	//for (int i = 0; i < 100; i++) {
	//	if (v[i].empty())continue;
	//	else {
	//		for (auto &e : v[i]) {
	//			cout <<i <<" "<<e << endl;
	//		}
	//		//cout << v[i] << endl;
	//	}
	//	//cout << v[i].<< endl;
	//}


}