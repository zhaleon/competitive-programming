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

ll arr[1000001];
ll bit[1000001];

void upd(int pos, int delta = 1) {
	while (pos < 1000001) {
		bit[pos] += delta;
		pos += pos & -pos;
	}
}

ll sum(int i) {
	ll res = 0;
	while (i > 0) {
		res += bit[i];
		i -= i & -i;
	}
	return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	map<int, int> m;
	
	rep(i,1,N+1) {
		cin >> arr[i];
		m[arr[i]];
	}
	int ind = 0;

	for (auto &p : m) p.S = ++ind;

	rep(i,1,N+1) {
		int a = arr[i];
		upd(m[a]);
		cout << sum(m[a]-1) + 1 << ' ';
	}

    return 0;
}








