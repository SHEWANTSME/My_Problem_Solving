#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
int n;
int dp1[3001][3001];
int dp2[3001][3001];
//int arr[3001];
deque<int>arr;
int main() {
	cin >> n;
	for (int i = 0; i <= 3000; i++) for (int j = 0; j <= 3000; j++) dp1[i][j] = 1e9,dp2[i][j] = 1e9;
	for (int cnt = 0; cnt < 3; cnt++) {
		arr.push_back(1e9);
		for (int i = 1; i <= n; i++) { int t; cin >> t; arr.push_back(t); }
		reverse(arr.begin(),arr.end());
		int bck = arr.back(); arr.pop_back(); arr.push_front(bck);
		for (int i = 1; i <= n; i++) {
			dp1[i][i] = arr[i];
			if (i != 1) {
				dp2[i - 1][i - 1] = dp1[i][i];
			}
		}
		for (int i = 1; i <n; i++) {
			for (int j = i+1; j <= n; j++) {
				dp1[i][j] = dp1[i][j - 1] + arr[j];
			}
		}
	//	for (int i = 1; i <= n; i++) cin >> arr[i];
		for (int i = 1; i <= n; i++) {
			dp1[n + 1 - i][i] = arr[n + 1 - i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = n; j >=1; j--) {
				if (dp1[j][i] != 1e9)continue;
				dp1[j][i] = 
			}
		}
		











	}
}