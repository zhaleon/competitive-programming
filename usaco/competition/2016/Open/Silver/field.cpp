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

int N;

pii x[50000];
pii y[50000];

vpi high;
vpi low;
vpi lef;
vpi righ;

bool comp(pii a, pii b) {
	return a.S < b.S;
}

int main() {
	setIO("reduce");
    ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
    
	rep(i,0,N) {
		cin >> x[i].F >> x[i].S;
		y[i].F = x[i].F;
		y[i].S = x[i].S;
	}

	sort(x, x+N);
	sort(y, y+N, comp);

	rep(i,0,4) {
		high.PB(y[N-1-i]);
		low.PB(y[i]);
		righ.PB(x[N-1-i]);
		lef.PB(x[i]);
	}	

	int area = INT_MAX;
	for (int a = 0; a < 4; a++) {
		for (int b = 0; b < 4; b++) {
			for (int c = 0; c < 4; c++) {
				for (int d = 0; d < 4; d++) {
					pii h = high[a];
					pii lo = low[b];
					pii r = righ[c];
					pii le = lef[d];
					
					int in = 0;
					for (int i = 0; i < N; i++) {
						if (x[i].F <= r.F && x[i].F >= le.F && x[i].S <= h.S && x[i].S >= lo.S) in++; 
					}

					if (in >= N-3) {
						area = min(area, abs(lo.S-h.S) * abs(le.F - r.F));
						//cout << lo.S << ' ' << h.S << ' ' << le.F << ' ' << r.F << endl;
					}	
				}
			}
		}
	}

	cout << area << endl;

    return 0;
}








