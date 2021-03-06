#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s2;
    cin >> s1 >> s2;
    const int a = s1.length(), b = s2.length();
    int resultArr[a+1][b+1];
    string resultStringArr[a+1][b+1];
    for (int i=0;i<=a;i++){
        for (int j=0;j<=b;j++){
            resultArr[i][j] = 0;
            resultStringArr[i][j] = "";
        }
    }
    for (int i=1;i<=a;i++){
        for (int j=1;j<=b;j++){
            int k;
            for (k=i;k>=1;k--){
                if (s1[k-1] == s2[j-1]) break;
            }
            if (k == 0){
                resultArr[i][j] = resultArr[i][j-1];
                resultStringArr[i][j] = resultStringArr[i][j-1];
            }
            else{
                if (resultArr[i][j-1] >= resultArr[k-1][j-1]+1){
                    resultArr[i][j] = resultArr[i][j-1];
                    resultStringArr[i][j] = resultStringArr[i][j-1];
                }
                else{
                    resultArr[i][j] = resultArr[k-1][j-1]+1;
                    resultStringArr[i][j] = resultStringArr[k-1][j-1] + s2[j-1];
                }
            }
        }
    }
    cout << resultArr[a][b] << endl << resultStringArr[a][b] << endl;
    return 0;
}