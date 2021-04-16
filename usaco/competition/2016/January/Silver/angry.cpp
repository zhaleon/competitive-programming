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

int N, K;

int pos[50000];

bool works(int k) {
	int r = pos[0]+2*k, cur = 0;
	for (int i = 1; i < K; i++) {
		while (pos[cur] <= r && cur < N) cur++;
		if (cur == N) return 1;
		r = pos[cur] + 2*k;
	}
	if (r >= pos[N-1]) return 1;
	if (cur < N) return 0;
	return 1;
}

int main() {
	setIO("angry");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;

	rep(i,0,N) cin >> pos[i];
	sort(pos, pos+N);
    
	int low = 0, high = 1e9;
	
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








