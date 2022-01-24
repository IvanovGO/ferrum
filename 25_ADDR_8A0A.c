#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


void strrev(char * str){//переворачиваем строку
int len=strlen(str);int neg=0;
//printf("Rev string %s with len %i\n",str,len);
char * tms = (char*)malloc(len+1+neg);
if (str[0]=='-') {neg=1;tms[0]='-';}
for (int p=neg;p<len;p++){
tms[len-1+neg-p]=str[p];}
tms[len]=0;
//printf("neg= %i tms=%s\n",neg,tms);
strcpy(str,tms);
free(tms);
}

static int _hexnum(int n){
if ((n>=0)&(n<10)) return 0x30+n;
if ((n>=10)&(n<16)) return 0x41+n-10;}


char * Dec2Hex(int num){

int remain=0;
int rez;
char * str = (char*)malloc(80);
int p=0;
if (num<0) {num=-num; str[p]='-';p++;}
rez=num;
while (rez>16)
{remain=rez%16;
rez/=16;
str[p]=_hexnum(remain);
p++;
//printf("%i",remain);
}
//printf("%i\n",rez);
str[p]=_hexnum(rez);
str[p+1]=0;
//printf("strlen=%i num=%s\n",strlen(str),str);
strrev(str);
return str;
}

static int _h2d(char n){
if ((n>0x2f)&(n<=0x3a)) return n-0x30;
if ((n>0x40)&(n<=0x47)) return n-0x40+9;}

int Hex2Int(char * str){
int rez=0;
int len=strlen(str);
//printf("len= %i\n",len);
for (int a=0;a<len;a++){
		// printf("str=%c num=%i\n",str[a],_h2d(str[a]));
		 rez+=_h2d(str[a])*pow(16,len-a-1);}
return rez;}


int main(){

char SS[]="8A0A";
char SP[]="0000";
printf("SS=%s,%i\n",SS,Hex2Int(SS));

for (int addr=Hex2Int(SP);addr!=Hex2Int(SP)+6*sizeof(unsigned short int);addr+=sizeof(unsigned short int)){
printf("%s:000%s\n",SS,Dec2Hex(addr));
}


return 0;}
