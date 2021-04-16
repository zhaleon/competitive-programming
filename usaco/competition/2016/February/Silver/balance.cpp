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

pii p[1000];
pii d[1000];


bool comp(pii a, pii b) {
	return a.S < b.S;
}

int main() {
	setIO("balancing");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	
	rep(i,0,N) cin >> p[i].F >> p[i].S;
	rep(i,0,N) {
		d[i].F = p[i].F;
		d[i].S = p[i].S;
	}

	sort(p, p+N);
    sort(d, d+N, comp);

	int l = 0, r = N;
	int vert = 0;
	
	int ans = INF;

	rep(i,0,N) {
		int j = i;
		
		while (j < N && p[j].F == p[j+1].F) j++;

		int dt = j-i+1;
		vert = p[j].F + 1;
		
		l += dt;
		r -= dt;


		int l1 = l, r1 = r, l2 = 0, r2 = 0;
		rep(a,0,N) {		
			int b = a;

			while (b < N && d[b].S == d[b+1].S) {
				if (d[b].F < vert) {
					l1--; l2++;
				} else {
					r1--; r2++;
				}
				b++;
			}

			if (d[b].F < vert) {
				l1--; l2++;
			} else {
				r1--; r2++;
			}
			
			ans = min(ans, max( max(l1, l2), max(r1, r2) ));

			a = b;
		}	
		i = j;
	}


	cout << ans << endl;
    
	
	return 0;
}








