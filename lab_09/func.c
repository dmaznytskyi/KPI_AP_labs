/* ************************************************************************** */
/*                                                                            */
/*                                                        _____    ______     */
/*   func.c                                              (____ \  |  ___ \    */
/*                                                        _   \ \ | | _ | |   */
/*   By: dmaznytskyi <dmaznytskyi@gmail.com>             | |   | || || || |   */
/*                                                       | |__/ / | || || |   */
/*   Created: 2016/11/03 02:52:15 by dmaznytskyi         |_____/  |_||_||_|   */
/*   Updated: 2017/01/21 00:02:42 by dmaznytskyi                              */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	forbiden[] = "abcdefghijklmnopqrstuvwxyzйцукенгшщзхъфывапролджэячсмитьбю!@#$%%^&*()_+=\\|'\"/{}[]";
char	input_buffer[100];

int ret_int_inp(char *str)
{
	printf("%s\n", str);
	scanf("%s", input_buffer);
	if (strpbrk(input_buffer, forbiden) != NULL)
	{
		error(1);
		error(2);
		return (0);
	}
	else
		return (ft_atoi(input_buffer));
}

double	ret_fl_inp(char *str)
{
	printf("%s\n", str);
	scanf("%s", input_buffer);
	if (strpbrk(input_buffer, forbiden) != NULL)
	{
		error(1);
		printf("У змінну введено '0'");
		return (0);
	}
	else
		return (atof(input_buffer));
}

void	print_menu(void)
{
	printf("\n\e[33m\e[1m>>> МЕНЮ <<<\e[0m\nДоступні дії: \n");
	printf("---------------------------------\n");
	printf("| |- ФАЙЛ			|\n");
	printf("| |-> \e[33m\e[1m[1]\e[0m Створити		|\n");
	printf("| |-> \e[33m\e[1m[2]\e[0m Зчитати		|\n");
	printf("| |-> \e[33m\e[1m[3]\e[0m Видалити		|\n");
	printf("|-------------------------------|\n");
	printf("| |- ЗАПИСИ			|\n");
	printf("| |-> \e[33m\e[1m[4]\e[0m Створити		|\n");
	printf("| |-> \e[33m\e[1m[5]\e[0m Зчитати запис(и)	|\n");
	printf("| |-> \e[33m\e[1m[6]\e[0m Редагувати		|\n");
	printf("| |-> \e[33m\e[1m[7]\e[0m Впорядкувати		|\n");
	printf("| |-> \e[33m\e[1m[8]\e[0m Вставка		|\n");
	printf("| |-> \e[33m\e[1m[9]\e[0m Видалення		|\n");
	printf("|-------------------------------|\n");
	printf("| |-> \e[33m\e[1m[0]\e[0m Вихід			|\n");
	printf("---------------------------------\n");
}

void	create_file(void)
{
	FILE *fp;
	char buf[127];

	printf("Введіть ім'я файлу для створення :\n");
	printf("\e[36m\e[1m");
	scanf("%s", buf);
	printf("\e[0m");

	if ((fp=fopen(buf, "rb")) != NULL)
	{
		printf("\e[31m\e[1m>>> ПОМИЛКА <<<\e[0m Такий файл існує!\n");
		return ;
	}
	if ((fp=fopen(buf, "wb")) == NULL)
	{
		error(11);
		exit(1);
	}
	if (fclose(fp))
	{
		error(12);
		return ;
	}
	printf("Порожній файл, '\e[32m\e[1m%s\e[0m' створено!\n\n", buf);
	printf("Тепер ви можете додати запис через функцію 'ЗАПИСИ -> Створити'");
}

void	remove_file(void)
{
	char buf[127];

	printf("Введіть ім'я файлу для видалення :\n");
	printf("\e[36m\e[1m");
	scanf("%s", buf);
	printf("\e[0m");

	if (remove(buf))
	{
		error(14);
		return ;
	}
	else
		printf("Файл, '\e[32m\e[1m%s\e[0m' видалено!\n\n", buf);
}

