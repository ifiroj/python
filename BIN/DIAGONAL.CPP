#include<stdio.h>
#include<conio.h>
int main(){
	int i,n=4,a[4][4],j,b[4][4];

	clrscr();

	printf("enter %d elements in 4*4 matrix :\n",n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("a%d%d : ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}

	if(a[1][1]==0 && a[2][2]==0 && a[3][3]==0 && a[4][4]==0){
		printf("\nThe diagonal of this matrix is zero");
	}
	else{
		printf("\nThe diagonal of this matrix is not zero");
	}


	getch();
	return 0;

}