/*
ID: lionz202
TASK: heritage
LANG: C++
*/
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

ifstream fin ("heritage.in");
ofstream fout ("heritage.out");

string a, b;

class node
{
public:
    char val;
    node* left;
    node* right;
};

node* newNode(char v) {
    node* Node = new node();
    Node->val = v;
    Node->left = NULL;
    Node->right = NULL;
    return Node;
};

node* makeTree(string pre, string in, int i, int j) {
    static int preIndex = 0;
    if (i > j) return NULL;
    
    node* x = newNode(pre[preIndex]);
    preIndex++;
    if (i == j) return x;
    
    int root = -1;
    loop(i, 0, in.length()) {
        if (in[i] == x->val) {
            root = i;
            break;
        }
    }
    x->left = makeTree(pre, in, i, root-1);
    x->right = makeTree(pre,in, root+1, j);
    
    return x;
}

void post(node* root) {
    if (root == NULL) return;
    
    post(root->left);
    post(root->right);
    fout << root->val;
}

int main() {
    fin >> a >> b;
    
    node* root = makeTree(b, a, 0, a.length()-1);
    post(root);
    fout << endl;
    
    
    fin.close();
    fout.close();
    return 0;
}



