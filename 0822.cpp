// 2493번 탑
#include<iostream>
#include<stack>
#include<vector>
#define ll long long
using namespace std;
int n;
ll arr[500001];
stack<ll>stk;
stack<ll>temp;
vector<ll>v;
void DO(stack<ll>&stk, stack<ll>&temp, int &now , int cnt) {
	if (stk.empty()) {
		stk.push(now);
		while (not temp.empty()) {
			int tmp_top = temp.top();
			temp.pop();
			stk.push(tmp_top);
		}
		v.push_back(cnt);
		
		return;
	}
	int ttop = stk.top();
	if (not stk.empty() and now <= ttop) {
		stk.pop();
		temp.push(ttop);
		DO(stk, temp, now, cnt+1);
		return;
	}
	if(not stk.empty() and now>ttop) {
		stk.push(now);
		while (not temp.empty()) {
			int tmp_top = temp.top();
			temp.pop();
			stk.push(tmp_top);
		}
		v.push_back(cnt);
		return;
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) 	cin >> arr[i];
	stk.push(arr[1]);
	//cout << 0 << " ";
	if (n == 1)exit(0);
	v.push_back(0);
	for (int i = 2; i <= n; i++) {
		int now = arr[i];
		int ttop = stk.top();
		DO(stk, temp, now,0);
		//while (not stk.empty()) {
		//	int ttop = stk.top();
		//	DO(stk, temp, now);
		//	//stk.pop();
		//	//if (now > ttop) {
		//	//	stk.push(now);
		//	//	v.push_back(0);
		//	//	continue;
		//	//}
		//	//else {
		//	//	DO(stk, temp, now);
		//	//	//temp.push(ttop);
		//	//	//stk.pop();
		//	//}
		//}
	}
	for (auto &e : v) {
		cout << e << endl;
	}
	
} // 시간초과.. stack 두개쓰면 시간초과나는듯 -> pair로 해보자.!


