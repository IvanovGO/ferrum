#include <limits.h>
#include <stdio.h>

/*
Основное правило кодирования для MFM состоит в том, что Ноль кодируется как 10 , если ему предшествует ноль, и 00 , если ему предшествует единица ; единица всегда кодируется как 01*/
int checkbit(const int value, const int position) {//функция проверяет бит на 0/1
    return ((value & (1 << position)) != 0);
}
void printbits(int n) {//печатает последовательность бит в байте
    size_t len = 8;
    size_t i;
    for (i = 0; i < len; i++) {
        printf("%d ", checkbit(n, i));
    }}
int main(){
char data[]="ADDY";//задание
printf("data:");for (int i=0;data[i];i++) printbits(data[i]); printf("\n");//выводим задание в двоичнойформе
printf("MFMc:");//выводим кодированную MFM последовательность
for (int i=0;data[i];i++) //итерация по символам  задания
	for (int pos=0;pos<8;pos++)//итерация по битам 
	if (i) {//если не самый первый символ
		if (pos) // и не нулевой в байте
			{ if (checkbit(data[i],pos)) //определяем  1/0
				{printf("01");} //1 если один то печатаем всегда одно и тоже
					else {//0 иначе ноль
				if (checkbit(data[i],pos-1)) {printf("00");}//и если предыдущий 1 то 00
				else {printf("10");}}//а если предыдущий 0 то 10
				}else{//если бит первый (нулевой)
			 if (checkbit(data[i],pos)) {printf("01");}// то тоже самое
			   else//только сверяемся в последним битом в предыдущем байте
			 { if (checkbit(data[i-1],7)) {printf("00");}//prev-1
						else  {printf("10");}}}} //prev-0
	        else {//у первого символа в последовательности предыдущий всегда ноль
			if (checkbit(data[i],pos)) {printf("01");} //1 
					else  {printf("00");}//0
						     } printf("\n");
puts("fin");
return 0;}
