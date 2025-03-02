#include <stdio.h>

void decimalToBinary(int dec1){
	
       int binary[8]={};
       int digit = 64;
       int decSign=0;
       int i = 0;
	   if(dec1 < 0) {
	    dec1 = -1 * dec1;
		 decSign =1;
	}

    while(i<8){
    	
    	if(dec1>=digit){
    		binary[i] = 1;
    		dec1=dec1-digit ;
		} 
		else{ binary[i]=0;
		}
	  
	  i++; 
	
	digit= digit/2; } 
	  
	if(decSign== 1){
		i=0;
		while(i<8){
			
			if(binary[i]==1){
				binary[i]=0;
			} else{binary[i]=1;
			}
			i++;
		}
		
		binary[0]++;
		
		i=0;
		while(i<7){
			if(binary[i]==2){
				binary[i]=0;
				binary[i+1]++;
			} 
			else if(binary[i]==3){
				binary[i]=1;
				binary[i+1]++;
			}
			i++;
		}
	}
		i=0;
		while(i<8){
			printf("%d", binary[i]);
			i++;
		}
}
		int main(){
			int x=-64;
			 decimalToBinary(x);
			return 0 ;
		}
		
