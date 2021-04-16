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


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pair<int, int>, int> piii;
typedef vector<vector<int> > vii;
typedef vector<pair<int, int> > vpi;
typedef vector<int> vi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define loop(i,a,b) for (int i = a; i < b; i++)

int t;

int main() {
    cin >> t;
    
    int a, b;
    loop(i,0,t) {
        cin >> a >> b;
        int low = 0, high = a-1;
        
        while (low < high) {
            int mid = (low+high)/2;
            if (mid*(mid+1) >= 2*b) {
                high = mid;
            } else {
                low = mid+1;
            }
        }
        
        string ans = "";
        loop(i,0,a) {
            
            if (i == a-(high+1) || i == (a-(high+1) + ((high+1)*high/2-b)+1)) {
                ans += "b";
            } else {
                ans += "a";
            }
        }
        cout << ans << '\n';//' ' << high <<' ' << b <<  ' ' << (a-(high+1) + ((high+1)*high)/2+1-b) << '\n';
        
    }
    return 0;
}



