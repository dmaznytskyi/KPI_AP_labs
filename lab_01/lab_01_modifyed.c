#include <stdio.h>;
#include <curses.h>;

int roman(int,int,char);

main() {
	int a;
	printf("enter number\n");
	scanf("%d",&a);
	int array_num[7] = {1000,500,100,50,10,5,1};
	char array_char[7] = {'M','D','C','L','X','V','I'};
	int i = 0;
	while (a>0){
		while (a>=array_num[i]){
			a = a - array_num[i];
			//printf("%d", a);
			putchar(array_char[i]);
		}
	i++;
	}
	return 0;
	getch();
}	