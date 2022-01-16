#include <sys/io.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>


typedef union word{ //структура для разделения слова на младший и старший байты
unsigned short  w;
struct b {
unsigned char l;
unsigned char h;}b;
}word;


int main(){

const unsigned short int tmrc = 0x43; //timer control register
const unsigned short int chrc = 0x42; //channel control register
const unsigned short int kbrd = 0x61; //keyboard control register
ioperm(tmrc,1,true);//делаем доступ
ioperm(kbrd,1,true);//
ioperm(chrc,1,true);//

unsigned char skb;//сохраняем исходные значения
unsigned char stm;
unsigned char sch;
skb = inb(kbrd);
stm = inb(tmrc);
sch = inb(chrc);


unsigned char kb=skb;//чтобы не "испортить" статус клавиатуры

//генерирует прямоугольные импульсы с частотой, равной 1 193 180/начальное_значение_счетчика=2000. 
//начальное_значение_счетчика=597
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
F 1111
устанавливае значение в  управляющий регистр первого таймера
    биты 7 – 6: если не 11 — это номер канала, который будет программироваться
        10 = канал 2
    биты 5 – 4:
        11 — чтение/запись сначала младшего, а потом старшего байта
    биты 3 – 1: режим работы канала
        011: генератор прямоугольных импульсов (основной режим)
    бит 0: формат счетчика:
        0 — двоичное 16-битное число (0000 – FFFFh)
   10110110=0b6
*/

outb(0xb6,tmrc);//пишем в упрвляющий регистр
usleep(1);//ждем
word w;
w.w=597;//задаем начальнрое значение счетчика
printf("w=%x l=%x h=%x\n",w.w,w.b.l,w.b.h);//выводим для контроля старший и младший байты
outb(w.b.l,chrc);//запись младшего
usleep(1);
outb(w.b.h,chrc);//запись старшего


kb|=0x3;//включаем динамик ПК
outb(kb,kbrd);
sleep (3);//слушаем 3 сек
//восстанавливаем регистры
outb(skb,kbrd);
outb(stm,tmrc);
outb(sch,chrc);
puts("fin");
return 0;}
