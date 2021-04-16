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

void setIO(string name) {
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
}
int n;
int arr[(int)1e5];

bool comp(int a, int b) {
	if (a + b % 2 == 0) return b > a;
	return a < b;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	bool parity = 0;
	bool good = 0;
	loop(i,0,n){ cin >> arr[i];
		if (i == 0) parity = arr[i] % 2;
		else if (parity != arr[i]%2) good = 1;
	}	
	if (good)sort(arr, arr+n);
    

	loop(i,0,n) cout << arr[i] << ' ';
	cout << endl;
    return 0;
}








