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

int N, total = 0;

pii p[201];
int dist[201];
int soFar[201];

int main() {
	setIO("lightsout");
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
	rep(i,0,N) cin >> p[i].F >> p[i].S;

	vi a(1, 0);
	
	rep(i,0,N) {
		int j = (i+1)%N;
		int k = (i+2)%N;
		int direction = ((p[i].F - p[j].F)*(p[k].S - p[j].S) > (p[k].F - p[j].F) * (p[i].S - p[j].S)) ? 1 : 2;
		int d = abs(p[i].F - p[j].F) + abs(p[i].S - p[j].S);
		total += d;
		a.PB(d);
		a.PB(direction);
	}
	a.back() = 0;
	
	int t = 0;
	rep(i,1,N) {
		t += abs(p[i].F - p[i-1].F) + abs(p[i].S - p[i-1].S);
		dist[i] = min(t, total - t);
		soFar[i] = t;
	}
	soFar[0] = soFar[N] = total;
	
	multiset<vector<int> > st;
	
	for (int i = 0; i < a.size(); i += 2) {
		for (int j = 1; j + i <= a.size(); j += 2) {
			st.insert(vi(a.begin()+i, a.begin()+i+j));
		}
	}
	
	int ans = 0;
	for (int i = 2; i + 2 < a.size(); i+=2) {
		int cost = 0;
		int moved;
		for (int j = 1; ; j += 2) {
			if (st.count(vi(a.begin()+i, a.begin()+i+j)) == 1 || i+j/2 >= N) {
				moved = j;
				break;
			}
			cost += a[i + j];
		}
		ans = max(ans, abs(dist[i / 2] - (soFar[(i + moved) / 2] - soFar[i / 2] + dist[ (i+moved) / 2])));
	}

	cout << ans << endl;	

	
    return 0;
}








