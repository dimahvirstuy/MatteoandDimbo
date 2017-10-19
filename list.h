struct node{ 
  char name[256];
  char artist[256];
  struct node *next;
};

struct node * insert_front(struct node * old_front, char* art, char * nam) ;

struct node * insert_order(struct node * old_front, char* art, char * nam);

struct node * src_song (char * art, char  * nam, struct node* list);

void remove_song (char* art, char* nam, struct node* list);

struct node * src_artist (char * art, struct node* list);

void remove_song (char* art, char* nam, struct node* list);

struct node * rand_song(struct node * list);

int list_size(struct node *);

void print_list(struct node * list);

void print_node(struct node * list);

struct node * free_list(struct node * list);

