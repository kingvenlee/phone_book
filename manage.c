#include <stdio.h>
#include <stdlib.h>
#include "manage.h"



Item *get_input(void)
{
	Item *new_line = NULL;
	new_line = malloc(sizeof(Item));
	new_line->next = NULL;
	printf("Name:");
	scanf("%s", new_line->name);
	//printf("name------%s\n", tmp_line->name);
	printf("Phone num:");
	scanf("%s", &new_line->phone_num);
	//printf("num-----%s\n", tmp_line->phone_num);
	return new_line;
}




Item *read_to_mem(char *file_name)
{	
	FILE *fp;
	char buf_name[NAME_LEN_MAX];
	char buf_num[PHONE_NUM_LEN_MAX];
	char ch;
	int len;

	Item *head = NULL;
	Item *new_item;

	printf("in read_to_mem.\n");
	printf("filename = %s\n",file_name);
	fp = fopen(file_name, "r");
	if (NULL == fp) {
		printf("Open file error!\n");
		return;
	}

	printf("start while.\n");
	while ((ch = getc(fp)) != EOF) {
		
		memset(buf_name,0,sizeof(buf_name));
		memset(buf_num,0,sizeof(buf_name));
		len = 0;
		do {
			buf_name[len] = ch;
			len++;
		} while ((ch = getc(fp)) != ':');
		buf_name[len] = '\0';

		ch = getc(fp);/*to ignore ':'*/
		len = 0;
		do {
			buf_num[len] = ch;
			len++;
		} while ((ch = getc(fp)) != '\n');
		buf_num[len] = '\0';
		
		new_item = malloc(sizeof(Item));
		memcpy(new_item->name, buf_name, NAME_LEN_MAX);
		memcpy(new_item->phone_num, buf_num, PHONE_NUM_LEN_MAX);
		//printf("name----%s\n",new_item->name);
		//printf("num----%s\n",new_item->phone_num);
		new_item->next = head;
		head = new_item;
		printf("name----%s\n",head->name);
		printf("num----%s\n",head->phone_num);		
		
	}

	printf("while is over!\n");
	fclose(fp);
	return head;
}


static char *my_strdup(char *src)
{
	char *dest;
	
	dest = malloc(sizeof(char) * (strlen(src) +1));
	strcpy(dest, src);
	return dest;
}

/*
void add_to_list(Item *head, Item *new_item)
{
	Item *pos;
	Item *prev = NULL;

	printf("start for.\n");
	printf("new_item-name is:%s\n", new_item->name);
	printf("head-name is:%s\n", head->name);
	for (pos = head; pos != NULL; pos = pos->next) {
		if (0 <= strcmp(pos->name, new_item->name)) {
			break;	
		}
		prev = pos;	
	}
	printf("for is over!\n");
	new_item->next = pos;
	printf("11\n");
	prev->next = new_item;
	printf("22\n");
}
*/

void find_info()
{}



void del_info()
{}
void show_info()
{}

void write_to_file(Item *head, char *file)
{
	Item *pos;
	FILE *fp;
	fp = fopen(file, "w+");
	if (NULL == fp)  {
		printf("error to open file\n");
	}
	for (pos = head; pos != NULL; pos = pos->next) {
		
		//printf("name is: %s\n", pos->name);
		//printf("num is: %s\n", pos->phone_num);

		fprintf(fp, "%s:%s\n", pos->name, pos->phone_num);
	}
	fclose(fp);

}
void finish()
{}


