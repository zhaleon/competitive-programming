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

int main() {
	setIO("alchemy_input");
    //ios::sync_with_stdio(0); cin.tie(0);

	cin >> t;
	int Case = 1;
	int n;
	string s;
	
	while(t--) {
		cin >> n >> s;
		
		int a = 0, b = 0;
		
		rep(i,0,n) {
			if (s[i] == 'A') a++;
			else b++;
		}
		
		cout << "Case #" << Case << ": ";
		
		if (abs(a-b) == 1) {
			cout << "Y" << endl;
		} else {
			cout << "N" << endl;
		}
		
		
		Case++;
		
	}
   			
    return 0;
}








