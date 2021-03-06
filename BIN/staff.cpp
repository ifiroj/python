#include <stdio.h>
#include <stdlib.h>

void Menu();
void New_Staff();
void Delete_Staff();
void Export_Profile();

struct element{
    char id[20];
    char name[20];
    char gender[20];
    char phone[20];
    char email[20];
}profile;

int main(void){      //The program will continue running until option 4 selected                                   
    int a;  

    for(a=0;;a++){
       Menu();
    }
    return 0;
}

void Menu()      //Main Menu to select option
{
    int n;
    printf("\n**********************************************");
    printf("\nMAIN MENU-STAFF INFORMATION SYSTEM");
    printf("\n**********************************************");
    printf("\n1. Add profile Staff Profile");
    printf("\n2. Delete Staff Profile");
    printf("\n3. Export All Profiles to 'output.txt'");
    printf("\n4. Exit");
    printf("\n**********************************************");
    printf("\nPlease enter your option< 1 / 2 / 3 / 4 >: ");
    scanf("%d", &n);

    switch(n){
    case 1:
        New_Staff();
        break;
    case 2:
        Delete_Staff();
        break;
    case 3:
        Export_Profile();
        break;
    case 4:
        printf("\n*** Thanks for using the program! Goodbye. ***");
        exit(0);
        break;
    default:
        printf("\nError! Wrong Number is Entered\nPlease Try Again");
        break;
    }
}

void New_Staff()                        //Add New Staff Profile 
{   
    int x;
    struct element profile;

    printf("\n===Add New Staff Profile===");
    printf("\n\nPlease enter the following staff information.");

    printf("\n\nStaff ID: ");
    scanf("%s", &profile.id);

    printf("\nName\t: ");
    fflush(stdin);
    fgets(profile.name,20,stdin);

    for(x=0 ; x<20 ; x++)
    {
    if(profile.name[x] == '\n')
        profile.name[x] = '\0';
    }

    printf("Gender\t: ");
    scanf("%s", &profile.gender);

    printf("Phone\t: ");
    scanf("%s", &profile.phone);

    printf("Email\t: ");
    scanf("%s", &profile.email);

    printf("\nSYSTEM: New Staff Profile is Added Successfully.");

}

void Delete_Staff()         //Delete Staff Profile
{                   
    FILE *fRead, *fWrite;
    char *TextFile;
    char c;
    int Delete_Id, temp = 1;

    TextFile="output.txt";

    fRead = fopen(TextFile, "r");
    c = getc(fRead);

    while (c != EOF){
    printf("%c", c);
    c = getc(fRead); 
    }

    rewind(fRead);

    printf("\nDelete Staff with ID: ");
    scanf("%d", &Delete_Id);

    Delete_Id=Delete_Id+1;

    fWrite = fopen("copy.c", "w");
    c = getc(fRead);
    while (c != EOF) {
    c = getc(fRead);
    if (c == '\n')
    temp++;
    if (temp != Delete_Id){
    putc(c, fWrite); 
       } 
    }

    fclose(fRead);
    fclose(fWrite);

    remove(TextFile);

    rename("copy.c", TextFile);
    printf("\nThe contents of file after being modified are as follows:\n");

    fRead = fopen(TextFile, "r");
    c = getc(fRead);
    while (c != EOF) {
    printf("%c", c);
    c = getc(fRead);
    }

    fclose(fRead);
}

void Export_Profile()           //Export Staff Profile to Text
{       
    struct element profile;

    FILE *fPtr;
    fPtr=fopen("output.txt","w");
    FILE *fPtr1;
    fPtr1=fopen("output.txt","a+");

    if (fPtr == NULL)
    printf("Error in opening file\n");
    
    if (fPtr1 == NULL)
    printf("Error in opening file\n");

    fprintf(fPtr,"%10s %10s %10s %10s %10s","Staff","ID",
             "Name","Gender","Phone","Email");

    fprintf(fPtr1,"\n%10s %10s %10s %10s %10s", profile.id, profile.name,   
             profile.gender, profile.phone, profile.email);

    printf("\n%10s %10s %10s %10s %10s", "Staff", "ID", "Name",
             "Gender", "Phone",  "Email");
    printf("\n%10s %10s %10s %10s %10s", profile.id, 
             profile.name, profile.gender, profile.phone, profile.email);

    printf("\nSYSTEM: All staff profile have been exported to output.txt file");

    fclose(fPtr);
    fclose(fPtr1);
