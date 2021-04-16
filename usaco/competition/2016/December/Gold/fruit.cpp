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

int T, A, B;

bool v[(int)5e6+1];


void search(int x, bool water) {
	v[x] = 1;
	if (x + A <= T && !v[x+A]) search(x+A, water);
	if (x + B <= T && !v[x+B]) search(x+B, water);
	if (!water && !v[x/2]) search(x/2, 1);
}

int main() {
	setIO("feast");
    ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> T >> A >> B;

    search(0, 0);
	
	for (int i = 5000000; i >= 0; i--) {
		if (v[i]) {
			cout << i << endl;
			return 0;
		}
	}


    return 0;
}








