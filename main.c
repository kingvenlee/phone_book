#include <stdio.h>
#include "manage.h"
#include <string.h>

#define PHONE_BOOK "phone_book"

int main(char argc, char **argv)
{

	Item *head;
	Item *new_item;

	char del_value[PHONE_NUM_LEN_MAX] = {0};
	char find_value[PHONE_NUM_LEN_MAX] = {0};
	
	if (2 < argc) {
		printf("Error: too many argcs.\n\n");
		help_info();
		return;
	}
	if (1 == argc) {
		help_info();
		return;
	}
	
	int result = 0;
	if (0 == memcmp(argv[1],"add",3))
		result = 1;
	else if (0 == memcmp(argv[1],"del",4))
		result = 2;
	else if (0 == memcmp(argv[1],"find",4))
		result = 3;
	else if (0 == memcmp(argv[1],"show",4))
		result = 4;
	
	switch (result) {
	case 0:break;
	case 1:
		new_item = get_input();
		head = read_to_mem(PHONE_BOOK);
		head = add_to_list(head, new_item);
		printf("new_item->name = %s\n", new_item->name);
		printf("head->name = %s\n",head->name);
		write_to_file(head, PHONE_BOOK);
		free_all(head);
		break;
	case 2:
		printf("Input the name or phonenum you want to delete:\n");
		scanf("%s",&del_value);
		head = read_to_mem(PHONE_BOOK);
		head = del_form_list(head, del_value);
		write_to_file(head, PHONE_BOOK);		
		free_all(head);
		break;
	
	case 3:
		printf("You want find:\n");
		scanf("%s",&find_value);
		head = read_to_mem(PHONE_BOOK);
		find_info(head, find_value);	
		break;
	case 4:
		head = read_to_mem(PHONE_BOOK);
		show_info(head);
		free_all(head);
		break;
	default:
		break;
	}
		

	return 0;
}



