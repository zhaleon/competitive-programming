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

ll N;
string s;

ll it = 1;

char comp(ll N) {
	if (N < s.length()) {
		return s[N];
	}
	
	ll l = it*s.length();
	
	if (N < l/2) {
		it/=2;
		return comp(N);
	} else {
		if (N == l/2) {
			return comp(N-1);
		}
		return comp(N-l/2-1);
	}


}

int main() {
	setIO("cowcode");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> s >> N;
    
	while (it * s.length() < N) {
		it *= 2;
	}

    cout << comp(N-1) << endl;
	
	return 0;
}








