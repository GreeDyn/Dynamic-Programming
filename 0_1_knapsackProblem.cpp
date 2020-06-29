//Knapsack problem | Dynamic programming
// Author: Prakash Besra
#include <iostream>

using namespace std;


int knapsack(int a[][2], int n, int capacity){
	
	// 2 D matrix to store profit of different weights.
	int profitMatrix[n+1][capacity+1];

	// first row and first column indicate no object and no weight respectively.
	// default profits for all weights 0
	for(int i=0;i<n+1;i++){
		for(int j=0;j<capacity+1;j++){
			profitMatrix[i][j]=0;
		}
	}

	// objCount used to iterate over objects
	int objCount=0;
	for(int i=1;i<n+1;i++){
		
		
		int weight=a[objCount][0];
		int profit=a[objCount][1];

		for(int j=0;j<capacity+1;j++){
			
			// if item's weight is greater than the current capacity, then take previous weight in (i-1, j)
			if(j<weight){
				
				profitMatrix[i][j]=profitMatrix[i-1][j];
				
			}else{
				profitMatrix[i][j]=max(profit+profitMatrix[i-1][j-weight], profitMatrix[i-1][j]);
			}
			
		}
		objCount++;
	}
	return(profitMatrix[n][capacity]);



}
int main(){

	// total number of objects/items
	int n;
	cin >> n;

	int a[n][2];
	
	// In the 2D matrix => a[][2], first item is weight and second item is profit.
	// weight, value
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			cin >> a[i][j];
		}
	}

	// total capacity of the bag that has to be filled.
	int capacity;
	cin >> capacity;
	

	cout << knapsack(a, n, capacity);
	
	return(0);
}
