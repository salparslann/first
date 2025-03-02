#include <stdio.h>

int main(){
	
	int array[]={1,2,4,25} ;
	
	int x=0;
	
	for(int i=0; i<4 ; i++){
		
		if(array[i]<23){
			x++;
		}
	}
	
	printf("%d", x);
	
	return 0 ;
}
