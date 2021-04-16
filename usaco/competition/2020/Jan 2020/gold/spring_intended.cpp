#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <fstream>
#include <assert.h>
#include <string>
#include <cstring>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <deque>
#include <cmath>
#include <set>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int> > vii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

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

int N, P;

ll best[100001];

typedef struct spring {
	ll x, y, idx;
	spring() {};
	spring(ll a, ll b, ll i) : x(a), y(b), idx(i) {};
	
	bool operator<(spring other) const {
		if (x == other.x) return y < other.y;
		return x < other.x;
	}
} spring;

vector<spring> springs;

int main() {
	setIO("boards");
    //ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> P;
	
	rep(i,1,P+1) {
		ll a,b,c,d;
		cin >> a >> b >> c >> d;
		springs.PB(spring(a,b,i));
		springs.PB(spring(c,d,-i));
	}

	sort(springs.begin(), springs.end());

	map<ll, ll> m;
	//m[100000000000000ll] = 0ll;
	m[0] = 0;
	for (spring cur : springs) {
		if (cur.idx > 0) { //start of spring
			auto it = prev(m.upper_bound(cur.y)); //first spring ending with lower y-val
			//auto it = m.begin();
			ll saved = it->S;
			best[cur.idx] = cur.x + cur.y + saved; //subtract time saved     
		} else {
			ll saved = best[-cur.idx] - cur.x - cur.y; // time saved
			auto it = prev(m.upper_bound(cur.y));
			if (it->S <= saved) continue;
			it++;
			while (it != m.end() && it->S > saved) m.erase(it++); //try to keep monotonic in second element
			m[cur.y] = saved;
		}
		//for (auto s : m) printf("(%lld,%lld) ", s.F, s.S); cout << endl << endl;
	}
	//for (auto s : m) printf("(%lld,%lld) ", s.F, s.S); cout << endl;
	ll saved = 0;
	
	for (auto s : m) {
		//cout << s.F << ' ' << s.S << endl;
		saved = min(s.S, saved);
	}
	
	//cout << "BEST " << best[2] << endl;
	
	cout << 2*N+saved << endl;
	
    return 0;
}