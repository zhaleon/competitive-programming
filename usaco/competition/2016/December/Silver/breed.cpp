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

int N, Q;

int id[100001];

int h[100001];
int g[100001];
int j[100001];

int main() {
	setIO("bcount");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> Q;

	rep(i,1,N+1) cin >> id[i];

	rep(i,1,N+1) {
		if (id[i] == 1) h[i]++;
		else if (id[i] == 2) g[i]++;
		else j[i]++;
		
		h[i] += h[i-1];
		g[i] += g[i-1];
		j[i] += j[i-1];
	}

	int a, b;

	rep(i,0,Q) {
		cin >> a >> b;
		cout << h[b] - h[a-1] << ' ' << g[b] - g[a-1] << ' ' << j[b] - j[a-1] << endl;
	}
	
    return 0;
}








