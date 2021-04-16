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

int N, A, B;

ll arr[200001];
ll pref[200001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> A >> B;

	rep(i,1,N+1) {
		cin >> arr[i];
		pref[i] = pref[i-1] + arr[i];
	}
   
	ll ans = -1e18;
	
	multiset<ll> s;

	rep(i,1,N+1) {
		if (i >= A) s.insert(pref[i-A]);
		if (s.size()) ans = max(ans, pref[i] - *s.begin());	
		if (i >= B) s.erase(s.find(pref[i-B]));
	}

	cout << ans << endl;

    return 0;
}








