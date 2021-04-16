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

void setIO(string name) {
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
}

ll N;
ll f[60];

ll MSB(ll x) {
	int low = 0, high = 52, k = 0;
	while (low < high && k++ < 100) {
		int mid = (low + high + 1)/2;
		if ((1ll << mid) <= x) low = mid;
		else high = mid-1;
	}
	return low;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
  
	f[1] = 1;

	rep(i,2,52) 
		f[i] = (1ll << (i-1)) + 2*f[i-1];
		
	ll res = 0;

	while (N > 0) {
		res += f[MSB(N)];
		N -= (1ll << MSB(N));
		res += N+1;
	}

	cout << res << endl;	

    return 0;
}








