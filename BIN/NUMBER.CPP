#include<stdio.h>
#include<conio.h>
int main(){
	int ev,od,i,n;
	FILE *x,*y,*z;
	int a[5],b[5],c[5],d[5];
	clrscr();

	printf("\nkati ota number halne ? ");
	scanf("%d",&n);

	printf("\nenter %d numbers ",n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		x=fopen("c:\\number.txt","w");
		fprintf(x,"%d",a[i]);
		fclose(x);
	}

	x=fopen("c:\\number.txt","r");
	while(!feof(x)){
		fscanf(x,"%d",&b[i]);
		if(feof(x)){
			break;
		}
		printf("%d ",b);
		fclose(x);
	}

		if(a[i]%2==0){
			printf("%d",a);
			y=fopen("c:\\even.txt","w");
			fprintf(y,"%d",c);
			printf("even = %d",c);
			fclose(y);
		}
		else{
			printf("%d",a);
			z=fopen("c:\\odd.txt","w");
			fprintf(z,"%d",d);
			printf("odd = %d",d);
			fclose(z);
		}



	getch();
	return 0;
}