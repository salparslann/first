#include <stdio.h>

int main(){
	 
	 int x;
	 char letters[]= {'A','B', 'C', 'D', 'F'} ;
	 
	 printf("write your grade:");
	 scanf("%d", &x);
	 
	 
	 if(x<60) {
	 	printf("%c", letters[4]);
	 	
	 }
	
	 else if(60<x && x<70){
	 	printf("%c", letters[3]);
	 }
	
	if(70 < x && x < 80){
		printf("%c", letters[2]);
     }
     
    else if(80 < x && x < 90){
    	printf("%c", letters[1]);
	}
	
	else(x >= 90); {
	    printf("%c", letters[0]);
	}
     
    
		
	
	
	

	
	
	
	return 0 ;
}
