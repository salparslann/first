#include <stdio.h>




int main() {
	
	int numbers[] = {12, 2, 16, 8, 9, 1} ;

	 
	int cur_max = numbers[0] + numbers [1] ;
	
	if(cur_max < numbers[1] + numbers[2]){
		cur_max = numbers[1] + numbers[2] ;
	}

    if(cur_max < numbers[2] + numbers[3]) {
    	
    cur_max = numbers[2] + numbers[3] ;
	}
	

    if(cur_max < numbers[3] + numbers[4]){
    	cur_max = numbers[3] + numbers[4];
    
	}
	
	if(cur_max < numbers[4] + numbers[5]){
		cur_max = numbers[4] + numbers[5];
	}
	
	printf("%d is the largest number\n" , cur_max) ;
	
	
	
	




return 0 ;





}
