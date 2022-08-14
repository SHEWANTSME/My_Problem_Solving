#include<iostream>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
// 2110번 공유기설치
// parametric search
vector<ll>v;
int n, c;
// 아니 이렇게 풀면 안될거같음.. retry..
int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int t; cin >> t; v.push_back(t);
	}
	sort(v.begin(), v.end());
	ll first = 0;
	ll last = v.size() - 1;
	while (first <= last) {
		ll mid = (v.size() - 1) / 2;
		
	}
}