#include <stdio.h>
#include <stdbool.h>
#include <sys/io.h>
#include <unistd.h>



int main(){

puts("Требуется sudo");
const unsigned short int kbrd = 0x60; //keyboard data register
const unsigned short int kbcn = 0x64; //keyboard control register
ioperm(kbrd,1,true);//
ioperm(kbcn,1,true);//

unsigned char skb;//

while (1)
{skb = inb(kbrd);
if (skb) printf("%i \r",skb);
}
/*
LSift+H=35
LSift+I=23
LSift+,=51
LSift+A=30
LSift+L=38
LSift+!=2
*/

puts("fin");
return 0;}
