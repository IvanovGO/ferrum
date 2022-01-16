#include <stdio.h>

int BCD2Int(char byte){int rez=((byte&0xf0)>>4)*10;rez+=byte&0xf;return rez;}//

unsigned char Ch2BCD(char byte){char rez=(byte/10)<<4;rez+=byte%10;return rez;}//

int main(){
char a=46;
char b=54;
printf("In BCD a=%i b=%i\n",a,b);
printf("In dec a=%i b=%i\n",BCD2Int(a),BCD2Int(b));
printf("a+b=%i\n",BCD2Int(a)+BCD2Int(b));
printf("a-b=%i\n",BCD2Int(a)-BCD2Int(b));
puts("fin");
return 0;}
