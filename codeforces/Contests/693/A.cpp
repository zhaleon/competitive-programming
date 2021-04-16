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
#define rep(i,a,b) for (int i = a; i <= b; i++)

int T, w, h, n;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> w >> h >> n;

		ll cuts_w = 0;
		ll cuts_h = 0;

		ll wide = 1;
		ll height = 1;

		while (w % 2 == 0) {
			cuts_w += wide;
			wide <<= 1;
			w >>= 1;
		}

		while (h % 2 == 0) {
			cuts_h += height;
			height <<= 1;
			h >>= 1;
		}

		ll ans = (cuts_w+1) * (cuts_h+1);


		if (ans >= n)
			cout << "YES\n";
		else 
			cout << "NO\n";

	}
    
    return 0;
}








