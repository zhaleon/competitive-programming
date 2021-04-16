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

ll N, X;


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

ll arr[200000];
unordered_map<ll, int, custom_hash> m;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> X;
	rep(i,0,N) cin >> arr[i];

	m.reserve(2000000);
	m.max_load_factor(.33);
	m[0] = 1;
	ll running = 0, ans = 0;
	rep(i,0,N) {
		running += arr[i];
		//cout << "debug " << running << ' ' << X-running << endl;
		if (m.find(running-X) != m.end()) ans += m[running-X];
		m[running]++;
	}

	cout << ans << endl;
    
    return 0;
}








