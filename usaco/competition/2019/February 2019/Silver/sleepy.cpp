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
int pos[100000];
unordered_map<int, int> m;

int numCows(int left) {
	int l = left, h = N-1;

	while(l < h) {
		int mid = (l+h+1)/2;
		if (pos[mid] < pos[left]+N) {
			l = mid;
		} else {
			h = mid-1;
		}
	}
	return l-left+1;
}

int main() {
	setIO("herding");
    ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
	rep(i,0,N) {
		cin >> pos[i];
		m[pos[i]] = 1;
	}

	sort(pos, pos+N);

	int most = 0, least = INF;
	
	rep(i,0,N-1) {
		int a = numCows(i);
		if (a == N) {
			cout << 0 << endl << 0 << endl;
			return 0;
		}

		if (a == N-1 && !m[pos[i]+N-1] && !m[pos[i]-2]) least = 2;
		else least = min(least, N-a);
	}

	most = max(pos[N-1] - pos[1]-N+2, pos[N-2] - pos[0]-N+2); 

	cout << least << endl << most << endl;
    
    return 0;
}








