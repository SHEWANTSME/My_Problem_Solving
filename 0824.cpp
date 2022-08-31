// 6198 옥상 정원 꾸미기
#include<iostream>
#include<queue>
#define ll long long
#define pp pair<ll , ll>
#define ff first
#define sc second
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int n;
ll arr[80001];
ll ans[80001];
priority_queue<pp, vector<pp>, greater<pp>>pq;
int main() {
	fastio;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	pq.push({ arr[1] , 1 });
	int cnt = 0;
	/*while (not pq.empty()) {
		pp now = pq.top();
		for (int i = 2; i <= n; i++) {			
			if (now.ff >= arr[i]) { cnt++; continue; }
			else break;
		}
		pq.pop();
	}*/

	for (int i = 2; i <= n; i++) {
		while (not pq.empty()) {
			pp now = pq.top();
			bool signal = 0;
			if (now.ff >= arr[i]) {
				pq.pop();
				ans[now.sc] = i;
				signal = 1;
			}
			if (!signal)break;
		}
		pq.push({ arr[i],i });
	}
	for (int i = 1; i <= n; i++)
		cnt += ans[i];
	cout << cnt << endl;
}

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#define ll long long
#define pp pair<ll , ll>
#define ff first
#define sc second
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
ll n, cnt = 0;
ll arr[80001];
ll ans[80001];
stack<ll>stk;
priority_queue<pp, vector<pp>, greater<pp>>pq;
vector<ll>v;
int main() {
	cin >> n;
	while (n--) {
		ll t; cin >> t; 
		if (stk.empty() or stk.top() > t) stk.push(t);
		else {
			while (not stk.empty()) {
				if (stk.top() <= t) {
					stk.pop();
					cnt += stk.size();
				}
				else continue;
			}
			stk.push(t);
		}
		if (n == 0) {
			while (not stk.empty()) {
				stk.pop();
				cnt += stk.size();
			}
		}
	}
	cout << cnt << endl;
}

#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
int n;
string s;
stack<int>stk;
stack<char>ss, ss2;
int main() {
	cin >> n >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] - '0' >= 1 and s[i] - '0' <= 9)stk.push(1);
		else {
			if (s[i] == 'L') { ss.push(s[i]); continue; }
			if(s[i] == 'R'){
				if (not ss.empty()) {
					stk.push(1);
					ss.pop();
					continue;
				}
				else { cout << stk.size() << endl; exit(0); }
			}
			if (s[i] == 'S') { ss2.push(s[i]); continue; }
			if (s[i] == 'K') {
				if (not ss2.empty()) {
					stk.push(1);
					ss2.pop();
					continue;
				}
				else { cout << stk.size() << endl; exit(0); }
			}
		}
	}
	cout << stk.size() << endl;
}














//
//// airpods 25495
//#include<iostream>
//#include<vector>
//#include<deque>
//#include<algorithm>
//using namespace std;
//deque<int>airpods;
//int n;
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int t; cin >> t; airpods.push_back(t);
//	}
//	if (n == 1) { cout << 2 << endl; exit(0); }
//
//	int pre = airpods.front();
//	airpods.pop_front();
//	int bat = 2;
//	int ans = bat;
//	
//	while (not airpods.empty()) {
//		int fr = airpods.front();
//		if (fr == pre) {
//			if (ans == 0)bat = 2;
//			else bat *= 2;
//			/*if (bat == 0)bat = 2;
//			else  bat *= 2;*/
//			ans += bat;
//			pre = fr;
//			if (ans >= 100) { ans = 0; bat = 0; }
//			//if (bat >= 100)bat = 0;
//			airpods.pop_front();
//		}
//		if (fr != pre) {
//			bat = 2;
//			ans += bat;
//			pre = fr;
//			if (ans >= 100) { ans = 0; bat = 0; }
//			airpods.pop_front();
//		}
//	}
//	cout << ans << endl;
//
//}