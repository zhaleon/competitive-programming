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
#define rep(i,a,b) for (int i = a; i < b; i++)

void setIO(string name) {
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	int T, N;

	cin >> T;

	while (T--) {
		cin >> N;
		int res = 0;
		int a;
		rep(i,0,N) {
			cin >> a;
			if (i & 1)
				res ^= a;
		}
		if (res) cout << "first\n";
		else cout << "second\n";
	}
    
    return 0;
}








