#include <stdio.h>
#include <stdlib.h>
#include "manage.h"
#include <string.h>

int length_of_list(Item *list)
{
	int length = 0;
	while (list != NULL) {
		length++;
		list = list->next;
	}
	
	return length;
}

static int exchange(Item *a, Item *b)
{
	char name_temp[NAME_LEN_MAX] = {0};
	char phone_num_temp[PHONE_NUM_LEN_MAX] = {0};
	
	
	memcpy(name_temp, a->name, NAME_LEN_MAX);
	memcpy(a->name, b->name, NAME_LEN_MAX);
	memcpy(b->name, name_temp, NAME_LEN_MAX);
	
	memcpy(phone_num_temp, a->phone_num, PHONE_NUM_LEN_MAX);
	memcpy(a->phone_num, b->phone_num, PHONE_NUM_LEN_MAX);
	memcpy(b->phone_num, phone_num_temp, PHONE_NUM_LEN_MAX);

	return 0;
}

Item *sort(Item *head)
{
	int list_length = 0;
	int i  = 0;
	int j = 0;

	Item *p = NULL;
	Item *old_head = NULL;

	list_length = length_of_list(head);

	old_head = head;
	i = list_length - 1;
	while (i != 0) {
		
		j = i;
		head = old_head;
		while (j != 0) {
			p = head;
			if (0 < strcmp(p->name, p->next->name)) {
				exchange(p, p->next);
			}
			head = head->next;
			j--;
		}
		i--;
	}

	return old_head;
	

}


void find_info(Item *head, char *find_value)
{
	int isfind = 0;
	
	if (NULL == head) {
		printf("sorry! phone book is empty!\n");
		return;
	}
	
	while (head != NULL) {
		if (0 == strcmp(head->name, find_value) || 0 == strcmp(head->phone_num, find_value)) {
			printf("------------------------------------------------------------------");
			printf("\nname is:      %s\nphone_num is: %s\n", head->name, head->phone_num);
			isfind = 1;
		}
		head = head->next;
	}
	
	if (!isfind) {
		printf("Sorry! can't find it.\n");
	}
}

Item *del_form_list(Item *head, char *del_value)
{
	Item *prev = NULL;
	Item *temp = NULL;
	Item *old_head;
	old_head = head;
	
	if (NULL == head) {
		printf("sorry! phone book is empty!\n");
		return head;
	}
	while (head != NULL) {
		temp = head;
		if (0 == strcmp(head->name, del_value) || 0 == strcmp(head->phone_num, del_value)) {
			printf("ok!, %s is finded.\n", del_value);
			if (NULL != prev) {
				printf("NULL != prev\n");
				prev->next = head->next;
				head->next = NULL;
				head = prev->next;
				free(temp);
				head = old_head;
				return head;
				
			} else {
				head = head->next;
				temp->next = NULL;
				free(temp);
				return head;
			}
			
		} 
		prev = head;
		head = head->next;
	}
	if (NULL == head) {
		printf("Cant't find what you want!!\n");
	}
	head = old_head;
	return head;

}


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


Item *add_to_list(Item *head, Item *new_item)
{
	Item *temp;
	temp = head;
	
	if (NULL == head) {
		head = new_item;
		return head;
	} else {
		while(head->next != NULL) {
			head = head->next;
		}
		head->next = new_item;
		head = temp;
		return head;
	}
	
}



void show_info(Item *head)
{
	if (NULL == head) {
		printf("Phone book is empty!\n");
		return;
	}
	printf("----------------------------------------------------------\n");
	while (head != NULL) {
		
		printf("| %-20s:		%-25s|\n", head->name, head->phone_num);
		
		head = head->next;
	}
	printf("----------------------------------------------------------\n");
	

}


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
void help_info(void)
{
	printf("usage: book [options]\n");
	printf("Valid options are:\n");
	printf("");
	printf("	add ");
	printf("		--Add a member to the book.\n\n");
	printf("	del ");
	printf("		--Delete a member from the book.\n\n");
	printf("	find ");
	printf("		--Find a member from the book and show it.\n\n");
	printf("	show ");
	printf("		--Show all members of the book.\n");
	printf("	sort ");
	printf("		--Sort by name.\n");
}


