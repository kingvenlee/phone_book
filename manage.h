#ifndef PHONE_BOOK_MANAGE_DEFINE
#define PHONE_BOOK_MANAGE_DEFINE

#define NAME_LEN_MAX (32)
#define PHONE_NUM_LEN_MAX (64)


typedef struct item {
	char name[NAME_LEN_MAX];
	char phone_num[PHONE_NUM_LEN_MAX];
	struct item *next;
} Item;



void find_info(Item *head, char *find_value);
Item *del_form_list(Item *head, char *del_value);
Item *get_input(void);
Item *read_to_mem(char *file_name);
static char *my_strdup(char *src);
Item *add_to_list(Item *head, Item *new_item);
void show_info(Item *head);
void free_all(Item *head);
void write_to_file(Item *head, char *file);



#endif


