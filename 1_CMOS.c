#include <sys/io.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

typedef union tcmos {//обьединение - в одной памяти две структуры
char rtc_buff[0xd]; //буфер для чтения 
struct time_BIOS{//структура для разбора регистров цмос
uint8_t sec,//секунды
	asec,//секунда будильника
	min,//минута 
	amin,// минута будильника
	hour,//часы
	ahour,//часы будильника
	dayoweek,//день недели
	dayomonth,//день недели
	month,//месяц
	year,//год
	statusA,//регистры состояния
	statusB,
	statusC;
}time_BIOS;
}tcmos;


int BCD2Int(char byte){int rez=((byte&0xf0)>>4)*10;rez+=byte&0xf;return rez;}//

unsigned char Ch2BCD(char byte){char rez=(byte/10)<<4;rez+=byte%10;return rez;}//


int main(){

for (int i=0;i<60;i++)
printf(" %i= %i back=%i\n",i,Ch2BCD(i),BCD2Int(Ch2BCD(i)));

tcmos cmos;
ioperm(0x70,2,true);//
const unsigned short int inport = 0x70; //adrr to read/write
const unsigned short int outport = 0x71; //read/write data
puts("Друк області пам'яти:");
for (unsigned char addr = 0x00;addr<0x0d;addr++){
outb( addr ,inport);cmos.rtc_buff[addr] = inb(outport);
printf("rtc_buff[%i]=%i\n",addr,cmos.rtc_buff[addr]);}
printf("Date %i/%i/%i\n",
	BCD2Int(cmos.time_BIOS.year),
	BCD2Int(cmos.time_BIOS.month),
	BCD2Int(cmos.time_BIOS.dayomonth));

puts("Original");
for (unsigned char addr = 0x00;addr<0x0d;addr++){outb( addr ,inport);cmos.rtc_buff[addr] = inb(outport);}
printf("Time %i:%i:%i\r",BCD2Int(cmos.time_BIOS.hour),BCD2Int(cmos.time_BIOS.min),BCD2Int(cmos.time_BIOS.sec));

//saving
char shh = cmos.time_BIOS.hour;
char smm = cmos.time_BIOS.min;
char sss = cmos.time_BIOS.sec;

//set new
char hh = 10;
char mm = 59;
char ss = 15;
cmos.time_BIOS.hour=Ch2BCD(hh);
cmos.time_BIOS.min=Ch2BCD(mm);
cmos.time_BIOS.sec=Ch2BCD(ss);

for (unsigned char addr = 0x00;addr<0x0d;addr++){outb( addr ,inport);outb(cmos.rtc_buff[addr],outport);}
for (unsigned char addr = 0x00;addr<0x0d;addr++){outb( addr ,inport);cmos.rtc_buff[addr] = inb(outport);}
printf("Time %i:%i:%i\n",BCD2Int(cmos.time_BIOS.hour),BCD2Int(cmos.time_BIOS.min),BCD2Int(cmos.time_BIOS.sec));

 hh = 21;
 mm = 42;
 ss = 35;
cmos.time_BIOS.hour=Ch2BCD(hh);
cmos.time_BIOS.min=Ch2BCD(mm);
cmos.time_BIOS.sec=Ch2BCD(ss);

for (unsigned char addr = 0x00;addr<0x0d;addr++){outb( addr ,inport);outb(cmos.rtc_buff[addr],outport);}

for (unsigned char addr = 0x00;addr<0x0d;addr++){outb( addr ,inport);cmos.rtc_buff[addr] = inb(outport);}
printf("Time %i:%i:%i\n",BCD2Int(cmos.time_BIOS.hour),BCD2Int(cmos.time_BIOS.min),BCD2Int(cmos.time_BIOS.sec));

cmos.time_BIOS.hour=shh;
cmos.time_BIOS.min=smm;
cmos.time_BIOS.sec=sss;

for (unsigned char addr = 0x00;addr<0x0d;addr++){outb( addr ,inport);outb(cmos.rtc_buff[addr],outport);}

for (unsigned char addr = 0x00;addr<0x0d;addr++){outb( addr ,inport);cmos.rtc_buff[addr] = inb(outport);}
printf("Time %i:%i:%i\n",BCD2Int(cmos.time_BIOS.hour),BCD2Int(cmos.time_BIOS.min),BCD2Int(cmos.time_BIOS.sec));

puts("fin");
return 0;}
