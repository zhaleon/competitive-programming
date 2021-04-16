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

int ways[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n; cin >> n;
	
	ways[n] = 1;
	for (int i = n; i >= 0; i--) {
		int a = i;
		if (ways[i] == 0) continue;
		while (a > 0) {
			if (i>=(a%10)) {
				if (ways[i-a%10] == 0) ways[i-a%10] = ways[i]+1;
				else ways[i-(a%10)] = min(ways[i]+1, ways[i-a%10]);
			}
			a/= 10;
		}
	}

	cout << ways[0]-1 << endl;
    for (int i = 0; i < 28; i++) {
		//cout <<  i << ' ' << ways[i] << endl;
	}

    return 0;
}








