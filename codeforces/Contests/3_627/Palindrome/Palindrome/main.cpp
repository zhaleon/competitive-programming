#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <bitset>
#include <deque>


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> piii;
typedef vector<vector<int>> vii;
typedef vector<int> vi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define loop(i,a,b) for (int i = a; i < b; i++)

int t, n;
int input[5000];


int main() {
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> input[j];
        }
        bool works = false;
        for (int a = 0; a < n; a++) {
            for (int b = n-1; b > a+1; b--) {
                if (input[b] == input[a]) {
                    works = true;
                    break;
                }
            }
            if (works) break;
        }
        if (works) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}



