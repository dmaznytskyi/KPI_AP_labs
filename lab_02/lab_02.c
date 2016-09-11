#include <stdio.h>
#include <curses.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

float side_a;
float side_b;
float side_c;

char forbiden[] = "abcdefghijklmnopqrstuvwxyzйцукенгшщзхъфывапролджэячсмитьбю!@#$%%^&*()_+-=\\|'\"/,{}[]";
char input_buffer[100];

float area();
float perimetr();
float pperimetr();
void heights();
void bisektrisi();
void mediani();
void input_promt_checker();


int main(void){
	input_promt_checker();
	printf("Площадь равна %.3f еденицам\n", area());
	printf("\nПериметр равен %.3f еденицам\n", perimetr());
	heights();
	bisektrisi();
	mediani();
	getch();
	return 0;
}

//площа
float area(){
	return sqrt(pperimetr()*(pperimetr()-side_a)*(pperimetr()-side_b)*(pperimetr()-side_c));
}	
//периметр
float perimetr(){
	return (side_a + side_b + side_c);
}
//высоты
void heights(){
	printf("\nВысота, проведённая к первой стороне равна %.3f еденицам.\nВысота, проведённая ко второй стороне равна %.3f еденицам.\nВысота, проведённая к третьей стороне равна %.3f еденицам.\n", (2*area()/side_a),(2*area()/side_b),(2*area()/side_c));
}
//бисектрисы
void bisektrisi(){
	printf("\nБисектриса, проведённая к первой стороне равна %.3f еденицам.\nБисектриса, проведённая ко второй стороне равна %.3f еденицам.\nБисектриса, проведённая к третьей стороне равна %.3f еденицам.\n", ( (2/(side_b+side_c))*sqrt(side_b*side_c*pperimetr()*(pperimetr()-side_a)) ),( (2/(side_a+side_c))*sqrt(side_a*side_c*pperimetr()*(pperimetr()-side_b)) ),( (2/(side_a+side_b))*sqrt(side_a*side_b*pperimetr()*(pperimetr()-side_c)) ) );
}
//медианы
void mediani(){
	printf("\nМедиана проведённая к первой стороне равна %.3f еденицам.\nМедиана проведённая ко второй стороне равна %.3f еденицам.\nМедиана проведённая к третьей стороне равна %.3f еденицам.\n",(sqrt(2*side_b*side_b+2*side_c*side_c-side_a*side_a)/2),(sqrt(2*side_a*side_a+2*side_c*side_c-side_b*side_b)/2),(sqrt(2*side_a*side_a+2*side_b*side_b-side_c*side_c)/2));
}
//воспомогательный полупериметр
float pperimetr(){
	return perimetr()/2;
}
//vvod i ego proverka @POWERED BY : LISOVICHENKO_PROTECT_ALFA
void input_promt_checker(void){
	while (true){
		printf("Введите стороны треугольника (они должны быть больше нуля!)\n");	
		for(int i =0; i<3; i++){
			printf("Введите %d сторону и нажмите enter: ",(i+1));
			scanf("%s", &input_buffer);
			if (strpbrk(input_buffer, forbiden) != NULL){
				printf("\nВы ввели текст! Надо ввести число!\n");
				break;
			} else {
				if (i==0) side_a = atof(input_buffer);
				if (i==1) side_b = atof(input_buffer);
				if (i==2) side_c = atof(input_buffer);
			}
		}
		if ((side_a>0)&&(side_b>0)&&(side_c>0)) {
			if (((side_a+side_b)>side_c)&&((side_b+side_c)>side_a)&&((side_c+side_a)>side_b)){
				break;
			} else { 
				printf("Треугольник со сторонами %.3f, %.3f и %.3f НЕ СУЩЕСТВУЕТ!\nПопробуйте ввести правильные данные!\n\n",side_a,side_b,side_c);
			}
		} else printf("Введённые стороны треугольнка не могут быть меньше или равны нулю.\nПопробуйте ввести правильные данные!\n\n");
	}
	puts("\nВведённые стороны верны. Начинаю вычисление...\n");
}