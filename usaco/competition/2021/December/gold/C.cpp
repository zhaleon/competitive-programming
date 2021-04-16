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

int N;

vpi points;
map<int, int> m;

int bit[2501];

void upd(int pos) {
	while (pos < N+1) {
		bit[pos]++;
		pos += pos & -pos;
	}
}

int query(int i) {
	int res = 0;
	while (i) {
		res += bit[i];
		i -= i & -i;
	}
	return res;
}

int query(int i, int j) {
	if (j < i)
		swap(i,j);
	if (i == 0) return 0;
	return query(j) - query(i-1);
}

void compress(vpi &v) {
	for (int i = 0; i < v.size(); i++) 
		m[v[i].S];

	int ind = 0;

	for (auto &p : m)
		p.S = ++ind;
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
    
	rep(i,1,N) {
		int a, b;
		cin >> a >> b;
		points.emplace_back(a,b);
	}

	compress(points);
	sort(points.begin(), points.end());

	int ans = 0;

	for (int i = 0; i < points.size(); i++) {
		memset(bit, 0, sizeof(bit));
		set<int> s;

		++ans; //single element
		s.insert(points[i].S);

		for (int j = i-1; j >= 0; j--) {
		
			int len = points[i].F - points[i].F;
			int low = min(points[j].S, points[i].S);
			int high = max(points[j].S, points[i].S);

			auto it = s.lower_bound(high - len);

			int add = 0;
			if (it != s.end())
				for (;;) {
					auto nxt = next(it);

					if (nxt == s.end() || *it == low) 
						break;
					
					int up = *nxt;

					int num = 1 + query(m.lower_bound(*it + len)->S, (--m.lower_bound(up + len))->S);
					add += num;
					it = nxt;
				}

			ans += add;
			upd(m[points[j].S]);
			s.insert(points[j].S);
		}
		cout << i << ' ' << ans << endl;
	}

	cout << ans+1 << endl;

    return 0;
}

