#include <stdio.h>

int main(){
	
	char array[]={'t', 'o', 'k', 'u', 'l', 'x'};
	int i;
	int test=0;
	
	for(i=0; i<4 && test==0 ; i++){
		if(array[i]=='o' && array[i+1=='k'] && array[i+2=='u'] && array[i+3]== 'l')
		test=1;
	}	
	
	
	if(test==1){
		printf("yes");
	} else{ printf("no");
	}
return 0 ;
}
