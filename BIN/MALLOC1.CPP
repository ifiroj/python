#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main(){
	int sum=0,*a,i,n;

	clrscr();
	printf("\nenter value of n : ");
	scanf("%d",&n);

	a=(int*)malloc(n*sizeof(int));

	printf("enter %d  numbers : ",n);
	for(i=0;i<n;i++){
		scanf("%d",a);
		sum+=*a;
		a++;
	}

	printf("The sum is: %d ",sum);
	free(a);

	getch();
	return 0;
}