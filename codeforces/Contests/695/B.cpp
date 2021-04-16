#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)

int T, N;
int a[300001];

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> N;
		rep(i,1,N) cin >> a[i];

		int original = 0;
		int best = INF; 

		rep(i,2,N-1) original += (a[i] > a[i-1] && a[i] > a[i+1]) || (a[i] < a[i-1] && a[i] < a[i+1]);

		best = max(original-1, 0);

		rep(i,2,N-1) {
			int score = original;
			int add = 0;

			if ((a[i] > a[i-1] && a[i] > a[i+1]) || (a[i] < a[i-1] && a[i] < a[i+1])) 
				--score;	

			if (i != 2) {
				--i;
				if ((a[i] > a[i-1] && a[i] > a[i+1]) || (a[i] < a[i-1] && a[i] < a[i+1])) 
					--score;
				++i;
			}

			if (i != N-1) {
				++i;
				if ((a[i] > a[i-1] && a[i] > a[i+1]) || (a[i] < a[i-1] && a[i] < a[i+1])) 
					--score;	
				--i;
			}

			rep(j,0,1) {
				int temp = a[i];
				a[i] = a[i-1 + 2*j];	


				if (i != 2) {
					--i;
					if ((a[i] > a[i-1] && a[i] > a[i+1]) || (a[i] < a[i-1] && a[i] < a[i+1])) 
						++add;
					++i;
				}

				if (i != N-1) {
					++i;
					if ((a[i] > a[i-1] && a[i] > a[i+1]) || (a[i] < a[i-1] && a[i] < a[i+1])) 
						++add;	
					--i;
				}

				best = min(best, score + add);
				a[i] = temp;
				add = 0;
			}
		}

		cout << best << endl;
	}
    
    return 0;
}








