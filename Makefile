all:
	gcc *.c  -g
1:
	gcc 1_CMOS.c -o cmos -g -Wall -Wpedantic -masm=att
2:
	gcc 2_BCD.c -o a_plus_b  
3:
	gcc 3_DAC.c -o dac
4:
	gcc 4_timer.c -o timer -g -Wall -Wpedantic -masm=att
5:
	gcc 5_ADDY.c -o addy_mfm
6:	
	gcc 6_vga256.c -o vga256
7:	
	gcc 7_RGB.c -o rgb -g
8:
	gcc 8_float32.c -o float32 -lm
9:
	gcc 9_ADDY_RLL27.c -o addy_rll