void	read_file(void)
{
	FILE *fp;
	int i = 1;
	char buf[127];
	long long cur_pos;
	long long end_pos;
	long long ent_count;
	struct record *ret = malloc(sizeof(struct record));

	printf("Введіть ім'я файлу для читання :\n");
	printf("\e[36m\e[1m");
	scanf("%s", buf);
	printf("\e[0m");

	if ((fp=fopen(buf, "rb")) == NULL)
	{
		error(13);
		return ;
	}
	fseek(fp, 0L, SEEK_END);
	fgetpos(fp, &end_pos);
	rewind(fp);
	fgetpos(fp, &cur_pos);
	ent_count = end_pos / 108;
	printf("Файл '\e[32m\e[1m%s\e[0m' містить %lld записів.\n", buf, ent_count);
	while (cur_pos < end_pos/* + 108*/)
	{
		fread(ret, sizeof(struct record), 1, fp);
		fgetpos(fp, &cur_pos);
		printf("| %d	| %s 	| %f 	| %f 	|\n", i, ret->data, ret->a, ret->b);
		i++;
	}
	if (fclose(fp))
	{
		error(12);
		return ;
	}
}

void	new_note(void)
{
	FILE *fp;
	char buf[127];
	long long ntmp;
	char new[100];

	printf("Введіть ім'я файлу для створення запису :\n");
	printf("\e[36m\e[1m");
	scanf("%s", buf);
	printf("\e[0m");

	if ((fp=fopen(buf, "ab")) == NULL)
	{
		error(13);
		return ;
	}
	fseek(fp, 0L, SEEK_END);
	fgetpos(fp, &ntmp);
	if (ntmp != 0)
	{
		error(15);
		printf("Скористуйтеся опцією 'Вставка'\n");
		return ;
	}
	printf("Введіть інформацію для поля data. Максимум 100 символів :\n");
	scanf(" %[^\n]", new);
	struct record *tmp = malloc(sizeof(struct record));
	ft_strcpy(tmp->data, new);
	tmp->a = ret_fl_inp("Введіть першу змінну типу double");
	tmp->b = ret_fl_inp("Введіть другу змінну типу double");
	fwrite(tmp, sizeof(struct record), 1, fp);
	if (fclose(fp))
	{
		error(12);
		return ;
	}
}

void	read_note(void)
{
	FILE *fp;
	long long cur_pos;
	long long end_pos;
	long long ent_count;
	char buf[127];
	int num = 0;
	struct record *ret = malloc(sizeof(struct record));

	printf("Введіть ім'я файлу для зчитування запису :\n");
	printf("\e[36m\e[1m");
	scanf("%s", buf);
	printf("\e[0m");

	if ((fp=fopen(buf, "rb")) == NULL)
	{
		error(13);
		return ;
	}
	fseek(fp, 0L, SEEK_END);
	fgetpos(fp, &end_pos);
	rewind(fp);
	fgetpos(fp, &cur_pos);
	ent_count = end_pos / 108;
	printf("Файл '\e[32m\e[1m%s\e[0m' містить %lld записів.\n", buf, ent_count);
	num = ret_int_inp("Введіть номер запису для відображення : ");
	if (num > 0)
	{
		fseek(fp, sizeof(struct record) * num - 108, SEEK_SET);
		fread(ret, sizeof(struct record), 1, fp);
		printf("| %s 	| %f 	| %f 	|\n", ret->data, ret->a, ret->b);
	}
	// TODO read notes, depends on user choose
	/* fseek(fp, ((num * 108) - 108), SEEK_SET); */
	if (fclose(fp))
	{
		error(12);
		return ;
	}
}

