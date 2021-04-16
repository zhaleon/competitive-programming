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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll N, X;

ll arr[1001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> X;
	rep(i,1,N+1) cin >> arr[i];


	unordered_map<ll, pii, custom_hash> m;

	rep(i,1,N+1) {
		rep(j,i+1,N+1) {
			if (m.find(X-arr[i]-arr[j]) != m.end()) {
				cout << m[X-arr[i]-arr[j]].S << ' ' << m[X-arr[i]-arr[j]].F << ' ' << i << ' ' << j << endl;
				return 0;
			}
		}

		rep(j,1,i) m[arr[i] + arr[j]] = MP(i, j);
	}	
	

	cout << "IMPOSSIBLE" << endl;

    return 0;
}








