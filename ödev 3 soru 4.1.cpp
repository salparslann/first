#include <stdio.h>

int main() {
	
	int x;
	
	-127< x && x < 128;
	
	printf("write a number: ");
	scanf("%d", &x) ;
	
	if(x > 0){
		printf("%d" , x);
	}
	
	else if (x < 0) {
		printf("%d" , -x);
	
	}
	
	
	
	return 0;
	
}
