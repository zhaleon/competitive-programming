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

int T;
int nums[2000000];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> T;
	int Case = 1;
	int N, K;
	while (T--) {
		cin >> N >> K;
		loop(i,0,N) {
			cin >> nums[i];
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			if (nums[i] == K) {
				bool works = 1;
				int j;
				for (j = i; j < i+K && j < N; j++) {
					if (nums[j] != i-j+K) {
						works = 0;
						break;
					}
				}
				i = j;
				if (nums[j] == K) {
					i--;
				}

				if (works) ans++;
				//cout <<"HI" << endl;
			}

		}

		cout << "Case #" << Case << ": " << ans << '\n';
		Case++;		

	}

    
    return 0;
}








