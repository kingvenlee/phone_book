#include <stdio.h>
#include "manage.h"
#include <string.h>

#define PHONE_BOOK "phone_book"

int main(char argc, char **argv)
{

	Item *head;
	Item *new_item;

	if (2 < argc) {
		printf("Error: too many argcs.\n");
		return;
	}
	if (1 == argc) {
		printf("Error: too flew argcs.\n");
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
		//new_item = get_input();
		head = read_to_mem(PHONE_BOOK);
		//read_to_mem(PHONE_BOOK);
		if (NULL == head) {
			printf("head is null!\n");
		}

		if (NULL == new_item) {
			printf("new_item is null!\n");
		}
		
		
		//add_to_list(&head, &new_item);
		write_to_file(head, "123");
		//free_all(head);
		break;
	/*case 2:
		get_info();
		read_to_mem();
		find_info();
		del_info();
		write_to_file();
		finish();
		break;
	case 3:
		get_info();
		read_to_mem();
		find_info();
		show_info();
		finish();
		break;
	case 4:
		get_info();
		read_to_mem();
		show_info();
		finish();
		break;*/
	default:
		break;
	}
		

	return 0;
}



