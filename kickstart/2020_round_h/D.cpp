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

int T, N;

bool comp(pii a, pii b) {
	return a.S < b.S;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	int Case = 1;
	while(T--) {
		cin >> N;
		vector<pair<ll, ll>> players;
		rep(i,0,N) {
			int a, b;
			cin >> a >> b;
			players.emplace_back(a, b);
		}

		ll ans = 0;

		sort(players.begin(), players.end(), comp);

		ll median = players[N/2].S;

		for (auto p : players) ans += abs(p.S-median);

		sort(players.begin(), players.end());

		int sum = 1;
		int l = 0, r = players.size()-1;

		while (l < r) {
			ans += sum * (players[l+1].F-players[l].F + players[r-1].F - players[r].F + 2);	
			l++, r--, sum++;
		}
		printf("Case #%i: %lld\n", Case++, ans);
	}
    
    return 0;
}








