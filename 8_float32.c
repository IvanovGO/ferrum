#include <math.h>
#include <stdio.h>



float F(int S, int E, int M){
return pow(-1,S)*pow(2,(E-127))*(1+M/pow(2,23));
}


int main(){


printf("Ответ=%f\n",F(0,134,1810432));//155,625 https://www.softelectro.ru/ieee754.html
printf("Ответ=%f\n",F(1,0xff,0));//Ответ минус бесконечность

return 0;
}

