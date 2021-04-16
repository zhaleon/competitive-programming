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
int n;
pii g[(1 << 15)];
vi adj[(1 << 15)];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int edges = 0;
	rep(i,0,n) {
		cin >> g[i].F >> g[i].S;
		edges += g[i].F;
		if (g[i].F == 1) {
			
		}
	}
	cout << edges/2 << endl;
    
    return 0;
}








