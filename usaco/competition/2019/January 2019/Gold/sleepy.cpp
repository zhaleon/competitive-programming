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

int arr[100001];

int bit[100001];

void upd(int pos) {
	while (pos < N+1) {
		bit[pos]++;
		pos += pos & -pos;
	}
}

int sum(int i) {
	int res = 0;
	while (i > 0) {
		res += bit[i];
		i -= i & -i;
	}
	return res;
}

int main() {
	setIO("sleepy");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	
	rep(i,1,N+1) cin >> arr[i];

	int k = 1;
	upd(arr[N]);
	
	for (int i = N-1; i > 0; i--) {
		if (arr[i] < arr[i+1]) {
			k++;
			upd(arr[i]);
		} else {
			break;
		}
	}
	int finished = k;
	cout << N-finished << endl;
	
	rep(i,1,N-finished+1) {
		int jump = N-k-1;
		jump += sum(arr[i]);
		cout << jump; 
		if (i < N-finished) cout << ' ';
		else cout << endl;
		upd(arr[i]);
		k++;
	}
	
    return 0;
}