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

int barn[1001][1001];
int N, K;


int main() {
	setIO("paintbarn");
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;

	int a,b,c,d;
	rep(i,0,N) {
		cin >> a >> b >> c >> d;
		barn[c][d]++;
		barn[a][b]++;
		barn[c][b]--;
		barn[a][d]--;
	}

	int area = 0;

	for (int y = 1000; y > 0; y--) {
		for (int x = 1000; x > 0; x--) {
			barn[x-1][y] += barn[x][y];
		}
	}
	for (int x = 1000; x > 0; x--) {
		for (int y = 1000; y > 0; y--) {
			barn[x][y-1] += barn[x][y];
		}
	}	
    
	for (int y = 1000; y >= 1; y--) {
		for (int x = 1; x <= 1000; x++) {
			if (barn[x][y] == K) area++;
		}
	}


	cout << area << endl;

    return 0;
}








