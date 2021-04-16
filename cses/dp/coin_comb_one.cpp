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
#define loop(i,a,b) for (int i = a; i < b; i++)

int n, x, c[100], ways[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
	loop(i,0,n) {
		cin >> c[i];
	}
	ways[0] = 1;
	const int mod = 1e9+7;
	for (int i = 0; i <= 1000000; i++) {
		for (int j = 0; j < n; j++) {
			if (i+c[j] <= 1000000) {
				ways[i+c[j]] += ways[i];
				ways[i+c[j]] %= mod;
			}

		}

	}
	cout << ways[x] << '\n';
		

    return 0;
}








