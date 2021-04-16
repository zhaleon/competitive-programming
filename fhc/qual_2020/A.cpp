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
	freopen((name+".txt").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
}

int t;

int n;
string I, O;

int adj[50][50];

int dist[50][50];

void reset() {
	rep(i,0,n) {
		rep(j,0,n) {
			if ((abs(i-j) == 1 && (O[i] == 'Y' && I[j] == 'Y')) || i == j) adj[i][j] = 1;
			else adj[i][j] = INF;
		}
	}
}

int main() {
	setIO("travel_restrictions_input");
    //ios::sync_with_stdio(0); cin.tie(0);

	cin >> t;
	int Case = 1;
	
	while(t--) {
		cin >> n >> I >> O;
		
		memset(adj, 0, sizeof(adj));
		
		reset();
				
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					if (adj[j][i] + adj[i][k] < adj[j][k]) {
						adj[j][k] = adj[j][i] + adj[i][k];
					}
				}
			}
		}
		
		cout << "Case #" << Case << ":\n";
		rep(i,0,n) {
			rep(j,0,n) {
				if (adj[i][j] != INF) {
					cout << "Y";
					//cout << adj[i][j];
				}
				else cout << "N";
			} cout << endl;
		}
		Case++;
		
	}
   			
    return 0;
}








