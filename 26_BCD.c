#include <stdio.h>

int BCD2Int(char byte){int rez=((byte&0xf0)>>4)*10;rez+=byte&0xf;return rez;}//

unsigned char Ch2BCD(char byte){char rez=(byte/10)<<4;rez+=byte%10;return rez;}//

int main(){
char a=27;
char b=94;
printf("In dec a=%i b=%i\n",a,b);
printf("In BCD a=%i b=%i\n",BCD2Int(a),BCD2Int(b));
printf("BCD a+b=%i\n",BCD2Int(a+b));
printf("BCD a-b=%i\n",BCD2Int(a-b));
puts("fin");
return 0;}
