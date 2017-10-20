#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "list.h"

//inserts node at front
//returns pointed to front
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

//inserts in order
//returns pointer to front of list
struct node * insert_order(struct node * old_front, char* art, char * nam) {
  struct node * ret = old_front;
  struct node * new_node;//pointer to new node
  new_node=(struct node *)malloc(sizeof(struct node));//mallocs memory
  strcpy(new_node->artist, art);
  strcpy(new_node->name, nam);
  
  //if song needs to be inserted at beginning
  if (!old_front || ((!strcmp(art,old_front->artist) &&
		      strcmp(nam,old_front->name)<0)//if curr artist and to be inserted artist are same and song comes first
		     ||
		     (strcmp(art,old_front->artist)<0)) ){
    new_node->next=old_front;
    return new_node;
  }

  while (old_front) {//if old_front is null it breaks loop

    //if next artist is the same and song belongs at beginning of artist
    if (old_front->next &&
	strcmp(art,old_front->artist) && //current artist doesnt match new artist
	!strcmp(art,old_front->next->artist) && //next artist matches new artist
	(strcmp(nam,old_front->next->name)<0)) //song goes before
      {
	new_node->next=old_front->next;
	old_front->next=new_node;
	return ret;
      }

    if (! strcmp(art, old_front->artist)) {//if artists equal
      if (strcmp(nam, old_front->name) > 0) {//if song should be inserted after current song
	new_node->next = old_front->next;
	old_front->next = new_node;
	//printf("insert_order successful if 1\n");
	return ret;
      }
      
    }
    //if inserting a new artist that needs to be inserted between artists
    //boolean is saying if (artist of song is later alphabetically than current artist AND (end of list OR next artist is later in alphabet)
    else if ((strcmp(art, old_front->artist) > 0) && ( !old_front->next || strcmp(art,old_front->next->artist)<0)) {//if new artist to be inserted is later in alphabet than current
      new_node->next = old_front->next;
      old_front->next=new_node;
      return ret;

    }
    old_front=old_front->next;
  }
  //insert at end
  old_front=new_node;
  old_front->next=0;
  return ret;

}

//return pointer to song
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

//free node
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

//return pointer to first song of artist
struct node * src_artist (char * art, struct node* list) {
  while (list) {
    if (! strcmp(list->artist,art))
      return list;
    list=list->next;
  }
  return list;
}
//return size
int list_size (struct node* list) {
  int i = 0;
  while (list) {
    i++;
    list = list -> next;
  }
  return i;
}
//random song
struct node * rand_song(struct node * list) {
  int i = list_size(list);
  while (list->next) {
    if (!(rand()%i))//modulo <length of list> gives probability 1/N of length of list, probability 1/N for each element
      return list;
    list=list->next;
  }
  return list;
}

void print_list(struct node * list) {

  //printf("FRONT | ");
  while (list) {
    printf("%s: %s | ",list->artist,list->name);
    list=list->next;
  }

  //printf("END\n");
  printf("\n");
}

void print_node(struct node * n) {
  printf("%s: %s\n",n->artist, n->name);
}

struct node * free_list(struct node * list) {
  while (list) {
    struct node * temp=list;
    list=list->next;
    printf("Freeing ");
    print_node(temp);
    free(temp);
    //print_list(list);
  }
  return list;
}


