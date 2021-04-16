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

string spots[500];
string plain[500];

bool works(int K) {
	bool good;
	rep(i,0,M-K+1) {
		good = true;
		set<string> s;
		rep(j,0,N) s.insert(spots[j].substr(i, K));
		rep(j,0,N) if (s.find(plain[j].substr(i,K)) != s.end()) good = false;
		if (good) return true;
	}
	return false;
}

int main() {
	setIO("cownomics");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	
	rep(i,0,N) cin >> spots[i];
	rep(i,0,N) cin >> plain[i]; 	

	int low = 0, high = M;
	
	while (low+1 < high) {
		int mid = (low+high)/2;
		if (works(mid)) {
			high = mid;
		} else {
			low = mid;
		}
	}
	

	cout << high << endl;

    return 0;
}