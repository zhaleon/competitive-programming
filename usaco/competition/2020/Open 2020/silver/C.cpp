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
pii p[100000];
int lows[100000];
int highs[100000];

bool comparator(pii a, pii b) {
	if (a.F == b.F) return a.S > b.S;
	return a.F < b.F;
}

int main() {
	//setIO("moop");
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
    rep(i,0,N) cin >> p[i].F >> p[i].S;
	
	sort(p, p+N, comparator);
	lows[0] = p[0].S; highs[N-1] = p[N-1].S;
	
	rep(i,1,N) 
		lows[i] = min(lows[i-1], p[i].S);	
		
	for (int i = N-2; i >= 0; i--) 
		highs[i] = max(highs[i+1], p[i].S);
	

	int components = 0;
	
	for (int i = N-1; i >= 0; i--) {
		if (i == N-1) 
			components++;
		else if (p[i].F != p[i+1].F && lows[i] > highs[i+1]) 
			components++;
	}

	cout << components << endl;

    return 0;
}








