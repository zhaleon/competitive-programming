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

int N, T;
int times[10000];

bool works(int k) {
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < k; i++) {
		q.push(times[i]);
	}
	int cur = k;

	int t = 0;
	while(!q.empty()) {
		t = q.top(); q.pop();
		if (cur < N) {
			q.push(times[cur]+t);
			cur++;
		}
	}
	return t <= T;
}

int main() {
	setIO("cowdance");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> T;
    
	rep(i,0,N) {
		cin >> times[i];
	}

	int low = 1, high = N;

	while (low + 1 < high) {
		int mid = (low + high)/2;
		if (works(mid)) {
			high = mid;
		} else {
			low = mid;
		}
	}

	cout << high << endl;

    return 0;
}
















