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
	
	srand(atoi(argv[1]));

    cout << 1 << '\n';
    
    cout << rand() % 100 + 1 << ' ' << rand() % 100 + 1 << ' ';
    string s = "";

    rep(i,1,10) {
        int k = rand() % 100;
        if (k < 25) s += "C";
        else if (k < 50) s += "J";
        else s += "?";
    }

    cout << s << endl;
    return 0;
}








