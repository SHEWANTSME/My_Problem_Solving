// 2910번 빈도정렬
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#define ll long long
#define ff first
#define sc second
using namespace std;
ll n, c;
map<ll, ll> idx, mp;
vector<pair<ll, ll>>v;
bool cmp(pair<ll, ll>&x, pair<ll, ll>&y) {
	if (x.sc == y.sc) return idx[x.ff] < idx[y.ff];// idx가 작은애부터 출력
	else return x.sc > y.sc;
	/*
	return a < b; 오름차순(1 2 3 4 )
	return a>b; 내림차순(4,3,2,1)
	*/
}
int main() {
	cin >> n >> c;
	for (int i = 1; i <= n; i++) {
		ll t; cin >> t; 	mp[t]++;
		if (idx[t] == 0) idx[t] = i;
	}
	for (auto &e : mp) v.push_back({ e.ff, e.sc });
	sort(v.begin(), v.end(), cmp);
	for (auto &e : v) {
		int iter = e.sc;
		for (int i = 0; i < iter; i++) {
			cout << e.ff << " ";
		}
	}	
}

// 13414 수강신청

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
map<string, int>mp1;
map<string, int>mp2;
vector<pair<int, string>>v;
int n, c;
int main() {
	cin >> n >> c;
	for (int i = 1; i <= c; i++) {
		string s; cin >> s;
		mp1[s]++;
		if (mp1[s] == 1) {
			mp2[s] = i;
		}
		if (mp1[s] > 1) {
			mp1[s]--; 
			mp2[s] = i;
			//continue;
		}
	}
	for (auto &e : mp2) {
		v.push_back({ e.second, e.first });
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	for (auto &e : v) {
		if (cnt == n)break;
		cout << e.second << endl;
		cnt++;
	}
}