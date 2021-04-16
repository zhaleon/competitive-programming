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
pii shifts[200000];
pii original[200000];

int best[100000]; //most time alone

int main() {
	setIO("lifeguards");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;


	rep(i,0,2*N) {
		cin >> shifts[i].F;
		shifts[i].S = (i - i%2)/2;
		original[i] = shifts[i];
	}
    
	sort(shifts, shifts+2*N);

	set<int> s;

	int small = INF, total = 0, t = 0;
	int f = 0;
	rep(i,0,2*N) {
		int cur = shifts[i].S;
		if (s.size() == 1) {
			best[*s.begin()] += shifts[i].F - t;
			//small = min(small, shifts[i].F-t);
		}

		if (s.find(cur) == s.end()) {
			if (s.size() == 0) f = shifts[i].F;
			s.insert(cur);
		} else {
			if (s.size() == 1) total += (shifts[i].F-f);
			s.erase(s.find(cur));
		}
		t = shifts[i].F;
	}
	rep(i,0,N) small = min(small, best[i]);
	cout << total-small << endl;
    return 0;
}








