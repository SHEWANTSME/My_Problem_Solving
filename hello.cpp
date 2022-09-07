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