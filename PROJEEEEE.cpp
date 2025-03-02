#include<stdio.h>

int main(){
	int a;
	int dec1; 
	int dec2;
	int dec1Sign = 0;
	int dec2Sign = 0;
	int binary1[] = {0,0,0,0,0,0,0,0};
	int binary2[] = {0,0,0,0,0,0,0,0};
	int addition[] = {0,0,0,0,0,0,0,0};

	
	printf("please enter your first number: ");
	scanf("%d" , &dec1);
	
	printf("please write your second number: ");
	scanf("%d" , &dec2);
	
	if(dec1 < 0) {
	    dec1 = -1 * dec1;
		printf("%d" , dec1);
		dec1Sign = 1;
	}
	
	if(dec2 < 0){
	    dec2 = -1 * dec2;
		printf("%d" , dec2);
		dec2Sign = 1;
	}
	
	if((-128 >= dec1 && dec1 > 127) || (-128 >= dec2 && dec2 > 127)){
	    printf("you cannot use this numbers");
	    return 0 ;
	}  
	
	//for the first number:
	
	binary1[0] = 0;
	
	if(dec1 >= 64){
		binary1[1] =  1;
		dec1= dec1 - 64 ;
	} else{
		binary1[1]=0;
	
	}
	
	if(dec1 >=32){
		binary1[2] = 1 ;
		dec1 = dec1 - 32 ;
	} else{
		binary1[2] = 0;
	}
	
    if(dec1 >= 16){
		binary1[3] = 1;
		dec1= dec1 - 16;
	} else{
		binary1[3] = 0;
	}
	
	if(dec1 >= 8){
		binary1[4] = 1 ;
		dec1 = dec1 - 8;
	} else {
		binary1[4] = 0;
	}
   	
   	if(dec1 >= 4) {
   		binary1[5]= 1 ;
   		dec1=dec1-4;
	} else {
    	binary1[5]=0;
	}
	   
	if(dec1 >= 2) {
	   binary1[6]= 1 ;
	   dec1= dec1 - 2;
	} else{
		binary1[6]=0;
		
	}

	if(dec1 >= 1 ){
		binary1[7] = 1;
		dec1= dec1 - 1;
	} else{
	    binary1[7] = 0;
	}
		
	//for the second number:
	
	binary2[0] = 0;
	
	if(dec2 >= 64){
		binary2[1] =  1;
		dec2= dec2 - 64 ;
	} else{
		binary2[1]=0;
	}
	
	if(dec2 >=32){
		binary2[2] = 1 ;
		dec2 = dec2 - 32 ;
	} else{
        binary2[2]=0;
	}
	
    if(dec2 >= 16){
		binary2[3] = 1;
		dec2= dec2 - 16;
	} else{
		binary2[3] = 0;
	}
	
	if(dec2 >= 8){
		binary2[4] = 1 ;
		dec2 = dec2 - 8;
	} else{
		binary2[4] = 0;
	}

   	if(dec2 >= 4) {
   		binary2[5]= 1 ;
   		dec2=dec2-4;
   	} else{
    	binary2[5]=0;
	}
	   
	if(dec2 >= 2) {
	   binary2[6]= 1 ;
	   dec2= dec2 - 2;
	} else{
		binary2[1]=0;
	}

	if(dec2 >= 1){
		binary2[7]=1;
		dec2= dec2 - 1;
	} else{
	    binary2[7] = 0;
	}
		

	if(dec1Sign == 1){
	    binary1[0] = 1;
	    
		if(binary1[1] == 0){
        	binary1[1] = 1;
		} else{
        	binary1[1] = 0;
		}
		
        if(binary1[2]==0){
        	binary1[2]=1;
		} else{
		    binary1[2]=0;
		}
		
		if(binary1[3]==0){
			binary1[3]=1;
			
		} else{
		    binary1[3]=0;
		}
	
		if(binary1[4]==0){
			binary1[4]=1;
		} else{
		    binary1[4]=0;
        }
		
		if(binary1[5]==0){
    	    binary1[5]=1;
		} else { 
		    binary1[5]=0;
		}
        
        if(binary1[6]==0){
            binary1[6]=1;
        } else{
	        binary1[6]=0;
	    }

        if(binary1[7]==0){
            binary1[7]=1;
        } else{
            binary1[7]=0;
        }
        
        // add 1 for negative
        int carry = 0;
    	int addBit = 0;
    	
    	addBit = binary1[7] + 1;
    	if(addBit == 2) {
    	    addBit = 0;
    	    carry = 1;
    	}
    	binary1[7] = addBit;
    	
    	addBit = binary1[6] + carry;
    	if(addBit == 2) {
    	    addBit = 0;
    	    carry = 1;
    	} else if(addBit == 3) {
    	    addBit = 1;
    	    carry = 1;
    	} else {
    	    carry = 0;
    	}
    	binary1[6] = addBit;
    	
    	addBit = binary1[5] + carry;
    	if(addBit == 2) {
    	    addBit = 0;
    	    carry = 1;
    	} else if(addBit == 3) {
    	    addBit = 1;
    	    carry = 1;
    	} else {
    	    carry = 0;
    	}
    	binary1[5] = addBit;
    	
    	addBit = binary1[4] + carry;
    	if(addBit == 2) {
    	    addBit = 0;
    	    carry = 1;
    	} else if(addBit == 3) {
    	    addBit = 1;
    	    carry = 1;
    	} else {
    	    carry = 0;
    	}
    	binary1[4] = addBit;
    	
    	addBit = binary1[3] + carry;
    	if(addBit == 2) {
    	    addBit = 0;
    	    carry = 1;
    	} else if(addBit == 3) {
    	    addBit = 1;
    	    carry = 1;
    	} else {
    	    carry = 0;
    	}
    	binary1[3] = addBit;
    	
    	addBit = binary1[2] + carry;
    	if(addBit == 2) {
    	    addBit = 0;
    	    carry = 1;
    	} else if(addBit == 3) {
    	    addBit = 1;
    	    carry = 1;
    	} else {
    	    carry = 0;
    	}
    	binary1[2] = addBit;
    	
    	addBit = binary1[1] + carry;
    	if(addBit == 2) {
    	    addBit = 0;
    	    carry = 1;
    	} else if(addBit == 3) {
    	    addBit = 1;
    	    carry = 1;
    	} else {
    	    carry = 0;
    	}
    	binary1[1] = addBit;
    	
    	addBit = binary1[0] + carry;
    	if(addBit == 2) {
    	    addBit = 0;
    	    carry = 1;
    	} else if(addBit == 3) {
    	    addBit = 1;
    	    carry = 1;
    	} else {
    	    carry = 0;
    	}
    	binary1[0] = addBit;
    }
	
	if(dec2Sign == 1){
	    binary2[0] = 1;
	    
		if(binary2[1] == 0){
        	binary2[1] = 1;
		} else{
        	binary2[1] = 0;
		}
		
        if(binary2[2] == 0){
        	binary2[2]=1;
		} else{
		    binary2[2]=0;
		}
		
		if(binary2[3]==0){
			binary2[3]=1;
		} else{
		    binary2[3]=0;
		}
	
		if(binary2[4]==0){
			binary2[4]=1;
		} else{
		    binary2[4]=0;
        }
		
		if(binary2[5]==0){
    	    binary2[5]=1;
		} else { 
		    binary2[5]=0;
		}
        
        if(binary2[6]==0){
            binary2[6]=1;
        } else{
	        binary2[6]=0;
	    }

        if(binary2[7]==0){
            binary2[7]=1;
        } else{
            binary2[7]=0;
        }
        
        // add 1 for negative
        int carry = 0;
    	int addBit = 0;
    	
    	addBit = binary2[7] + 1;
    	if(addBit == 2) {
    	    addBit = 0;
    	    carry = 1;
    	}
    	binary2[7] = addBit;
    	
    	addBit = binary2[6] + carry;
    	if(addBit == 2) {
    	    addBit = 0;
    	    carry = 1;
    	} else if(addBit == 3) {
    	    addBit = 1;
    	    carry = 1;
    	} else {
    	    carry = 0;
    	}
    	binary2[6] = addBit;
    	
    	addBit = binary2[5] + carry;
    	if(addBit == 2) {
    	    addBit = 0;
    	    carry = 1;
    	} else if(addBit == 3) {
    	    addBit = 1;
    	    carry = 1;
    	} else {
    	    carry = 0;
    	}
    	binary2[5] = addBit;
    	
    	addBit = binary2[4] + carry;
    	if(addBit == 2) {
    	    addBit = 0;
    	    carry = 1;
    	} else if(addBit == 3) {
    	    addBit = 1;
    	    carry = 1;
    	} else {
    	    carry = 0;
    	}
    	binary2[4] = addBit;
    	
    	addBit = binary2[3] + carry;
    	if(addBit == 2) {
    	    addBit = 0;
    	    carry = 1;
    	} else if(addBit == 3) {
    	    addBit = 1;
    	    carry = 1;
    	} else {
    	    carry = 0;
    	}
    	binary2[3] = addBit;
    	
    	addBit = binary2[2] + carry;
    	if(addBit == 2) {
    	    addBit = 0;
    	    carry = 1;
    	} else if(addBit == 3) {
    	    addBit = 1;
    	    carry = 1;
    	} else {
    	    carry = 0;
    	}
    	binary2[2] = addBit;
    	
    	addBit = binary2[1] + carry;
    	if(addBit == 2) {
    	    addBit = 0;
    	    carry = 1;
    	} else if(addBit == 3) {
    	    addBit = 1;
    	    carry = 1;
    	} else {
    	    carry = 0;
    	}
    	binary2[1] = addBit;
    	
    	addBit = binary2[0] + carry;
    	if(addBit == 2) {
    	    addBit = 0;
    	    carry = 1;
    	} else if(addBit == 3) {
    	    addBit = 1;
    	    carry = 1;
    	} else {
    	    carry = 0;
    	}
    	binary2[0] = addBit;
        
	}
	
	int carry = 0;
	int additionBit = 0;
	
	additionBit = binary1[7] + binary2[7];
	if(additionBit == 2) {
	    additionBit = 0;
	    carry = 1;
	}
	addition[7] = additionBit;
	
	additionBit = binary1[6] + binary2[6] + carry;
	if(additionBit == 2) {
	    additionBit = 0;
	    carry = 1;
	} else if(additionBit == 3) {
	    additionBit = 1;
	    carry = 1;
	} else {
	    carry = 0;
	}
	addition[6] = additionBit;
	
	additionBit = binary1[5] + binary2[5] + carry;
	if(additionBit == 2) {
	    additionBit = 0;
	    carry = 1;
	} else if(additionBit == 3) {
	    additionBit = 1;
	    carry = 1;
	} else {
	    carry = 0;
	}
	addition[5] = additionBit;
	
	additionBit = binary1[4] + binary2[4] + carry;
	if(additionBit == 2) {
	    additionBit = 0;
	    carry = 1;
	} else if(additionBit == 3) {
	    additionBit = 1;
	    carry = 1;
	} else {
	    carry = 0;
	}
	addition[4] = additionBit;
	
	additionBit = binary1[3] + binary2[3] + carry;
	if(additionBit == 2) {
	    additionBit = 0;
	    carry = 1;
	} else if(additionBit == 3) {
	    additionBit = 1;
	    carry = 1;
	} else {
	    carry = 0;
	}
	addition[3] = additionBit;
	
	
	additionBit = binary1[2] + binary2[2] + carry;
	if(additionBit == 2) {
	    additionBit = 0;
	    carry = 1;
	} else if(additionBit == 3) {
	    additionBit = 1;
	    carry = 1;
	} else {
	    carry = 0;
	}
	addition[2] = additionBit;
	
	
	additionBit = binary1[1] + binary2[1] + carry;
	if(additionBit == 2) {
	    additionBit = 0;
	    carry = 1;
	} else if(additionBit == 3) {
	    additionBit = 1;
	    carry = 1;
	} else {
	    carry = 0;
	}
	addition[1] = additionBit;
	
	additionBit = binary1[0] + binary2[0] + carry;
	if(additionBit == 2) {
	    additionBit = 0;
	    carry = 1;
	} else if(additionBit == 3) {
	    additionBit = 1;
	    carry = 1;
	} else {
	    carry = 0;
	}
	addition[0] = additionBit;
	
if(addition[0] == 1){
	a= a-128;
}
if(addition[1] == 1){
	a= a + 64;
}
if(addition[2] == 1){
	a= a + 32;
}
if(addition[3] == 1){
	a= a+ 16;
}
if(addition[4] == 1){
	a= a + 8;
}
if(addition[5] == 1){
	a= a+ 4;
}
if(addition[6] == 1){
	a= a + 2;
}
if(addition[7] == 1){
	a= a +1 ;
}

	printf("\n is dec1 in binary %d %d %d %d %d %d %d %d", binary1[0],binary1[1],binary1[2],binary1[3],binary1[4],binary1[5],binary1[6],binary1[7]);
	printf("\n is dec2 in binary %d %d %d %d %d %d %d %d", binary2[0],binary2[1],binary2[2],binary2[3],binary2[4],binary2[5],binary2[6],binary2[7]);
    printf("\n is addition in binary %d %d %d %d %d %d %d %d", addition[0],addition[1],addition[2],addition[3],addition[4],addition[5],addition[6],addition[7]);
    printf("\n is sum in decimal: ");
    printf("%d", a);
    
    
	return 0;
}



