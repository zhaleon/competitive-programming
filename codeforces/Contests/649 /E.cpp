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

int p[2049];
int x[2048][2048];

int query(int a, int b) {
	int ans;
	cout << "?" << ' ' << a << ' ' << b << endl;
	cin >> ans;
	return ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
    for (int i = 0; i < n-1; i++) {
		p[i] = query(i,i+1);
		x[i][i+1] = p[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = i+2; j < n; j++) {
			x[i][j] = x[i][j-1] ^ p[j-1];
		}
	}
	cout << x[0][2] << endl;
	int a = 0;
	for (int i = 1; i < n; i++) {
		a ^= i;
	}

	for (int i = 0; i < n; i++) {
		int guess = 0;
		if (n % 2 == 0) {
			for (int j = 0; j < n; j+=2) {
				guess ^= p[j];
			}
		} else {
			for (int j = 0; j < n-1; j+= 2) {
				guess ^= p[j];
			}
			guess ^= x[i][n-2];
		}
		cout << a << ' ' << guess << endl;
		if (guess == a) {
			string ans = "! ";
			for (int j = 0; j < n; j++) {
				if (j == i) ans += "0 ";
				else ans += to_string(x[i][j]) + " ";
			}
			cout << ans << endl;
			break;
		}

	}


    return 0;
}








