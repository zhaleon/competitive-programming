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

int z[100001];
int f[100001];
int b[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, Q;
	cin >> N >> Q;
	loop(i,1,N+1) cin >> z[i];
	f[1] = z[1];
	loop(i,2,N+1) f[i] = z[i] + f[i-1]; 
	b[N] = z[N];
	for (int i = N-1; i > 0; i--) {
		b[i] = z[i] + b[i+1];
	}
	loop(i,1,N+1) cout << b[i] << endl;
	int a, x;
	for (int i = 0; i < Q; i++) {
		cin >> a >> x;
		cout << min(abs(f[x]-f[a]), abs(b[x] - b[a])) << endl;
	}


    return 0;
}








