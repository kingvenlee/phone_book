#ifndef PHONE_BOOK_MANAGE_DEFINE
#define PHONE_BOOK_MANAGE_DEFINE

#define NAME_LEN_MAX (32)
#define PHONE_NUM_LEN_MAX (64)


typedef struct item {
	char name[NAME_LEN_MAX];
	char phone_num[PHONE_NUM_LEN_MAX];
	struct item *next;
} Item;




//Item *line; 


//Item *get_info(void);
/*
get_info();
read_to_memery();
find_info();
add_list();
del_info();
show_info();
write_to_file();
finish();
*/


#endif