void	edit_note(void)		//TODO make final
{
	/* FILE *fp; */
	char buf[127];

	printf("\e[36m\e[1m");
	scanf("%s", buf);
	printf("\e[0m");
	long long cur_pos;
	long long end_pos;
	long long ent_count;
	int num = 0;
	struct record *tmp = malloc(sizeof(struct record));

	fseek(fp, 0L, SEEK_END);
	fgetpos(fp, &end_pos);
	fseek(fp, sizeof(sign), SEEK_SET);
	fgetpos(fp, &cur_pos);
	ent_count = (end_pos-sizeof(sign)) / sizeof(struct record);
	printf("File %s contains %lld records\n", filename, ent_count);

	num = returnMinMaxInputInt("Enter record number to edit: ", 1, ent_count);

	fseek(fp, sizeof(sign) + sizeof(struct record) * (num-1), SEEK_SET);
	fread(tmp, sizeof(struct record), 1, fp);
	printf(" %58s | %12s | %12s |\n", "City", "Area", "Population");
	printf(" %58s | %12g | %12d |\n", tmp->city, tmp->area, tmp->population);

	printf("Enter new city name: ");

	fgets (new, 58, stdin);

	if ((strlen(new)>0) && (new[strlen (new) - 1] == '\n'))
		new[strlen (new) - 1] = '\0';

	fflush(stdin);

	strcpy(tmp->city, new);
	tmp->area = returnInputDouble("Enter new area: ");
	tmp->population = returnMinInputInt("Enter new population: ", 0);

	fseek(fp, sizeof(sign) + sizeof(struct record) * (num-1), SEEK_SET);
	fwrite(tmp, sizeof(struct record), 1, fp);

	printf(LGREEN"Record edited!\n"NC);
}

