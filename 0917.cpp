// B¹ø
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int main() {
	cin >> n;
	for (int i = 0; ; i++) {
		n = n - i;
		if (n < 0) {
			if (i % 2 == 0) { cout << 0 << endl; exit(0); }
			else {
			//	n = n - i;
				cout << -n << endl; exit(0);
			}
		}
	}
}
// D¹ø
#include<iostream>
#include<string>
using namespace std;
string s;
string HG[26] = {
	"aespa","baekjoon","cau","debug","edge","firefox","golang","haegang","iu"
	,"java","kotlin","lol","mips","null","os","python","query","roka","solvedac", "tod","unix"
	,"virus","whale","xcode","yahoo","zebra"
};
string ans = "";
int main() {
	cin >> s;
	int k = 1;
	for (int i = 0; i < s.size(); i += k) {
		char now = s[i];
		bool flag = 1;
		for (int j = 0; j < 26; j++) {
			if (now == HG[j][0]) {
				for (int k = 0; k < HG[j].size(); k++) {
					if (s[k + i] != HG[j][k]) {
						flag = 0;
						cout << "ERROR!" << endl; exit(0);
					}
				}
				break;
			}
		}
		if (flag == 1) { ans.push_back(now); k = HG[s[i] - 'a'].size(); }

	}
	cout << "It's HG!" << endl;
	cout << ans << endl;
}

