#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<string.h>

int main(){
	clrscr();
	int i;
	char a[100];
  
  puts("\nWrite a sentence below : \n");
  gets(a);

  /*
  printf("\nDescending order \n");
  
  for(i=(strlen(a));i>=0;i--){
    printf("%c",a[i]);
    delay(150);
    sound(255+50);
    delay(150);
    nosound();
  }
  */

  /*
  printf("\nAscending order \n");
  
  for(i=0;i<=(strlen(a));i++){
    printf("%c",a[i]);
    delay(150);
    sound(250+50);
    delay(150);
    nosound();
  }
  */
  
  printf("Pausing after a word\n");
  for(i=0;i<=(strlen(a));i++){
    if(a[i]==' '|| a[i]=='.'){
      printf("%c",a[i]);
      delay(550);
      sound(250-50);
      delay(150);
      nosound();
    }

    else{
      printf("%c",a[i]);
      delay(250); 
    }
  
  }

  getch();
  return 0;
}