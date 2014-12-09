#include <stdio.h>
#include <stdlib.h>
#include "manage.h"

#define WORD_LEN_MAX (1024)
#define PHONE_BOOK "phone_book"

Item *creat_line(void)
{
	Item *p;
	p = malloc(sizeof(Item));
	if (NULL == p)
		return;
	p->next = NULL;
	//p->phone_num = "123456";
	return p;
}


int get_word(char *buf, int buf_size, FILE *fp)
{
	int len;
	int ch;
	while ((ch = getc(fp)) != EOF && !isalnum(ch))
		;
	if (ch == EOF) {
		return EOF;
	}	

	len = 0;
	do {
		buf[len] = ch;
		len++;
		if (len >= buf_size) {
			fprintf(stderr,"word too long.\n");
			exit(1);
		}
	} while ((ch = getc(fp)) != EOF && isalnum(ch));
	buf[len] = '\0';
	
	return len;
}


Item *get_info(void)
{
	Item *tmp_line = NULL;
	tmp_line = creat_line();
	printf("Name:");
	scanf("%s", tmp_line->name);
	//printf("name------%s\n", tmp_line->name);
	printf("Phone num:");
	scanf("%s", &tmp_line->phone_num);
	//printf("num-----%s\n", tmp_line->phone_num);
	return tmp_line;
}


static char *my_strdup(char *src)
{
	char *dest;
	
	dest = malloc(sizeof(char) * (strlen(src) +1));
	strcpy(dest, src);
	return dest;
}



Item *new_line(char *buf)
{
	Item *tmp_line = creat_line();
	tmp_line->name = my_strdup(buf);
	tmp_line->phone_num = "";
	tmp_line->next = NULL;
	return tmp_line;
}


void add_to_list()
{
	char buf[WORD_LEN_MAX];
	FILE *fp;

	fp = fopen(PHONE_BOOK,"a+");
	if (NULL == fp) {
		printf("Open file error!\n");
		return;
	}
	
	while (get_word(buf, WORD_LEN_MAX, fp) != EOF) {

		printf("%s\n", buf);
		add_line(buf);
	}
}




void find_info()
{}

void add_line(char *buf)
{
	Item *head_line;
	Item *pos;
	head_line = get_info();
	pos = new_line(buf);

	if (strcmp(head_line->name, pos->name) > 0) {
		
	}
	
	for (pos = head_line; pos != NULL; pos = pos->next) {
		if (strcmp(buf, pos->name) > 0) {
			
		}
	}
}


void del_info()
{}
void show_info()
{}
void write_to_file()
{}
void finish()
{}


