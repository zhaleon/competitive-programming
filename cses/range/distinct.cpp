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

int N, Q;
int arr[200001];
int bit[200001];
int ans[200001];

struct query {
	int id, a, b;
	query() {};
	query(int x, int y, int z) : id(x), a(y), b(z) {};
};

bool comp(query a, query b) {
	return a.b < b.b;
}

void upd(int pos, int delta) {
	while (pos < N+1) {
		bit[pos] += delta;
		pos += pos & -pos;
	}
}

int sum(int i) {
	int res = 0;
	while (i) {
		res += bit[i];
		i -= i & -i;
	}
	return res;
}

int sum(int i, int j) {
	return sum(j) - sum(i-1);
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> Q;
    rep(i,1,N+1) cin >> arr[i];

	vector<query> q;

	rep(i,1,Q+1) {
		int a, b;
		cin >> a >> b;
		q.emplace_back(i,a,b);
	}	

	sort(q.begin(), q.end(), comp);

	int cur = 0;

	map<int, int> m;
	rep(i,1,N+1) {
		auto it = m.find(arr[i]);
		if (it != m.end()) 
			upd(it->S, -1);		
		upd(i, +1);
		m[arr[i]] = i;
		while (cur < Q && q[cur].b == i) {
			ans[q[cur].id] = sum(q[cur].a, q[cur].b);
			cur++;
		}
	}

	rep(i,1,Q+1) cout << ans[i] << endl;
    return 0;
}








