#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#define ESC 27

struct patient{
	char id[5];
	char fName[25];
	char lName[25];
	char age[3];
	char gender[2];
}	h;

FILE *file,*bill,*price;

void entry();
void searching();
void display();
void create_bill();
void report();

int main(){
	int option;
	char ch;

	here:
	system("cls");
	puts("\n\tWelcome to xyz hospital\n");
	puts("    1. Add entry");
	puts("    2. Display record");
	puts("    3. Search record");
	puts("    4. Create bill");
	puts("    5. Report");
	puts("    6. Exit");
	puts("\n\nSelect an option : ");
	scanf("%d",&option);

	switch(option){
		case 1:
			system("cls");
			entry();
			break;

		case 2:
			system("cls");
			display();
			break;

		case 3:
			system("cls");
			searching();
			break;

		case 4:
			system("cls");
			create_bill();
			break;

		case 5:
			system("cls");
			report();
			break;

		case 6:
			system("cls");
			puts("\nThank you.");
			delay(345);
			exit(0);

		default :
			system("cls");
			puts("\nError : invalid option");
	}

	puts("\n\nDo you want to continue (y/n) ? ");
	ch=getch();
	if(ch=='y' || ch=='Y'){
		goto here;
	}

	else{
		if(ch=='n' || ch=='N'){
			system("cls");
			puts("\nThank you for using this software.");
			delay(345);
			exit(0);
		}
	}

	getch();
	return 0;
}

void entry(){
	char save;

	while(1){
		system("cls");
		puts("\nEnter Id : ");
		fflush(stdin);
		scanf("%s",h.id);

		puts("Enter first name : ");
		fflush(stdin);
		scanf("%s",h.fName);

		puts("Enter last name : ");
		fflush(stdin);
		scanf("%s",h.lName);

		puts("Enter age :");
		fflush(stdin);
		scanf("%s",h.age);

		puts("Enter gender (m/f): ");
		fflush(stdin);
		scanf("%s",h.gender);

		puts("\nDo you want to save (y/n) : ");
		save=getch();

		if(save=='Y' || save=='y'){
			file=fopen("c:\\register.txt","a");
			fprintf(file,"%s\t%s\t%s\t%s\t%s\n",h.id,h.fName,h.lName,h.age,h.gender);
			fclose(file);
			puts("\nEntry successful.");
			break;
		}

		else{
			if(save=='n' || save=='N'){
			break;
			}
		}
	}
}

void display(){
		system("cls");
		printf("--------------------------------------------------------------\n");
		puts("\t\tRecord available\n");
		printf("Id\tFull Name\tAge\tGender\n");
		printf("--------------------------------------------------------------\n");

		file=fopen("c:\\register.txt","r");
		while(!feof(file)){
			fscanf(file,"%s %s %s %s %s",h.id,h.fName,h.lName,h.age,h.gender);
			if(feof(file)){
				break;
			}
			printf("%s\t%s %s\t%s\t%s\n",h.id,h.fName,h.lName,h.age,h.gender);
		}
		fclose(file);
		getch();
}

void searching(){

	char id[5];
	char fName[25],lName[25];
	char age[3];
	char gender[2];
	char search[20];
	int flag=0;

	file=fopen("c:\\register.txt","r");

	printf("\nEnter id to search : ");
	scanf("%s",search);
	puts("\nId\tFull Name\tAge\tGender\n");

	while(!feof(file)){
		fscanf(file,"%s %s %s %s %s",id,fName,lName,age,gender);
		if(feof(file)){
			break;
		}
		if(strcmp(id,search)==0){
			flag=1;
			break;
		}
	}
		if(flag==1){
			printf("%s\t%s %s\t%s\t%s",id,fName,lName,age,gender);
			puts("\n\nPress any key to continue");
			getch();
		}

		else{
			if(flag!=1){
				system("cls");
				puts("\nId not found.");
				getch();
			}
		}

	fclose(file);
	getch();
}

