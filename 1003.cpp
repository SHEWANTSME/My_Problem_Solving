#include<iostream>
#include<vector>
#include<algorithm>	
using namespace std;
int n;
int arr[1001];
//int dp[1001][2];
bool chk[1001];
vector<int>ansans;
int main() {
	cin >> n;
	int k = 1;
	for (int i = 1; i <= n; i++) 	cin >> arr[i];
	while (k <= n) {
		vector<int>idx;
		vector<int>dp;
		for (int i = 0; i < k; i++) idx.push_back(1);
		for (int i = 0; i < n - k; i++)idx.push_back(0);
		sort(idx.begin(), idx.end());

		do {
			for (int i = 0; i < idx.size(); i++) {
				if (idx[i] == 1) {	/*	printf("%d ", arr[i + 1]);*/	chk[i + 1] = 1;}
			}
			for (int i = 1; i <= n; i++) {
				if (chk[i] == 0)continue;
				else dp.push_back(arr[i]);
			}
		//	cout << endl;
			int cnt = dp[0];
			int ans = 1;
			for (int i = 1; i < dp.size(); i++) {
				int now = dp[i];
				if (cnt >= now) {
					cnt += now;
					ans++;
				}
				else {
					cnt = now;
					ans = 1;
				}
			}
			cout << ans << endl;
			ansans.push_back(ans);
			ans = 1;
		} while (next_permutation(idx.begin(), idx.end()));
		k++;
	}
	sort(ansans.begin(), ansans.end());
	cout << "씨발"<<ansans.back() << endl;

	/*
	넥퍼뮤로 나온 모든결과를 벡터에 때려 박아서 저 do-while문을 나와서
	따로 loop을 해야 할듯!!
	이따가 하자
	
	
	
	
	*/
	//	dp[1][0] = 1;
	//	for (int i = 1; i <= n; i++) 	cin >> arr[i];
	//	dp[1][1] = arr[1];
	//	for (int i = 2; i <= n; i++) {
	//		if (dp[i - 1][1] >= arr[i]) {
	//			dp[i][1] = dp[i - 1][1] + arr[i];
	//			dp[i][0] = dp[i - 1][0] + 1;
	//		}
	//		else {
	//			dp[i][1] = arr[i];
	//			dp[i][0] = 1;
	//		}
	//	}
	//	cout << dp[n][0] << endl;
	//}
	//


}
//4 10 3 9 2 1
// 4 5 10 11 