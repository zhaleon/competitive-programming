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
int arr[100000];
int after[10000]; //sorted version

int main() {
	setIO("sort");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	rep(i,0,N) { 
		cin >> arr[i];
		after[i] = arr[i];
	}
	int ans = 0;

	sort(after, after+N);
	//rep(i,0,N) cout << after[i] << ' ';
	for (int i = 0; i < N; i++) {
		int low = 0, high = N;
		while (low+1 < high) {
			int mid = (low+high)/2;
			if (after[mid] <= arr[i]) {
				low = mid;
			} else {
				high = mid;
			}
		}
		
		ans = max(ans, i-low);
	}
	cout << ans + 1 << endl;
    return 0;
}








