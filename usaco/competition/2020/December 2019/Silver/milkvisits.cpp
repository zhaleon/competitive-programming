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
string pref;

int farm[100001];
vi adj[100001];

void floodfill(int s, int g) {
	farm[s] = g;
	rep(i,0,adj[s].size()) {
		if (!farm[adj[s][i]]) {
			floodfill(adj[s][i], g);
		}
	}
}

int main() {
	setIO("milkvisits");
    ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M >> pref;

	int a, b;
	rep(i,0,N-1) {
		cin >> a >> b;
		if (pref[a-1] == pref[b-1]) {
			adj[a].PB(b);
			adj[b].PB(a);
		}
	}	
	int group = 1;
	rep(i,1,N+1) {
		if (!farm[i]) {
			floodfill(i, group);
			group++;
		}
	}
    
	int A, B;
	char C;

	rep(i,0,M) {
		cin >> A >> B >> C;
		if (farm[A] != farm[B]) {
			cout << 1;
		} else if (C == pref[A-1]) {
			cout << 1;
		} else {
			cout << 0;
		}
	} cout << endl;
    return 0;
}








