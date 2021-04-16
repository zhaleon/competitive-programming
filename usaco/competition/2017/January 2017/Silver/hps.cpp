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

int h[100000];
int p[100000];
int s[100000];

int best(int a, int b, int c) {
	return max(a, max(b,c));
}

int main() {
	setIO("hps");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	
	char a;
	rep(i,0,N) {
		cin >> a;
		if (a == 'H') h[i]++;
		if (a == 'P') p[i]++;
		if (a == 'S') s[i]++;
		if (i > 0) {
			h[i] += h[i-1];
			p[i] += p[i-1];
			s[i] += s[i-1];
		}
	}
    
	int ans = 0;

	rep(i,0,N) {
		ans = max(ans, best(h[i], p[i], s[i]) + best(h[N-1]-h[i], p[N-1]-p[i], s[N-1]-s[i]));
	}

	cout << ans << endl;

    return 0;
}








