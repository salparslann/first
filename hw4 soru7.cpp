#include <stdio.h>

int main() {
	
	int numbers[]= {1,2,3,4,7,8} ;
	
	int odd=0;
	int even = 0;
	
	for(int i =0; i<6; i++){
		
		if(numbers[i]%2 == 0){
		
		even++;}
		else{odd++;
		}
		}
	
	printf("%d is the number of even", even);
	printf("\n%d is the number of odd", odd);
	
	
	
	
	
	
	return 0 ; }
