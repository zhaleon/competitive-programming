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

int d[1000];

int main() {
	
	ifstream cin ("nfc.in");
	ofstream cout ("nfc.out");
	cin >> N >> K;

	rep(i,0,N) {
		cin >> d[i];
	}
    
	int dif = INF;
	int l, r;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (d[i] + d[j] == K && j+i < dif) {
				dif = j+i;
				l = i; r = j;
			}
		}
	}

	cout << l+1 << ' ' << r+1 << endl;

    return 0;
}








