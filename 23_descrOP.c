#include <stdio.h>


int checkbit(const int value, const int position) {
    return ((value & (1 << position)) != 0);}

void printbits(unsigned char n) {
    size_t len = 8;
    size_t i;
    for (i = len; i ; i--) {
        printf("%d", checkbit(n, i-1));
    }}

typedef struct tdesc{
unsigned char seglim[2];
unsigned char base[2];
}tdesc;


union des{
tdesc desc;
unsigned char raw[8];
}des;

/* таблица перевода двоичных в шестиричные числа
1 0001
2 0010
3 0011
4 0100
5 0101
6 0110
7 0111
8 1000
9 1001
A 1010
B 1011 
C 1100
D 1101 
E 1110
F 1111*/

int main(){

des.raw[0]=0xc8;
des.raw[1]=0x0d;
des.raw[2]=0x36;
des.raw[3]=0x12;
des.raw[4]=0x00;
des.raw[5]=0x80;
des.raw[6]=0x20;
des.raw[7]=0x00;

printf("Segment Limit(15-0):");printbits(des.desc.seglim[1]);printf("-");printbits(des.desc.seglim[0]);
printf ("\nBase adress:%X\n",des.desc.seglim[0]);
printf ("Type:%X\n",des.desc.seglim[1]&0x0f);
printf ("S:%X\n",(des.desc.seglim[1]&0x10)>>4);
printf ("DPL:%X\n",(des.desc.seglim[1]&0x60)>>5);
printf ("P:%X\n",(des.desc.seglim[1]&0x80)>>7);

printf("Base Adress(15-0):");printbits(des.desc.base[1]);printf("-");printbits(des.desc.base[0]);
printf ("\nLimits:%X\n",des.desc.base[0]&0xf);
printf ("A:%X\n",(des.desc.base[0]&0x10)>>4);
printf ("DB:%X\n",(des.desc.base[0]&0x40)>>7);
printf ("G:%X\n",(des.desc.base[0]&0x80)>>8);
printf ("Base address:%X\n",des.desc.base[1]);

return 0;}