void create_bill(){
		//bill=fopen("c:\\bill.txt","a");
		char id[5],p_id[5],a[25],b[25],c[25],d[25];
		char fName[25],lName[25],age[5],gender[5];
		int r,s;
		char f_Name[25],l_Name[25];
		char ID[5];

		price=fopen("c:\\code.txt","r");
		gotoxy(r,s);
		printf("\nID\tNAME\tRATE\n");

		/*code for searching details*/

		while(!feof(price)){
			fscanf(price,"%s %s %s %s", a,b,c,d);
			if(feof(price)){
				break;
			}
			s++;
			gotoxy(r,s);
			printf("%s %s %s %s\n",a,b,c,d);
		}
		fclose(price);

		/*code for searching patient info*/

		gotoxy(1,1);
		printf("ID : ");
		scanf("%s",p_id);
		file=fopen("c:\\register.txt","r");
		while(!feof(file)){
			fscanf(file,"%s%s%s%s%s",id,fName,lName,age,gender);
			if(strcmp(id,p_id)==0){
				printf("NAME : %s %s",f_Name,l_Name);
				printf("AGE : %s",age);
				printf("GENDER : %s",gender);
				break;
			}
			if(feof(file)){
				break;
			}
		}
		fclose(file);

		/*code for taking input of patients*/

		printf("\nID\tNAME\tRATE\n");
		int x=6,y=8;
		int e=0;
		while(1){
			scanf("%s",ID);
			price=fopen("c:\\code.txt","r");
			bill=fopen("c:\\billing.txt","a");
			gotoxy(x,y);

			while(!feof(price)){
				fscanf(price,"%s",a);
				if(strcmp(a,ID)==0){
					fscanf(price,"%s%s%s",b,c,d);
					fprintf(bill,"%s%s%s%s\n",p_id,a,b,c,d);
					printf("%s %s %s\n",b,c,d);
					//e=c+d;
				}
			}

			y++;
			char ch;
			ch=getch();
			char z;
			if(ch==ESC){
				printf("Do you want to save (y/n) ? \n");
				z=getch();
				if(z=='y' || z=='Y'){
					printf("\n\n\nTotal amount : Rs. %s",e);
				}
				break;
			}
		}
		fclose(price);
		fclose(bill);
		getch();

}

	/*report for patient*/
	char hbg[10];
	char hct[10];
	char mch[10];

void report(){
	clrscr();
	char id[5],fName[25],lName[25],age[5],gender[5];
	char p_id[5];
	char a[25],b[25],c[25],d[25];

	printf("\n\tCODE IT MEDICAL CENTRE\n");
	printf("Patient Id : ");
	scanf("%s",p_id);

	file=fopen("c:\\register.txt","r");
	while(!feof(file)){
		fscanf(file,"%s %s %s %s %s\n",id,fName,lName,age,gender);
		if(strcmp(id,p_id)==0){
			printf("\nName : %s %s",fName,lName);
			printf("Age : %s",age);
			printf("Gender : %s",gender);
			break;
		}
	}
	printf("\n------------------------------------------\n");
	printf("Tests : \t\tResult\t\tNormal\n");
	printf("\n------------------------------------------\n");
	price=fopen("c:\\code.txt","r");
	while(!feof(price)){
		fscanf(price,"%s%s%s%s",a,b,c,d);
		if(feof(price)){
			break;
		}
		printf("%s %s \n\n\n",b,c);
	}

	int x,y;
	x=41;
	y=12;
	gotoxy(x,y);
	printf("13.8g/dL");
	y++;
	gotoxy(x,y);
	printf("45%-52%");
	y++;
	gotoxy(x,y);
	printf("27-32pG");
	y++;
	gotoxy(x,y);
	printf("");
	x=17;
	y=12;
	gotoxy(x,y);
	printf("Hbg : ");
	scanf("%s",hbg);
	y++;
	gotoxy(x,y);
	printf("Hct : ");
	scanf("%s",hct);
	y++;
	gotoxy(x,y);
	printf("MCH : ");
	scanf("%s",mch);
	fclose(price);
}
