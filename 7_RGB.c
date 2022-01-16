#include <stdio.h>

typedef struct tRGB{ //структура для хранения компонент
	int r,g,b;
 }tRGB;

int checkbit(const int value, const int position) {//проверяет бит по номеру
    return ((value & (1 << position)) != 0);
}

void printbits(int n) {//вывод числа в двоичной форме
    int len = 16;//максимальная длинна вывода
    for (int i = len; i ; i--) {
        printf("%d", checkbit(n, i-1));
    }}

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
tRGB splitCol(int col){//расщепляет цвет на RGB
tRGB rez;
rez.r = (col & 0xf800)>>11 ;//домножаем ненужные биты на ноль и сдвигаем 5 бит красного цвета влево
rez.g = (col & 0x07e0)>>5 ;//домножаем ненужные биты на ноль и сдвигаем 6 бит зеленого цвета влево
rez.b = (col & 0x1f);//домножаем лишние биты на ноль и ничего не сдвигаем синий т.к. он и так слева
return rez;}

int main(){

int col1,col2,col3;

col1=1234;//задание
col2=5678;
col3=9100;
//выводим в двоично и десятичной форме исходные данные
printf("Col=%2i binary=",col1);printbits(col1);printf("\n");
printf("Col=%2i binary=",col2);printbits(col2);printf("\n");
printf("Col=%2i binary=",col3);printbits(col3);printf("\n\n");
tRGB rgb;

printf("Color=%i:\n",col1);
rgb=splitCol(col1);//расщепляем на компоненты
printf("R=%2i binary=",rgb.r);printbits(rgb.r);printf("\n");//печатаем красный
printf("G=%2i binary=",rgb.g);printbits(rgb.g);printf("\n");//зеленый
printf("B=%2i binary=",rgb.b);printbits(rgb.b);printf("\n");//синий

printf("Color=%i:\n",col2);
rgb=splitCol(col2);
printf("R=%2i binary=",rgb.r);printbits(rgb.r);printf("\n");
printf("G=%2i binary=",rgb.g);printbits(rgb.g);printf("\n");
printf("B=%2i binary=",rgb.b);printbits(rgb.b);printf("\n");

printf("Color=%i:\n",col3);
rgb=splitCol(col3);
printf("R=%2i binary=",rgb.r);printbits(rgb.r);printf("\n");
printf("G=%2i binary=",rgb.g);printbits(rgb.g);printf("\n");
printf("B=%2i binary=",rgb.b);printbits(rgb.b);printf("\n");

return 0;
}




