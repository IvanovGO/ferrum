#include <stdio.h>

int checkbit(const int value, const int position) {
    return ((value & (1 << position)) != 0);}

void printbits(unsigned char n) {
    size_t len = 10;
    size_t i;
    for (i = len; i ; i--) {
        printf("%d", checkbit(n, i-1));
    }}

unsigned int BCD2Int(unsigned char byte){unsigned int rez=((byte&0xf0)>>4)*10;rez+=byte&0xf;return rez;}//

unsigned char Ch2BCD(unsigned char byte){unsigned char rez=(byte/10)<<4;rez+=byte%10;return rez;}//
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
unsigned char a=0xce;
unsigned char b=0x6f;
printf(" a=%3i     b=%3i ",a,b);printbits(a);printf(" ");printbits(b);printf("\n");
printf(" a|b=%3i a^b=%3i ",a|b,a^b);printbits(a|b);printf(" ");printbits(a^b);printf("\n");
printf("a|b=%3i ",Ch2BCD(a|b));printbits(Ch2BCD(a|b));printf("\n");
printf("a^b=%3i ",Ch2BCD(a^b));printbits(Ch2BCD(a^b));printf("\n");
puts("fin");
return 0;}
