#include <limits.h>
#include <stdio.h>
#include <string.h>

int checkbit(const int value, const int position) {//функция проверяет бит на 0/1
    return ((value & (1 << position)) != 0);
}
void printbits(int n) {//печатает последовательность бит в байте
    size_t len = 8;
    size_t i;
    for (i = 0; i < len; i++) {
        printf("%d", checkbit(n, i));
    }}

void RLL(char b){//функция счетчик
static char c1=0;//количество единиц
static char c0=0;//количество нулей
static char rez[4];//входная двоичная последовательность не может быть длинее 4 бит
if ((c1==3)|(c0==3)|((c1+c0)==4)) {//если накопилось 3 диницы или 3 ноля 
if (!strcmp(rez,"11")) {printf("T000");}//выводим варианты
if (!strcmp(rez,"011")) {printf("00T000");}
if (!strcmp(rez,"010")) {printf("T00T00");}
if (!strcmp(rez,"0011")) {printf("0000T000");}
if (!strcmp(rez,"0010")) {printf("00T00T00");}
if (!strcmp(rez,"000")) {printf("000T00");}
if (c1==3) {c1=1;c0=0;} else {c1=0;c0=0;}//не может быть подряд больше двух единиц
rez[0]=0;//обнуляем строку-последовательность
return;}
if (b){ c1++; strcat(rez,"1");} else {c0++;strcat(rez,"0");}//приращиваем счетчики формируем последовательность
if (!strcmp(rez,"10")) {printf("0T00");rez[0]=0;c1=0;c0=0;}//частный случай "10"
}

int main(){
char data[]="ADDY";//задание
printf("data:");for (int i=0;data[i];i++) printbits(data[i]); printf("\n");//выводим задание в двоичной форме
printf("MFMc:");//выводим кодированную MFM последовательность
for (int i=0;data[i];i++) //итерация по символам  задания
 for (int b=0;b<8;b++) RLL(checkbit(data[i],b));//создаем поток двоичнх данных
puts("fin");
return 0;}
