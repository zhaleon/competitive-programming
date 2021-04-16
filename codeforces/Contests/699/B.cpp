#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define all(x, ...) next(begin(x), ##__VA_ARGS__), end(x)
#define rep(i,a,b) for (int i = a; i <= b; ++i)

int T, x, y;
string s;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> x >> y >> s;
		for (auto &c : s) {
			if (x > 0) {
				if (c == 'R') --x;
			} else if (x < 0){
				if (c == 'L') ++x;
			}
			if (y > 0) {
				if (c == 'U') --y;
			} else if (y < 0){
				if (c == 'D') ++y;
			}
		}

		if (x != 0 || y != 0) cout << "NO\n";
		else cout << "YES\n";
	}
    
    return 0;
}








