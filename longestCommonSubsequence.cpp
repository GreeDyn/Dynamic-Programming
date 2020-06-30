// This is dynamic programming to solve longest common sequence problem.
// Given two sequence X and Y, find Z, a common subsequence of X and Y
// Reference: Introduction to Algorithms
// Programming language: C++
// Author: Prakash Besra

#include <iostream>
using namespace std;
void lcs(string x, string y){
    int n=x.length();
    int m=y.length();
    int c[n+1][m+1];
    char b[n+1][m+1];
    for(int i=0;i<n+1;i++){
        c[i][0]=0;
    }
    for(int i=0;i<m+1;i++){
        c[0][i]=0;
    }
    // 'l' means move left
    // 'u' means move up
    // 'd' means move in diagonal diection

    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(x[i-1]==y[j-1]){
                c[i][j]=c[i-1][j-1]+1;
                b[i][j]='d';
            }else if(c[i-1][j]>=c[i][j-1]){
                c[i][j]=c[i-1][j];
                b[i][j]='u';
            }else{
                c[i][j]=c[i][j-1];
                b[i][j]='l';
            }

        }
    }
    
    // print length of the longest common subsequence
    cout << c[n][m] << endl;
}
int main(){
  return(0);
}
