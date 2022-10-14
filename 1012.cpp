#include<iostream>
// 이문제가 25822번 2000문제 푼 임스
#include<algorithm>
#include<deque>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define endl "\n"
using namespace std;
double a;
int t, n, la;
int arr[100001];
deque<int>dq;
int main() {
	cin >> a;
	if (a >= 0.0 and a <= 0.98)t = 0;
	else if (a >= 0.99 and a <= 1.97)t = 1;
	else if (a >= 1.98 and a <= 2.96)t = 2;
	else if (a >= 2.97 and a <= 3.95)t = 2;
	else if (a >= 3.96 and a <= 4.94)t = 2;
	else t = 2;
	cin >> n;
	int mx = -1;
	int cnt = 0;
	int cntmax = 0;
	int zerocnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		mx = (arr[i] > mx) ? arr[i] : mx;
		if (arr[i] == 0) {
			dq.push_back(arr[i - 1]);
			cntmax = (cntmax > cnt) ? cntmax : cnt;
			cnt = 0; zerocnt++;
		}
		else { arr[i] = arr[i - 1] + 1; cnt++; }
	}
	/*for (auto &e : dq)
		cout << e << endl;
*/
	int fr = 0;
	if (zerocnt < t) la = zerocnt-1;
	else la = t - 1;
	int maxx = -1;
	while (la < dq.size()) {
		int sum = 0;
		for (int i = fr; i <= la; i++) sum += dq[i];
		if (zerocnt < t)sum += zerocnt;
		else	sum += t;
		if (la + 1 >= dq.size()) sum += arr[n];
		else sum += dq[la + 1];
		maxx = (maxx > sum) ? maxx : sum;
		fr++;
		la++;
	}
	if (maxx == -1) {
		if (n == 1)cout << 1 << endl;
		else cout << cntmax << endl;
	}
	else	cout << maxx << endl;
	cout << mx << endl;
}