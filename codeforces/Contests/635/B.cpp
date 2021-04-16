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

int t;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> t;
	while(t--) {
		int x, n, m;
		cin >> x >> n >> m;

		loop(i,0,n) {
			if (x/2 + 10 > x) break;
			x /= 2;
			x += 10;
		}
		if (x <= m*10) {
			cout << "YES" << '\n';	
		} else {
			cout << "NO" << '\n';
		}

	}


    
    return 0;
}








