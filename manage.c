#include <stdio.h>
#include <stdlib.h>
#include "manage.h"
#include <string.h>


Item *get_input(void)
{
	Item *new_line = NULL;
	new_line = (Item *)malloc(sizeof(Item));
	new_line->next = NULL;
	printf("Name:");
	scanf("%s", new_line->name);
	printf("Phone num:");
	scanf("%s", new_line->phone_num);
	
	return new_line;

}


Item *read_to_mem(char *file_name)
{	
	FILE *fp;
	char buf_name[NAME_LEN_MAX] = {0};
	char buf_num[PHONE_NUM_LEN_MAX] = {0};
	char ch;
	int len;
	int file_size = 0;
	Item *head = NULL;
	Item *prev = NULL;
	
	Item *new_item = NULL;
	
	fp = fopen(file_name, "r");
	if (NULL == fp) {
		return NULL;
	}
	
	
	int state = 0;
	len = 0;

	while ((ch = getc(fp)) != EOF) {
		
		switch(state) {
		case 0:
			buf_name[len] = ch;
			len++;
			if (':' == ch) {
				state = 1;
				buf_name[len-1] = '\0';
				len = 0;
			}
			break;
		case 1:
			buf_num[len] = ch;
			len++;
			if ('\n' == ch) {
				state = 0;
				buf_num[len-1] = '\0';
				len = 0;
				new_item = NULL;
				new_item = (Item *)malloc(sizeof(Item));
				if (NULL == new_item) {
					printf("Memory error\n");
					exit(2);
				}
			
				int i = 0;
				for (i = 0; i < NAME_LEN_MAX; i++) {
					new_item->name[i] = buf_name[i];
				}
				
				
				for (i = 0; i < PHONE_NUM_LEN_MAX; i++) {
					new_item->phone_num[i] = buf_num[i];
				}
				
				if (NULL == prev) {
					prev = new_item;
					head = new_item;
				} else {
					prev->next = new_item;
					//new_item->next = NULL;
					prev = new_item;
				}
			}
			break;
		default:break;
		}
	}	
	fclose(fp);
	fp = NULL;
	
	return head;
}


static char *my_strdup(char *src)
{
	char *dest;
	
	dest = malloc(sizeof(char) * (strlen(src) +1));
	strcpy(dest, src);
	return dest;
}


void add_to_list(Item *head, Item *new_item)
{
	Item *temp;
	
	if (NULL == head) {
		temp = new_item;	
	} else {
		while(head->next != NULL) {
			head = head->next;
		}
		head->next = new_item;
	}
	head = temp;
}


void find_info()
{}



void del_info()
{}
void show_info()
{}


void free_all(Item *head)
{
	Item *tmp;
	
	while (head != NULL) {
		tmp = head;
		head = head->next;
		free(tmp);
	}

}

void write_to_file(Item *head, char *file)
{
	
	FILE *f;
	Item *pos;
	f = fopen(file, "w+");

	if (NULL == f)  {
		printf("error to open file\n");
		return;
	}
	for (pos = head; pos != NULL; pos = pos->next) {
		fprintf(f, "%s:%s\n", pos->name, pos->phone_num);
	}
	fclose(f);

}
void finish()
{}


