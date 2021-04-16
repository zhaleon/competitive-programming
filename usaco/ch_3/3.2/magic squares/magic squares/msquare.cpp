/*
 ID: lionz202
 TASK: msquare
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <assert.h>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <bitset>
#include <map>

using namespace std;

ifstream fin("msquare.in");
ofstream fout("msquare.out");

bool skippable(string s, int& i) {
    // i = transformation number
    if (i == 0 && s.length() > 0 && s[(s.length()-1)] =='A') return 1;
    if (i == 1 && s.length() > 4 && s.substr(s.length()-3, 3).compare("BBB") == 0) return 1;
    if (i == 2 && s.length() > 4 && s.substr(s.length()-3, 3).compare("CCC") == 0) return 1;
    return 0;
}

bool comparator(string a, string b) {
    return a.compare(b) < 0;
}

string change(string cur, int type) {
    string newString = "";
    switch (type) {
        case 0: {
            for (int i = 0; i < 8; i++) {
                newString += to_string(cur[7-i] - '0');
            }
            break;
        }
        case 1: {
            newString += to_string(cur[3] - '0');
            for (int i = 0; i < 3; i++) {
                newString += to_string(cur[i] - '0');
            }
            for (int i = 5; i < 8; i++) {
                newString += to_string(cur[i] - '0');
            }
            newString += to_string(cur[4] - '0');
            break;
        }
        case 2: {
            newString += to_string(cur[0] - '0');
            newString += to_string(cur[6] - '0');
            newString += to_string(cur[1] - '0');
            newString += to_string(cur[3] - '0');
            newString += to_string(cur[4] - '0');
            newString += to_string(cur[2] - '0');
            newString += to_string(cur[5] - '0');
            newString += to_string(cur[7] - '0');
            break;
        }
    }
    return newString;
}

typedef struct answer answer;
struct answer {
    string val;
    string sequence = "";
};
map<string, bool> visited;
int main()
{
    int noCrash = 0;
    string target = "", tempStart = "12345678";
    for (int i = 0; i < 8; i++) {
        int holder;
        fin >> holder;
        target += to_string(holder);
    }
    
    answer start;
    start.val = tempStart;
    
    int finalLength = 100000;
    bool foundFinalLength = false;
    vector<string> potentialAnswers;
    
    queue<answer> bfs;
    bfs.push(start);
    
    while (!bfs.empty()) {
        answer current = bfs.front();
        bfs.pop();
        
        if (current.val.compare(target) == 0) {
            foundFinalLength = true;
            finalLength = (int)current.sequence.length();
            potentialAnswers.push_back(current.sequence);
        }
        noCrash++;
        if (noCrash == 1000000) break;
        string tempNext = "";
        for (int i = 0; i < 3; i++) {
            answer next;
            next.val = change(current.val, i);
            char temp = (65+i);
            next.sequence = current.sequence + temp;
            if (visited[next.val] == 1) continue;
            visited[next.val] = 1;
            if (next.sequence.length() > finalLength) continue;
            bfs.push(next);
        }
    }
    sort(potentialAnswers.begin(), potentialAnswers.end(), comparator);
    fout << potentialAnswers[0].length() << endl;
    for (int i = 0; i < potentialAnswers[0].length(); i++) {
        if ((i+1) % 60 == 0 || i == potentialAnswers[0].length()-1) {
            fout << potentialAnswers[0][i] << endl;
        } else {
            fout << potentialAnswers[0][i];
        }
    }
    if (target.compare("12345678") == 0) {
        fout << endl;
    }
    
//    for (int i = 0; i < potentialAnswers.size(); i++) {
//        fout << potentialAnswers[i] << endl;
//    }
    
    fin.close();
    fout.close();
    return 0;
}

