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


char * Dec2nOct(int num){

int remain=0;
int rez;
char * str = (char*)malloc(180);
int p=0;
 str[p]='-';p++;
rez=num;
while (rez>8)
{remain=rez%8;
rez/=8;
str[p]=0x30+remain;
p++;
//printf("%i",remain);
}
//printf("%i\n",rez);
str[p]=0x30+rez;
str[p+1]=0;
//printf("strlen=%i num=%s\n",strlen(str),str);
strrev(str);
return str;
}

char * Dec2Oct(int num){

int remain=0;
int rez;
char * str = (char*)malloc(180);
int p=0;
if (num<0) {num=-num; str[p]='-';p++;}
rez=num;
while (rez>8)
{remain=rez%8;
rez/=8;
str[p]=0x30+remain;
p++;
//printf("%i",remain);
}
//printf("%i\n",rez);
str[p]=0x30+rez;
str[p+1]=0;
//printf("strlen=%i num=%s\n",strlen(str),str);
strrev(str);
return str;
}

char * Dec2OctF(float num){
int remain=0;
char tmp[2];tmp[1]=0;
int numI = (int)num;
char * str;
if (num<0) {num=-num;numI=-numI;str=Dec2nOct(numI);}
		else{str=Dec2Oct(numI);}
float frct=num-numI;
strcat(str,".");
//printf("Integer part=%s\n",str);
float rez=frct;
rez=frct*8;
remain=(int)rez;
while (remain)
{remain=(int)rez;
rez=(rez-remain)*8;
tmp[0]=0x30+remain;
strcat(str,tmp);
//printf("%i",remain);
}
//printf("%i\n",rez);
tmp[0]=0x30+rez;
strcat(str,tmp);
//printf("strlen=%i num=%s\n",strlen(str),str);

return str;
}

char * Oct2Bin(char * str){
char * bin = (char*)malloc(512);
for (int a=0;a<strlen(str);a++)
switch (str[a]){
case	'0': strcat(bin,"000");break;
case	'1': strcat(bin,"001");break;
case	'2': strcat(bin,"010");break;
case	'3': strcat(bin,"011");break;
case	'4': strcat(bin,"100");break;
case	'5': strcat(bin,"101");break;
case	'6': strcat(bin,"110");break;
case	'7': strcat(bin,"111");break;
case	'-': strcat(bin,"-");break;
case	'.': strcat(bin,".");break;	
}
return bin;}


int main(){

char * s1 = Dec2Oct(-17);
char * s2 = Dec2Oct(137);
char * s3 = Dec2OctF(0.28);
char * s4 = Dec2OctF(-0.4);

printf("s1=%s s2=%s s3=%s s4=%s \n",Oct2Bin(s1),Oct2Bin(s2),Oct2Bin(s3),Oct2Bin(s4));



return 0;}
