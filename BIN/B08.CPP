/*	lab		: power of number
coded by	: firoj acharya	*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(){
	//clrscr();
	int x,y,z;

	printf("enter base of number :");
	scanf("%d",&x);

	printf("enter the power of the number : ");
	scanf("%d",&y);

	z=pow(x,y);
	printf("the answer is %d",z);


	getch();
	return  0;

}