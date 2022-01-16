#include <limits.h>
#include <stdio.h>
#include <string.h>

int checkbit(const int value, const int position) {//функция проверяет бит на 0/1
    return ((value & (1 << position)) != 0);
}
void printbits(int n) {//печатает последовательность бит в байте
    size_t len = 8;
    size_t i;
    for (i = 0; i < len; i++) {
        printf("%d ", checkbit(n, i));
    }}



void RLL(char b){
static int t=0;
static int c=0;
static int c0=0;
static int c1=0;
static char rez[8];
if (b) c1++; else c0++;

switch(c){

case 0: t=b; break;

case 1: if (b&t) {strcpy(rez,"NNNT"); c++; t=b; break;}
        if (!b&!t) {strcpy(rez,"NNTN"); c++; t=b; break;}
	break;

case 2: if (b&t)


	break;



case 3: break;


}


{  if (b) {strcpy(rez,"TNNN");} else if (b&!t) {printf("NTNN");}  
   if (!b)  if (t) { } else
   		{ }

}

}

int main(){
char data[]="ADDY";//задание
char d,n,c;
printf("data:");for (int i=0;data[i];i++) printbits(data[i]); printf("\n");//выводим задание в двоичнойформе
printf("MFMc:");//выводим кодированную MFM последовательность
for (int i=0;data[i];i++) //итерация по символам  задания
 for (int b=0;b<8;b++) RLL(checkbit(data[i],b));
puts("fin");
return 0;}
