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


int mountains[100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
   	int T;
	cin >> T;
	int Case = 1;
	while (T--) {
		int N;
		cin >> N;

		loop(i,0,N) {
			cin >> mountains[i];
		}
		int ans = 0;

		loop(i,1,N-1) {
			if (mountains[i] > mountains[i-1] && mountains[i] > mountains[i+1]) {
				ans++;
			}
		}
		cout << "Case #" << Case << ": " << ans << endl;


		Case++;
	}

		

    return 0;
}








