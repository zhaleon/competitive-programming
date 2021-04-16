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

int N, G;

pair<pii, int> updates[100000];

int milk[100001];

bool comp(pair<pii, int> a, pair<pii, int> b) {
	return a.F.F < b.F.F;
}

map<int, int, greater<int>> m;
map<int, int> numCows;

int main() {
	setIO("measurement");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> G;

	int a,b,c;

	rep(i,0,N) {
		cin >> a >> b >> c;
		updates[i] = MP(MP(a,b),c);
		m[b] = 0;
	}
	numCows[0] = N;
    

	sort(updates, updates+N, comp);

	//cout << "\n\n\n";
	int most = 0, numMost = 0, ans = 0;
	rep(i,0,N) {
		int amt = updates[i].S;
		int cur = updates[i].F.S;
		int x = ans;
		int after = m[cur] + amt;
		int now = m[cur];
		//cout << i << " WHAT: " << m[55] << endl;
		//cout << cur << " AMT " << amt << endl;
		//cout << now << ' ' << after << ' ' << most << endl;
		if (now == most && after > most) {
			if (numCows[now] > 1) { 
				ans++;	
			}
			numCows[now]--;
			numCows[after]++;
			most = after;
			m[cur] += amt;
		} else if (now == most) {
			m[cur] += amt;

			if (numCows[now] == 1) {
				//most = m.begin()->S;
				most = 0;
				for (auto temp : m) {
					most = max(most, temp.S);
				}
			}
			numCows[now]--;
			numCows[after]++;
			if (most == m[cur] && numCows[most] == 1) ans--;
			ans++;
		} else if (after >= most) {
			numCows[now]--;
			numCows[after]++;
			ans++;
			m[cur] += amt;
			most = after;
		} else {
			numCows[now]--;
			numCows[after]++;
			m[cur] += amt;
		}
		//if (x < ans) cout << updates[i].F.F << ' ' << cur << ' ' << amt << " MOST " << most << endl;
	}
	//cout << "\n\n\n";
	rep(i,0,N) {
		//cout << updates[i].F.F << ' ' << updates[i].F.S << ' ' << updates[i].S << endl;
	}	
	cout << ans << endl;

    return 0;
}








