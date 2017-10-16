#include <stdlib.h>
#include <stdio.h>

typedef struct node{ 
  char name[256];
  char artist[256];
  struct node *next;
};

struct node * insert_front(struct node * old_front, char* art, char * nam) {
  struct node * new_front;
  //printf("made new_front\n");
  new_front=(struct node *)malloc(sizeof(struct node));
  //printf("malloc successful\n");
  new_front->artist= art;
  new_front->name= nam;
  new_front->next=old_front;
  //printf("insert_front successful\n");
  return new_front;

}

struct node * insert_order(struct node * old_front, char* art, char * nam) {
  struct node * new_node;
  //printf("made new_front\n");
  new_node=(struct node *)malloc(sizeof(struct node));
  //printf("malloc successful\n");
  new_node->artist= art;
  new_node->name= nam;
  while (1) {
    if (! strcmp(art, old_front->artist)) {
      if (strcmp(nam, old_front->name) > 0) {
	new_node->next = old_front->next;
	old_front->next = new_node;
      }
      return new_node;
    }
    if (strcmp(art, old_front->artist) > 0) {
      //do the same as ^^^^
    }
  }
  //new_node->next=old_front;
  //printf("insert_front successful\n");
  return new_front;

}
void print_list(struct node * list) {

  printf("FRONT-->");
  while (list) {
    printf("%d-->",list->i);
    list=list->next;

  }

  printf("END\n");
}

struct node * free_list(struct node * list) {
  while (list) {
    struct node * temp=list;
    list=list->next;
    free(temp);
    //print_list(list);
  }
  return list;

}

int main() {


  struct node * test=0;
  printf("Printing empty list:\n");
  print_list(test);
  printf("\nPrinting one element list:\n");
  test=insert_front(test, 3);
  print_list(test);
  test=insert_front(test,7);
  test=insert_front(test,19);
  printf("\nPrinting three element list:\n");
  print_list(test);
  printf("\nPrinting freed list\n");
  test=free_list(test);
  print_list(test);
  return 0;
}
