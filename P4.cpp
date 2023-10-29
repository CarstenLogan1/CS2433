#include <iostream>
using namespace std;

int* swapArray(int* arr){
	static int arr1[100];
	int size = *(&arr + 1) - arr;
	int* pArr1 = arr1;
	for(int i = size-1; i>=0; i--){
		*pArr1 = arr[i];
		pArr1++;
	}
	return arr1;
}



int main() {
	
	int arr[] = {1,2,3};
	int* revArr = swapArray(arr);
	for(int i = 0; i<3;i++){
		cout<<revArr[i]<<" ";
	}
	
return 0;
}
