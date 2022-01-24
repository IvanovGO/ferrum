#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef struct troot {
char file_name[8];
char file_extension[3];
char attr;
char reserved[10];
char time[2];
char date[2];
unsigned short int starts;
unsigned  int size;
} troot;

union sec {
troot root;
unsigned char raw[32];
}sec;

void time2root(char * rez,char hh, char mm, char ss){
char tmp[2];
tmp[1]=hh<<3;
tmp[1]=tmp[1]|(mm>>3);
tmp[0]=mm<<5;
tmp[0]=tmp[0]|ss;
rez[1]=tmp[1];
rez[0]=tmp[0];}

void date2root(char * rez,char yy, char mm, char dd){
char tmp[2];
tmp[1]=yy<<1;
tmp[1]=tmp[1]|(mm>>3);
tmp[0]=mm<<5;
tmp[0]=tmp[0]|dd;
rez[1]=tmp[1];
rez[0]=tmp[0];}


int main (){
for (int a=0;a<32;a++) sec.raw[a]=0;
strcpy(sec.root.file_name,"START");
strcpy(sec.root.file_extension,"TXT");
time2root(&sec.root.time,21,55,18);
date2root(&sec.root.date,7,12,6);
sec.root.size=1029;
sec.root.starts=7;
for (int a=0;a!=32;a++) {printf("%X ",sec.raw[a]);}printf("\n");
for (int a=0;a!=32;a++) {printf("%2c ",sec.raw[a]);}printf("\n");
puts("fin");
return 0;}
