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

ll N, K;

struct info {
	ll a, b, x;
	info() {};
	info(ll c, ll d, ll e) : a(c) , b(d), x(e){};
};

auto comp = [](info a, info b) {
	return a.a-a.b - 2*a.b*a.x < b.a-b.b - 2*b.b*b.x;
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> K;

	priority_queue<info, vector<info>, decltype(comp)> pq(comp);

	rep(i,0,N) {
		ll a, b;
		cin >> a >> b;
		pq.push(info(a,b,0));
	}

	ll ans = 0;

	rep(i,0,K) {
		auto cur = pq.top(); pq.pop();
		if (cur.a - cur.b - 2*cur.b*cur.x < 0) break;
		ans += cur.a - cur.b - 2*cur.b*cur.x;
		//cout << ans << '\n';
		
		pq.push(info(cur.a, cur.b, cur.x+1));
	}

	cout << ans << '\n';

    return 0;
}








