#include<iostream>
#include<stack>
#include<vector> 
#include<algorithm>
#define ll long long
#define pp pair<ll,ll>
#define sc second
#define ff first
using namespace std;
int n;
stack<pp>stk;
vector<ll>v;
int main() {
	cin >> n;
	//cout << "fucking hell" << endl;
	for (int i = 1; i <= n; i++) {
		int t; cin >> t;
		while (not stk.empty() and stk.top().sc < t)
			stk.pop();
		if (stk.empty()) cout << 0 << " ";
		else cout << stk.top().ff << " ";
		stk.push({ i,t });
	}
}



#include<iostream>
#include<stack>
#include<vector>
#define ll long long
#define pp pair<ll,ll>
#define sc second
#define ff first
using namespace std;
ll n; 
stack<pp>stk;
vector<ll>v;
int main() {
	cin >> n;
	int mx = -1;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		if (i == 0) {
			mx = t;
			stk.push({t,-1});
		}
		else {
			if (t > stk.top().ff) {
				stk.top().sc = t;
				stk.push({ t,-1 });
				continue;
			}
			else {

			}
		}

	}
}


//  9 5 4 8
// -1 8 8 -1



// minecraft
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n, m, b;
int arr[501][501];
priority_queue<pair<int, int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
//priority_queue<int>pq;
int mmin = 1e9;
int mmax = -1;
int main() {
	// 고르지 않은 땅에선 작업을 x -> 땅 고르기 작업 need -> height all same
	/*
		1. 해당 좌표의 highest block to the inventory -> 2초
		2. inventory에서 block 꺼내서 stackin -> 1초
	*/
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			cin >> arr[i][j];
	for (int h = 0; h <= 256; h++) {
		int del = 0;
		int inv = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int now_h = arr[i][j] - h;
				if (now_h < 0) inv -= now_h;
				else del += now_h;
			}
		}
		if (del + b >= inv) {
			int Time = del * 2 + inv;
			if (mmin >= Time) {
				mmin = Time; 
				mmax = h;
			}
		}
	}
	cout << mmin << " " << mmax << endl;
	//for (int i = 0; i <= 256; i++) {
	//	if (height[i] > 0) {
	//		pq.push({ height[i] , i });
	//	}
	//}
	//while (not pq.empty()) {
	//	int x = pq.top().first;
	//	int y = pq.top().second;
	//	cout << x <<" "<< y<< endl;
	//	pq.pop();
	//}
}


#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
int n, c;
unordered_map<ll, ll>mp;
vector<ll>v;
vector<pair<ll, ll>>vv;
bool cmp(pair<ll,ll>a, pair<ll, ll>b) {
	if (a.first == b.first) return a.second < b.second;
	else a.second > b.second;
}
bool cmp(pair<ll, ll>&m1, pair<ll, ll>&m2) {
	if (m1.second == m2.second) return m1.first > m2.first;
	return m1.second < m2.second;
}

int main() {
	 map을 두번 쓰면 해결될 일인데 왜 생각이 안났을까..?

	cin >> n >> c;
	if (n == 1) {
		ll t; cin >> t; cout << t << endl; exit(0);
	}
	for (int i = 0; i < n; i++) {
		ll t; cin >> t; 
		mp[t]++;
	}
	vector<pair<ll, ll>>vec(mp.begin(), mp.end());
	sort(vec.begin(), vec.end(), cmp);
	for (auto &e : vec) {
		cout << e.first << " " << e.second << endl;
	}
	sort(mp.begin(), mp.end(), cmp);
	for (auto &e : mp) {
		cout << e.first << " " << e.second << endl;
	}


	for (int i = 0; i < n; i++) {
		ll t; cin >> t; v.push_back(t);
		if (i == 0) { vv.push_back({ 1,t }); continue; }
		else {
			bool flag = 0;
			for (auto &e : vv) {
				if (t == e.second) {
					e.first++; flag = 0; break;
				}
				else flag = 1;
			}
			if (flag == 1) { vv.push_back({ 1,t }); }
		}
	}
	stable_sort(vv.begin(), vv.end(), greater<>() );
	//1 8 7 1 7 8 1 8 7

	for (auto &e : vv) {
		cout << e.first << " " << e.second << endl;
	}


}
