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
map<int, int> delta;

int main() {
	setIO("teleport");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	int a,b;
	ll curVal = 0;
    rep(i,0,N) {
		cin >> a >> b;
		curVal += abs(a-b);
		if (abs(a) > abs(a-b)) continue;
		delta[b] += 2;
		if (a < 0 && a < b) {
			delta[0]--;
			delta[2*b]--;
		}
		if (a >= 0 && a < b) {
			delta[2*a]--;
			delta[2*b-2*a]--;
		}
		if (a < 0 && a >= b) {
			delta[2*a]--;
			delta[2*b-2*a]--;
		}
		if (a >= 0 && a >= b) {
			delta[0]--;
			delta[2*b]--;
		}
	}
	ll curMin = curVal;
	
	ll curY = -1e8, curSlope = 0;
	for (auto crit : delta) {
		int tempY = crit.F;
		curVal += curSlope * (tempY - curY);
		curMin = min(curMin, curVal);
		curSlope += crit.S;
		curY = tempY;
	}

	cout << curMin << endl;
    return 0;
}








