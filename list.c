#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct node{ 
  char name[256];
  char artist[256];
  struct node *next;
};

struct node * insert_front(struct node * old_front, char* art, char * nam) {
  struct node * new_front;
  //printf("made new_front\n");
  new_front=(struct node *)malloc(sizeof(struct node));
  //printf("malloc successful\n");
  strcpy(new_front->artist, art);
  strcpy(new_front->name, nam);
  new_front->next=old_front;
  //printf("insert_front successful\n");
  return new_front;

}

struct node * insert_order(struct node * old_front, char* art, char * nam) {
  struct node * new_node;//pointer to new node
  //  printf("made new_front\n");
  new_node=(struct node *)malloc(sizeof(struct node));//mallocs memory
  //  printf("malloc successful\n");
  strcpy(new_node->artist, art);
  strcpy(new_node->name, nam);
  // printf("strcpy successful\n");
  
  while (old_front) {//if old_front is null it breaks loop
    // printf("while loop started\n");
    if (! strcmp(art, old_front->artist)) {//if artists equal
      
      if (strcmp(nam, old_front->name) > 0) {//if song should be inserted after current song
	new_node->next = old_front->next;
	old_front->next = new_node;
	//	printf("insert_order successful if 1\n");
	return new_node;
      }
      else if (strcmp(art, old_front->artist)<0) {//song is at end of artist alphabetically
	new_node->next = old_front->next;
	old_front->next = new_node;
	//	printf("insert_order successful if 2\n");
	return new_node;
      }
    }
    //boolean is saying if (artist of song is later alphabetically than current artist AND (end of list OR next artist is later in alphabet)
    else if ((strcmp(art, old_front->artist) > 0) && ( !old_front->next || strcmp(art,old_front->next->artist)<0)) {//if new artist to be inserted is later in alphabet than current
      new_node->next = old_front->next;
      old_front->next=new_node;
      //   printf("insert_order successful if 3\n");
      return new_node;
      //do the same as ^^^^
    }
    old_front=old_front->next;
    //  printf("loop gone through once\n");
  }
  //printf("loop ended\n");
  //means it is null
  old_front=new_node;
  old_front->next=0;
  //  printf("insert_order successful end\n");
  return new_node;
  //new_node->next=old_front;

}

struct node * src_song (char * art, char  * nam, struct node* list) {
  while (list) {
    if (! strcmp (list -> artist, art) && ! strcmp (list -> name, nam)) {
      //printf("src song worked\n");
      return list;
    }
    list = list-> next;
  }
  //printf("fault");
  return list;
}

void remove_song (char* art, char* nam, struct node* list){
  while (list->next) {
    if (! strcmp(list->next->artist,art) && ! strcmp(list->next->name,nam)){
      struct node * temp = list ->next;
      list->next=temp->next;
      free(temp);
      return;
    }
    list=list->next;
  }
    
  
}

struct node * src_artist (char * art, struct node* list) {
  while (list) {
    if (! strcmp(list->artist,art))
      return list;
    list=list->next;
  }
  return list;
}
//MAKE THIS GOOD LATER 
int list_size (struct node* list) {
  int i = 0;
  while (list) {
    i++;
    list = list -> next;
  }
  return i;
}

struct node * rand_song(struct node * list) {
  int i = list_size(list);
  while (list->next) {
    if (!(rand()%i))
      return list;
    list=list->next;
  }
  return list;
}

void print_list(struct node * list) {

  printf("FRONT | ");
  while (list) {
    printf("%s: %s | ",list->artist,list->name);
    list=list->next;
  }

  printf("END\n");
}

void print_node(struct node * n) {
  printf("%s: %s\n",n->artist, n->name);
}

/*struct node * free_list(struct node * list) {
  while (list) {
  struct node * temp=list;
  list=list->next;
  free(temp);
  //print_list(list);
  }
  return list;

  }*/

int main() {
  srand(time(NULL));

  struct node * test=0;
  printf("Printing empty list:\n");
  print_list(test);
  printf("\nPrinting one element list:\n");
  test=insert_order(test, "AC\\DC","Dirty Deeds Done Dirt Cheap");
  print_list(test);
  insert_order(test, "AC\\DC","Problem Child");
  insert_order(test, "Arcade Fire","Neighborhood #1 (Tunnels)");
  insert_order(test, "Arcade Fire","Neighborhood #2 (Laika)");
  insert_order(test,"Annie Lennox","No More I Love You's");
  insert_order(test, "Adele","Rolling In the Deep");
  insert_order(test, "Annie Lennox", "Take Me To The River");

  printf("\nPrinting many element list:\n");
  print_list(test);
  printf("\n");

  printf("Searching for AC\\DC Problem Child\n");
  struct node * child=src_song("AC\\DC","Problem Child",test);
  //printf("child made\n");
  printf("Song is: %s | Artist is %s\n",child->name,child->artist);
  printf("Searching for Arcade Fire\n");
  child=src_artist("Arcade Fire",test);
  printf("Song is: %s | Artist is %s\n",child->name,child->artist);
  printf("Size of list is %d\n\n", list_size(test));

  printf("Random songs:\n");
  print_node(rand_song(test));
  print_node(rand_song(test));
  print_node(rand_song(test));

  printf("Removing Problem Child and Rolling in the Deep\n");
  remove_song("AC\\DC","Problem Child",test);
  remove_song("Adele","Rolling In The Deep",test);
  print_list(test);

  
  return 0;
}
