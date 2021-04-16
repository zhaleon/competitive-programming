/*
 ID: lionz202
 TASK: ratios
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

ifstream fin("ratios.in");
ofstream fout("ratios.out");

int target[3], current[5], feed[3][3];

int main()
{
    for (int i = 0; i < 3; i++)
        fin >> target[i];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            fin >> feed[j][i];
        }
    }
//    for (int i = 0; i < 3; i++) {
//        for (int j = 0; j < 3; j++) {
//            fout << feed[i][j] << ' ';
//        }
//        fout << endl;
//    }
    current[4] = 1000000;
    //best sum so far;
    int targetSum = target[0] + target[1] + target[2];
    if (targetSum == 0) {
        fout << "0 0 0 0\n" << endl;
        return 0;
    }
    bool foundAnything = false;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            for (int k = 0; k < 101; k++) {
                int grain1 = i*(feed[0][0]) + j*feed[0][1]+ k*feed[0][2];
                int grain2 = i*(feed[1][0]) + j*feed[1][1]+ k*feed[1][2];
                int grain3 = i*(feed[2][0]) + j*feed[2][1]+ k*feed[2][2];
                int finalRatio = (grain1 + grain2 + grain3)/targetSum;
                if (finalRatio == 0) continue;
                if (!(grain3 == 0 && grain2 == 0 && grain1 == 0) && (i + j + k > 0) && grain3 == finalRatio*target[2] && grain2  == finalRatio*target[1] && grain1 == finalRatio*target[0]) {
                    if (current[4] > i + j + k) {
                        foundAnything = true;
                        current[4] = i + j + k;
                        current[0] = i;
                        current[1] = j;
                        current[2] = k;
                        current[3] = (grain1 + grain2 + grain3)/targetSum;
                    }
                }
            }
        }
    }
    
    if (!foundAnything) {
        fout << "NONE\n";
        return 0;
        
    }

    for (int i = 0; i < 4; i++) {
        if (current[i] > 99) {
            fout << "NONE" << endl;
            return 0;
        }
    }
    fout << current[0] << ' ' << current[1] << ' ' << current[2] << ' ' << current[3] << endl;
    
    fin.close();
    fout.close();
    return 0;
}

