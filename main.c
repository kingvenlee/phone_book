#include <stdio.h>
#include "manage.h"


#define PHONE_BOOK "phone_book"

int main(char argc, char **argv)
{

	Item *head = NULL;
	Item *new_item;
	
/*----------------------*/
	new_item = malloc(sizeof(Item));
	
	memcpy(new_item->name, "wang", NAME_LEN_MAX);
	memcpy(new_item->phone_num, "33323334", PHONE_NUM_LEN_MAX);
	
	new_item->next = NULL;
/*----------------------*/


	if (2 < argc) {
		printf("Error: too many argcs.\n");
		return;
	}
	if (1 == argc) {
		printf("Error: too flew argcs.\n");
		return;
	}
	
	int result = 0;
	if (!memcmp(argv[1],"add"))
		result = 1;
	else if (!memcmp(argv[1],"del"))
		result = 2;
	else if (!memcmp(argv[1],"find"))
		result = 3;
	else if (!memcmp(argv[1],"show"))
		result = 4;

	printf("result = %d\n",result);
	switch (result) {
	case 0:
		printf("start.\n");
		//new_item = get_input();
		//head = read_to_mem(PHONE_BOOK);
		read_to_mem(PHONE_BOOK);
		if (NULL == head) {
			printf("head is null!\n");
		}

		if (NULL == new_item) {
			printf("new_item is null!\n");
		}
		//add_to_list(head, new_item);
		write_to_file(head, "123");
		//final();
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



