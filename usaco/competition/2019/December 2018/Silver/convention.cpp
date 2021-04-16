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

int N, M, C;
int t[100000];

bool works(int T) {
	int cows = 0;
	rep (i,0,M) {
		if (cows >= N) return true;
		int early = t[cows];
		cows++;
		rep(j,0,C-1) {
			if (t[cows] - early <= T) cows++;
			else break;
		}
	}
	return cows >= N;
}

int main() {
	setIO("convention");
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> C;

	rep(i,0,N) {
		cin >> t[i];
	}

	sort(t, t+N);
    
	int l = 1, h = 1e9;
	while (l + 1 < h) {
		int mid = (l+h)/2;
		if (works(mid)) {
			h = mid;	
		} else {
			l = mid;
		}
	}

	cout << h << endl;

    return 0;
}








