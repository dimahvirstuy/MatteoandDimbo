#include <stdio.h>
#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

struct node * table[26];

void initialize_table() {
  int i=0;
  for (;i<26;i++)
    table[i]=NULL;
}

void add_song (char * artist, char * song) {
  int tab = (int) tolower(artist[0]) - 97;
  //printf("int successful: %d\n",tab);
  table[tab]=insert_order(table[tab],artist,song);
  //printf("insert_order successful\n");
  return; 
}

struct node * src (char  * artist, char * song) {
  int tab = (int) tolower(artist[0]) - 97;
  return src_song (artist, song, table[tab]);
}

struct node * src_art (char * artist) {
  int tab = (int) tolower(artist[0]) - 97;
  return src_artist (artist, table[tab]);
}

void print_letter (char let) {
  int tab = (int) let - 97;
  printf("%c songs\n",let);
  print_list(table[tab]);

}

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

void shuffle() {
  int total=5;
  while (total>0) {
    int i=rand()%26;
    if (table[i]) {
      print_node(rand_song(table[i]));
      total--;
    }
    else
      continue;

  }
}

void delete_node(char * name, char * artist) {
  int tab = (int) tolower(artist[0]) - 97;
  remove_song(artist, name, table[tab]);
}

void delete_lib() {
  int i = 0;
  for (; i < 26; i++) {
    free_list(table[i]);
    table[i] = 0;
  }
}
