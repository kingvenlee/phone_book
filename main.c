#include <stdio.h>
#include "manage.h"

int main(char argc, char **argv)
{

	if (2 < argc) {
		printf("Error: too many argcs.\n");
		return;
	}
	if (1 == argc) {
		printf("Error: too flew argcs.\n");
		return;
	}
	int i = 0;
	if (!memcmp(argv[1],"add"))
		i = 1;
	else if (!memcmp(argv[1],"del"))
		i = 2;
	else if (!memcmp(argv[1],"find"))
		i = 3;
	else if (!memcmp(argv[1],"show"))
		i = 4;
	
	switch (i) {
	case 1:
		//printf("start get_info().\n");
		//get_info();
		add_to_list();
		//add_list();
		write_to_file();
		finish();
		break;
	case 2:
		get_info();
		read_to_memery();
		find_info();
		del_info();
		write_to_file();
		finish();
		break;
	case 3:
		get_info();
		read_to_memery();
		find_info();
		show_info();
		finish();
		break;
	case 4:
		get_info();
		read_to_memery();
		show_info();
		finish();
		break;
	default:
		break;
	}
		

	return 0;
}



