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

#warning Remember to try big N, overflows, edge cases

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);
	
    int x = atoi(argv[1]);
	srand(x);
    
    cout << 1 << endl;
    cout << 20 << ' ' << 100 << endl;

    vector<int> nums(20);
    iota(nums.begin(), nums.end(), 0);
    shuffle(nums.begin(), nums.end(), default_random_engine(x));

    rep(i,0,19) cout << nums[i] << " \n"[i == 19];
    return 0;
}








