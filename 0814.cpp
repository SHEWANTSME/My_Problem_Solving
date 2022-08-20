#include<iostream> // 7568 µ¢Ä¡
#include<vector>
#define ff first
#define sc second
#define pp pair<int,int>
using namespace std;
int n;
vector<pp>v;
int main() {
	cin >> n; int nn = n;
	while (n--) {
		int weight, height;
		cin >> weight >> height;
		v.push_back({ weight,height });
	}
	for (auto &i : v) {
		int x = 1;
		for (auto &j : v) {
			if (i.ff < j.ff and i.sc < j.sc)x++;
		}cout << x << " ";
		//cout << e.first << " " << e.second << endl;
	}
	/*for (int i = 0; i < nn; i++) {
		int x = 1;
		for (int j = 0; j < nn; j++) {
			if (v[i].ff < v[j].ff and v[i].sc < v[j].sc)x++;
		}cout << x << " ";
	}*/
}