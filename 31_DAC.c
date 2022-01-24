#include <stdio.h>

int checkbit(const int value, const int position) {
    return ((value & (1 << position)) != 0);}

void printbits(unsigned char n) {
    size_t len = 10;
    size_t i;
    for (i = len; i ; i--) {
        printf("%d", checkbit(n, i-1));
    }}

int main(){
unsigned char R=35;
unsigned char G=37;
unsigned char B=39;
printf("Содержимое DAC видеоадаптера для R=%i G=%i B=%i\n",R,G,B);
printbits(R); printf(" ");
printbits(G); printf(" ");
printbits(B); printf("\n");

return 0;}
