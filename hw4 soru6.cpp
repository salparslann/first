
#include <stdio.h>

int main() {
	
	int numbers[]= {1,2,3,4,7,8,-2,-3} ;
	
	int neg=0;
	int pos = 0;
	
	for(int i =0; i<8; i++){
		
		if(numbers[i] < 0){
		
		neg++;}
		else{pos++;
		}
		}
	
	printf("%d is the number of pos", pos);
	printf("%d is the number of neg", neg);
	
	
	
	
	
	
	return 0 ; 	 }
	
