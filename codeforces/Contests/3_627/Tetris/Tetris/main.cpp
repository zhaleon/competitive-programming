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

int T, N;

int main() {
    cin >> T;
    int d, start;
    for (int i = 0; i < T; i++) {
        cin >> N;
        bool works = true;
        for (int j = 0; j < N; j++) {
            cin >> d;
            if (j == 0) {
                start = d % 2;
            } else {
                if (d % 2 != start) works = false;
            }
        }
        if (works) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}



