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

int n;
const int mod = 1e9 + 7;
int ways[1000007];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n;
	ways[0]=1;	
	for (int i = 0; i <= 1000000; i++) {
		for (int j = 1; j<= 6; j++) {
			ways[i+j] += ways[i];
			ways[i+j] %= mod;
		}
	}
	cout << ways[n] << endl;

    return 0;
}








