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

// airpods 25495
#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
deque<int>airpods;
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t; cin >> t; airpods.push_back(t);
	}
	if (n == 1) { cout << 2 << endl; exit(0); }

	int pre = airpods.front();
	airpods.pop_front();
	int bat = 2;
	int ans = bat;
	
	while (not airpods.empty()) {
		int fr = airpods.front();
		if (fr == pre) {
			if (ans == 0)bat = 2;
			else bat *= 2;
			/*if (bat == 0)bat = 2;
			else  bat *= 2;*/
			ans += bat;
			pre = fr;
			if (ans >= 100) { ans = 0; bat = 0; }
			//if (bat >= 100)bat = 0;
			airpods.pop_front();
		}
		if (fr != pre) {
			bat = 2;
			ans += bat;
			pre = fr;
			if (ans >= 100) { ans = 0; bat = 0; }
			airpods.pop_front();
		}
	}
	cout << ans << endl;

}