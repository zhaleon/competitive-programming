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

int N;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	priority_queue<pii, vpi, greater<pii>> pq;

	rep(i,0,N) {
		int a, b; 
		cin >> a >> b;
		pq.push(MP(a, 1));
		pq.push(MP(b, 0));
	}
   
	int active = 0, ans = 0;

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();

		if (cur.S) active++;
		else active--;

		ans = max(ans, active);
	}

	cout << ans << endl;

    return 0;
}








