#include <iostream>
#include <climits>
using namespace std;
void minCoin(int* coins, int n, int w){
	int all_coins[w+1];  // make an array of length len=w+1 to store minimum number of coins for value i.
	fill(all_coins, all_coins+w, INT_MAX);  // fill all_coins array with INT_MAX from index=0 to index=w
	all_coins[0]=0;
	for(int i=1;i<=w;i++){
		for(int j=0;j<n;j++){
			if(coins[j]<=i){
				int c=all_coins[i-coins[j]];    // 1 coins[j]+ number of coins in coins[i-coins[j]];
				if(c!=INT_MAX and c+1<all_coins[i]){
					all_coins[i]=c+1;
				}
			}
		}
	}
	cout << "minimum no. of coins for value " << w << " is " << all_coins[w] << endl;

}
int main(){
	int coins[]={9, 6, 5, 1};
	int w=13;    // total value
	int n=sizeof(coins)/sizeof(int);
	minCoin(coins, n, w);
	return 0;
}
