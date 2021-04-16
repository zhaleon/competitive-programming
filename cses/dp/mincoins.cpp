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

int c[100];
int n, x;
int ways[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> x;
	loop(i,0,n) {
		cin >> c[i];
	}
	ways[0] = 1;

	loop(i,0,1000001) {
		loop(j,0,n) {
			if (i - c[j] >= 0 && ways[i-c[j]]>0) {
				if (ways[i] == 0) ways[i] = ways[i-c[j]]+1;
				else ways[i] = min(ways[i], ways[i-c[j]]+1);
			}

		}
	}
	if (ways[x] == 0) {
		cout << -1 << '\n';
		return 0;
	}

	cout << ways[x]-1 << '\n';

    
    return 0;
}








