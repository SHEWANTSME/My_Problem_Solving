// 9012 °ýÈ£
#include<iostream>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;
int n;
int main() {
	cin >> n;
	while (n--) {
		string s; cin >> s;
		stack<char>stk;
		bool flag = 0;
		for (int i = 0; i < s.size(); i++) {
			if (stk.empty()) {
				if (s[i] == '(')stk.push(s[i]);
				else { cout << "NO" << endl; flag = 1; break; }
			}
			else {
				if (s[i] == '(')stk.push(s[i]);
				else stk.pop();
			}			
		}
		if (flag == 1)continue;
		if (stk.empty())cout << "YES" << endl;
		if(not stk.empty()) cout << "NO" << endl;
	}
}