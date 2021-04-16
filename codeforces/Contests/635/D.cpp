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
int r[100001];
int g[100001];
int b[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> t;
	while(t--) {
		int R, G, B; 
		cin >> R  >> G  >> B;
		loop(i,0,R) cin >> r[i];
		loop(i,0,G) cin >> g[i];
		loop(i,0,B) cin >> b[i];
		sort(r, r+R);
		sort(g, g+G);
		sort(b, b+B);

		ll ans=0;
		cout << "HI" << ' ' << r[0] << ' ' << g[0] << ' ' << b[0] << '\n';

		ans += (r[0]-g[0])*(r[0]-g[0]);
		ans += (g[0]-b[0])*(g[0]-b[0]);
		ans += (b[0]-r[0])*(b[0]-r[0]);
		cout << ans << endl;
	}

    
    return 0;
}








