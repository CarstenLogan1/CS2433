#include <iostream>
using namespace std;

int main(int argc, const char * argv[]){
	
	int a[2][3] = {
		{1,2,3},
		{4,5,6}
	};
	
	//switches rows and columns
	int b[2][3];
	for(int i = 0; i < 2; i++){
		for(int j = 0; j<3; j++){
			if(i == 0){
			b[i][j] = a[i+1][j];
			} else {
				b[i][j] = a[0][j];
			}
		}
	}
	
	for(int i = 0; i<2; i++){
		for(int j = 0; j<3; j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	int c[2][3];
	int d[2][3];
	
	
	//switches rows back
	for(int i = 0; i < 2; i++){
		for(int j = 0; j<3; j++){
			if(i == 0){
			c[i][j] = b[i+1][j];
			} else {
				c[i][j] = b[0][j];
			}
		}
	}
	
	
	int temp[3];
	int temp2[3];
	
	//flips row 1
	for(int i = 0; i < 3; i++){
		temp[i] = c[0][2-i];
	}
	
	//flips row 2
	for(int i = 0; i < 3; i++){
		temp2[i] = c[1][2-i];
	}
	
	
	//inserts two new flipped rows into array d
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++){
			if(i == 0){
				d[i][j] = temp[j];
			} else {
				d[i][j] = temp2[j];
			}
		}
		cout<<endl;
	}
	
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++) {
			cout<<d[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int i = 0; i<3; i++){
		if(i == 0){
			temp[i] = d[0][1];
		} else if(i == 2){
			temp[i] = d[0][0];
		} else {
			temp[i] = d[0][2];
		}
	}
	
	for(int i = 0; i<3; i++){
		if(i == 0){
			temp2[i] = d[1][1];
		} else if(i == 2){
			temp2[i] = d[1][0];
		} else {
			temp2[i] = d[1][2];
		}
	}
	
	int e[2][3];
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++){
			if(i == 0){
				e[i][j] = temp[j];
			} else {
				e[i][j] = temp2[j];
			}
		}
		cout<<endl;
	}
	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 3; j++) {
			cout<<e[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	

return 0;
}
