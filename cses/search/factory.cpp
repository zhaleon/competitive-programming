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

int N, T;
ll arr[200000];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> T;

	rep(i,0,N) cin >> arr[i];

	auto works = [](ll t) {
		ll res = 0;
		rep(i,0,N) {
			res += t/arr[i];
			if (res > 1e17) return true;
		}
		return res >= T;
	};

	ll low = 1, high = 1e18;

	while (low + 1 < high) {
		ll mid = (low + high)/2;
		if (works(mid)) high = mid;
		else low = mid;
	}

	cout << high << endl;
    
    return 0;
}








