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

pii h[1000000];

int bit[1000001];

void upd(int pos, int size) {
	while (pos < size) {
		bit[pos] += 1;
	    pos += pos & -pos;	
	}
}


int s(int i) {
	int sum = 0;
	while (i > 0) {
		sum += bit[i];
		i -= i & -i;
	}
	return sum;
}

int sum(int i, int j) {
	return s(j) - s(i-1);
}

bool comp(pii a, pii b) { return a.F > b.F; }

int main() {
	setIO("bphoto");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
    
	rep(i,0,N) {
		cin >> h[i].F;
		h[i].S = i+1;
	}
	sort(h, h+N, comp); 
	
	int ans = 0;

	rep(i,0,N) {
		upd(h[i].S, N+1);
			
		int L = sum(1, h[i].S-1);
		int R = sum(h[i].S+1, N);
		if (max(L,R) > 2*min(L,R)) ans++;
	}

	cout << ans << endl;

    return 0;
}








