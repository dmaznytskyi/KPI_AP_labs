#include <stdio.h>;
#include <curses.h>;

int roman(int,int,char);

main() {
	int a;
	printf("enter number\n");
	scanf("%d",&a);
	a = roman(a,1000,'M');
	a = roman(a,500,'D');
	a = roman(a,100,'C');
	a = roman(a,50,'L');
	a = roman(a,10,'X');
	a = roman(a,5,'V');
	a = roman(a,1,'I');
	getch();
	return 0;
}

roman(int i,int j,char c){
	while (i>=j) {
		putchar(c);
		i=i-j;
	}
	return i;
}

//	пересобрать кучу "а" как массив (двумерный)
//
//	int array_num[7] = {1000,500,100,50,10,5,1};
//	char array_char[7] = {'M','D','C','L','X','V','I'};
//	int a;
//	int buff;
//	scanf("%d",&a);
//	while a>0 do {
//		int i = 0;
//		while a>array_num[i] do {
//			a = a - array_num[i];
//		}
//	i++;
//	}