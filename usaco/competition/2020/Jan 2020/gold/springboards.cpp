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
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> P;
	
	rep(i,1,P+1) {
		ll a,b,c,d;
		cin >> a >> b >> c >> d;
		springs.PB(spring(a,b,i));
		springs.PB(spring(c,d,-i));
	}

	sort(springs.begin(), springs.end());

	map<ll, ll> m;
	m[0ll] = 0ll;
	for (spring cur : springs) {
		if (cur.idx > 0) { //start of spring
			auto it = prev(m.upper_bound(cur.y)); //first spring ending with lower y-val
			ll saved = it->S;
			best[cur.idx] = cur.x + cur.y - saved; //subtract time saved     
		} else {
			ll saved = cur.x + cur.y - best[-cur.idx]; // time saved
			
			auto it = prev(m.upper_bound(cur.y)); //largest y but still lower
			if (it->S >= saved) continue;
			it++;
			m[cur.y] = saved;
			while (it != m.end() && it->S < saved) m.erase(it++); //try to keep monotonic
		}
	}
	
	ll saved = 0;
	
	for (auto s : m) saved = max(s.S, saved);
	
	cout << 2*N-saved << endl;
	
    return 0;
}