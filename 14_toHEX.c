#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

char * Dec2nHex(int num){

int remain=0;
int rez;
char * str = (char*)malloc(80);
int p=0;
 str[p]='-';p++;
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



char * Dec2HexF(float num){
char * str;
int remain=0;
char tmp[2];tmp[1]=0;
int numI = (int)num;
if (num<0) {numI=-numI;num=-num;printf("%i %f\n",numI,num);
	 str = Dec2nHex(numI);}else
				{str = Dec2Hex(numI);}


float frct=num-numI;;
strcat(str,".");
//printf("Integer part=%s\n",str);
float rez=frct;
rez=frct*16;
remain=(int)rez;
while (remain)
{remain=(int)rez;
rez=(rez-remain)*16;
tmp[0]=_hexnum(remain);
strcat(str,tmp);
//printf("remain=%s %2f",tmp,rez);
}

tmp[0]=_hexnum(rez);
strcat(str,tmp);
//printf("\nstrlen=%i num=%s\n",strlen(str),str);

return str;
}




int main(){

char * s1 = Dec2Hex(-17);
char * s2 = Dec2Hex(137);
char * s3 = Dec2HexF(0.28);
char * s4 = Dec2HexF(-1.4);

printf("s1=%s s2=%s s3=%s s4=%s\n",s1,s2,s3,s4);

return 0;}
