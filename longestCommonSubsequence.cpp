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
    
    // c stores length of common subsequence of X and Y
    int c[n+1][m+1];
    
    // b stores common subsequence
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
    // let's assume z is the common subsequence of x and y then
    // if x[n]==y[m] => z[k]=x[n]=y[m] => we have to consider x[n-1] and y[m-1]
    // if x[n]!=y[m]=> z[k]=x[n] => we have to consider x[n-1] and y[m]
    // if x[n]!=y[m]=> z[k]=y[m] => we have to consider x[n] and y[m-1]
    
    
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
