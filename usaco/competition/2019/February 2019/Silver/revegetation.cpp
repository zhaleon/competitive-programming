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

int N, M;

vpi adj[100001];

int pastures[100001]; //component numbers
int feed[100001]; //try construction

void flood(int p, int g) {
	pastures[p] = g;
	rep(i,0,adj[p].size()) {
		if (!pastures[adj[p][i].F]) {
			flood(adj[p][i].F,g);
		}
	}
}


bool color(int p, int c) {
	feed[p] = c;
	bool works = 0;
	rep(i,0,adj[p].size()) {
		if (!feed[adj[p][i].F]) {
			if (!adj[p][i].S) color(adj[p][i].F, (c % 2) + 1);
			else color(adj[p][i].F, c);
		} else {
			if (adj[p][i].S && feed[p] != feed[adj[p][i].F]) return false;
		   	if (!adj[p][i].S && feed[p] == feed[adj[p][i].F]) return false;	
		}
	}
	return true;
}

int main() {
	setIO("revegetate");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	char a;
	int b, c;
	rep(i,0,M) {
		cin >> a >> b >> c;
		if (a == 'S') {
			adj[b].PB(MP(c,1));
			adj[c].PB(MP(b,1));
		} else {
			adj[b].PB(MP(c,0));
			adj[c].PB(MP(b,0));
		}
	}

    int group = 0;
	rep(i,1,N+1) {
		if (!pastures[i]) {
			group++;
			flood(i, group);
		}
	}
	
	rep(i,1,N+1) {
		if (!feed[i]) {
			if (!color(i, 1)) {
				group = 0;
				break;			
			}
		}
	}

	if (group == 0) {
		cout << 0 << endl;
	} else {
		cout << 1;
		rep(i,0,group) cout << 0;
		cout << endl;
	}	


    return 0;
}








