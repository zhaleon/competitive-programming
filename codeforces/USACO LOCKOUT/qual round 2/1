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
bool sieve[1000001];
int x, n[1000];
int one = 0, two = 0;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> x;
	loop(i,0,x) {
		cin >>n[i];
		if (n[i] == 1) one++;
		if (n[i] == 2) two++;
	}	
	memset(sieve, 1, sizeof(sieve));
    for (int p=2; p*p<=1e6; p++) 
    { 
        if (sieve[p] == true) 
        { 
            for (int i=p*p; i<=1e6; i += p) 
                sieve[i] = false; 
        } 
    }
	if (one > 1) {
		int prime = -1;
		for (int i = 0; i < x; i++) {
			if (n[i] > 1 && sieve[n[i]+1]) prime = n[i];
		}
		if (prime > 0) cout << one+1 << endl;
		else cout << one << endl;
		for (int i = 0; i < one; i++) cout << 1 << ' ';
		if (prime > 0) cout << prime;
		cout << endl;
		return 0;	
	}

	int a = -1, b = -1;

	loop(a,0,x) {
		loop(b,a+1,x) {
			if (sieve[n[a]+n[b]]) {
				cout << 2 << endl << n[a] << ' ' << n[b] << endl; 
				return 0;
			}
		}
	}
	
	loop(a,0,x) {
		if (sieve[a]) {
			cout << 1 << endl << n[a] << endl;
			return 0;
		}
	}
	cout << 0 << endl;
    return 0;
}