void	sort_notes(void)			//TODO make final
{
	/* FILE *fp; */
	char buf[127];

	printf("\e[36m\e[1m");
	scanf("%s", buf);
	printf("\e[0m");
	long long cur_pos;
	long long end_pos;
	long long ent_count;

	fseek(fp, 0L, SEEK_END);
	fgetpos(fp, &end_pos);
	fseek(fp, sizeof(sign), SEEK_SET);
	fgetpos(fp, &cur_pos);
	ent_count = (end_pos-sizeof(sign)) / sizeof(struct record);

	if(ent_count < 2){
		printf(LRED"Error"NC" You should have 2+ records to sort!\n");
		getch();
		return 0;
	}
	printf("Sort records by area\n");
	if(returnADInt("Sort ascending/descending [a/d]: ") == 1){
		// asc
		//
		// 		for(int a = 0; a < ent_count-1; a++){
		// 					for(int b = a+1; b < ent_count; b++){
		// 									struct record *olda = malloc(sizeof(struct record));
		// 													struct record *oldb = malloc(sizeof(struct record));
		//
		// 																	fseek(fp, sizeof(sign) + sizeof(struct record) * a, SEEK_SET);
		// 																					fread(olda, sizeof(struct record), 1, fp);
		// 																									
		// 																													fseek(fp, sizeof(sign) + sizeof(struct record) * b, SEEK_SET);
		// 																																	fread(oldb, sizeof(struct record), 1, fp);
		// 																																				
		// 																																								double av = olda->area;
		// 																																												double bv = oldb->area;
		//
		// 																																																if(av > bv){ 
		//
		// 																																																					fseek(fp, sizeof(sign) + sizeof(struct record) * a, SEEK_SET);			// a = b
		// 																																																										fwrite(oldb, sizeof(struct record), 1, fp);
		//
		// 																																																															fseek(fp, sizeof(sign) + sizeof(struct record) * b, SEEK_SET);			// b = a
		// 																																																																				fwrite(olda, sizeof(struct record), 1, fp);
		// 																																																																								}
		// 																																																																											}
		// 																																																																													}
		// 																																																																														}
		// 																																																																															else{
		// 																																																																																	for(int a = 0; a < ent_count-1; a++){
		// 																																																																																				for(int b = a+1; b < ent_count; b++){
		// 																																																																																								struct record *olda = malloc(sizeof(struct record));
		// 																																																																																												struct record *oldb = malloc(sizeof(struct record));
		//
		// 																																																																																																fseek(fp, sizeof(sign) + sizeof(struct record) * a, SEEK_SET);
		// 																																																																																																				fread(olda, sizeof(struct record), 1, fp);
		// 																																																																																																								
		// 																																																																																																												fseek(fp, sizeof(sign) + sizeof(struct record) * b, SEEK_SET);
		// 																																																																																																																fread(oldb, sizeof(struct record), 1, fp);
		// 																																																																																																																			
		// 																																																																																																																							double av = olda->area;
		// 																																																																																																																											double bv = oldb->area;
		//
		// 																																																																																																																															if(av < bv){ 
		//
		// 																																																																																																																																				fseek(fp, sizeof(sign) + sizeof(struct record) * a, SEEK_SET);			// a = b
		// 																																																																																																																																									fwrite(oldb, sizeof(struct record), 1, fp);
		//
		// 																																																																																																																																														fseek(fp, sizeof(sign) + sizeof(struct record) * b, SEEK_SET);			// b = a
		// 																																																																																																																																																			fwrite(olda, sizeof(struct record), 1, fp);
		// 																																																																																																																																																							}
		// 																																																																																																																																																										}
		// 																																																																																																																																																												}
		// 																																																																																																																																																													}
		//
		// 																																																																																																																																																														printf(LGREEN"Records sorted!\n"NC);
		// 																																																																																																																																																															read_file();
}

void	insert_note(void)         //TODO make here user input 
{
	FILE *fp;
	char buf[127];
	long long tend_pos;

	printf("Введіть ім'я файлу для додавання запису :\n");
	printf("\e[36m\e[1m");
	scanf("%s", buf);
	printf("\e[0m");

	if ((fp=fopen(buf, "rb")) == NULL)
	{
		error(13);
		return ;
	}
	if ((fp=fopen(buf, "ab")) == NULL)
	{
		error(13);
		return ;
	}
	fseek(fp, 0L, 2);
	fgetpos(fp, &tend_pos);
	printf("1 %lld\n", tend_pos);

	struct record *tmp = malloc(sizeof(struct record));
	ft_strcpy(tmp->data, "Hello bitch!");
	tmp->a = 14.0;
	tmp->b = 2.0;
	fwrite(tmp, sizeof(struct record), 1, fp);
	if (fclose(fp))
	{
		error(12);
		return ;
	}
}

void	delete_note(void)		//TODO make   final
{
	/* FILE *fp; */
	char buf[127];

	printf("\e[36m\e[1m");
	scanf("%s", buf);
	printf("\e[0m");
	long long cur_pos;
	long long end_pos;
	long long ent_count;
	int num = 0;
	struct record *rec = malloc(sizeof(struct record));

	fseek(fp, 0L, SEEK_END);
	fgetpos(fp, &end_pos);
	fseek(fp, sizeof(sign), SEEK_SET);
	fgetpos(fp, &cur_pos);
	ent_count = (end_pos-sizeof(sign)) / sizeof(struct record);
	printf("File %s contains %lld records\n", filename, ent_count);

	num = returnMinMaxInputInt("Enter record number to delete: ", 1, ent_count);

	FILE *ptr2 = fopen("temp","a");

	fseek(ptr2, 0L, SEEK_SET);
	fwrite(sign, sizeof(sign), 1, ptr2);

	fseek(fp, sizeof(sign), SEEK_SET);
	fseek(ptr2, sizeof(sign), SEEK_SET);

	for(int i = 1; i <= ent_count; i++){
		if(i != num) {
			fseek(fp, sizeof(sign) + sizeof(struct record) * (i-1), SEEK_SET);
			fread(rec, sizeof(struct record), 1, fp);

			fseek(ptr2, 0L, SEEK_END);
			fwrite(rec, sizeof(struct record), 1, ptr2);
		}
	}

	fclose(fp);
	fclose(ptr2);
	remove(filename);
	rename("temp", filename);
	remove("temp");
	fp = fopen(filename, "r+b");

	printf(LGREEN"Record deleted!\n"NC);
}
