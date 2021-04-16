#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <fstream>
#include <assert.h>
#include <string>
#include <math.h>
#include <deque>


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int> > vii;
typedef vector<int> vi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define loop(i,a,b) for (int i = a; i < b; i++)

int n;
string x;

ofstream fout ("whereami.out");
ifstream fin ("whereami.in");

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    fin >> n >> x;
    
    int answer = -1;
    
    for (int i = 1; i <= x.length(); i++) {
        string curAttempt;
        bool works = true;
        for (int k = 0; k < x.length()-i+1; k++) {
            curAttempt = x.substr(k, i);
            for (int j = 0; j < x.length()-i+1; j++) {
                if (j == k) continue;
                if (curAttempt == x.substr(j, i)) {
                    works = false;
                    break;
                }
            }
        }
        if (works) {
            answer = (int)curAttempt.length();
            break;
        }
    }
    fout << answer << endl;
    
    return 0;
}



