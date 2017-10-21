#include <stdio.h>
#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct node * table[26];

//initializes all table slots to NULL
void initialize_table() {
  int i=0;
  for (;i<26;i++)
    table[i]=NULL;
}

//adds song, sets table[tab]=insert_order b/c insert_order returns pointer to start
void add_song (char * artist, char * song) {
  int tab = (int) artist[0] - 97;
  //printf("int successful: %d\n",tab);
  table[tab]=insert_order(table[tab],artist,song);
  //printf("insert_order successful\n");
  return; 
}

//search for song
struct node * src (char  * artist, char * song) {
  int tab = (int) artist[0] - 97;
  return src_song (artist, song, table[tab]);
}

//search for artist
struct node * src_art (char * artist) {
  int tab = (int) artist[0] - 97;
  return src_artist (artist, table[tab]);
}

//print all songs for artists starting with <let>
void print_letter (char let) {
  int tab = (int) let - 97;
  printf("%c songs\n",let);
  print_list(table[tab]);

}

//print all songs under artist a
void print_artist(char * a) {
  struct node * temp=src_art(a);
  printf("%s: ",a);
  while (a && !strcmp(a,temp->artist)) {
    printf("%s | ",temp->name);
    temp=temp->next;
  }
  printf("\n");
  
}

void print_table() {
  int i=0;
  for (;i<26;i++){
    if (table[i]) {
      printf("%c:\n",(char)(i+97));
      //printf("stuff\n");
      print_list(table[i]);
    }
  }
}



//return 5 songs
void shuffle() {
  int total=5;
  while (total>0) {
    int i=rand()%26;//modulo 26 will return one of the indeces of the table. 
    if (table[i]) {//if that slot has songs you get a random one
      print_node(rand_song(table[i]));
      total--;
    }
    else//if that slot has no songs you redo the rand()%26
      continue;

  }
}

void delete_node(char * name, char * artist) {
  int tab = (int) artist[0] - 97;
  remove_song(artist, name, table[tab]);
}

void delete_lib() {
  int i = 0;
  for (; i < 26; i++) {
    free_list(table[i]);
    table[i] = 0;
  }
}
