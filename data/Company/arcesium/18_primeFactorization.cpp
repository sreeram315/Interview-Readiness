#include<iostream>
#include<vector>


void printPrimeFactors(int num){
	if(num <= 1) return;
	while(num%2 == 0){
		printf("2 ");
		num /= 2;
	}
	for(int fac = 3; num > fac; fac += 2){
		while(num>fac && num%fac==0){
			printf("%d ", fac);
			num /= fac;
		}
	}
	if(num > 1)
		printf("%d ", num);
}

int main(){
	int num = 28746129;
	printPrimeFactors(num);
	printf("\n");
}