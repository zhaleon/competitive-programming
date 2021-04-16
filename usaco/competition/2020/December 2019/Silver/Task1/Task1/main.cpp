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

ofstream fout ("moobuzz.out");
ifstream fin ("moobuzz.in");

int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fin >> N;
    
//FIX MULTIOPLES OF 8
    //FIX MULTIOPLES OF 8
    //FIX MULTIOPLES OF 8
    //FIX MULTIOPLES OF 8
    
    
    int counter = 1;
    int x = N % 8;
    int i;
    
    for (i = (N/8)*15+1; counter <= x; i++) {
        if (i % 3 != 0 && i % 5 != 0) {
            counter++;
        }
    }
    
    if (N % 8 == 0) {
        i--;
    }
    
    fout << i - 1 << endl;
    return 0;
}



