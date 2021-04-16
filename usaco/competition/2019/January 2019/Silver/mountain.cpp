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

pii mountains[100000];

bool comp(pii a, pii b) {
	if (a.F - a.S == b.F - b.S) return a.F + a.S > b.F + b.S;
	return a.F - a.S < b.F - b.S;
}

int N, ans = 0;

int main() {
	setIO("mountains");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	
	int a, b;
	rep(i,0,N) {
		cin >> a >> b;
		mountains[i] = MP(a,b);
	}

	sort(mountains, mountains+N, comp);
	
	int ans = 1;
	int right = mountains[0].F + mountains[0].S;
	
	rep(i,1,N) {
		if (mountains[i].F + mountains[i].S <= right) continue;
		else ans++;
		right = max(right, mountains[i].F + mountains[i].S);
	}

	cout << ans << endl;
    
    return 0;
}








