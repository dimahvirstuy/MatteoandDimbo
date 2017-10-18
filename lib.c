#include <stdio.h>
#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct node * table[26];

void add_song (char * artist, char * song) {
  int tab = (int) artist - 97;
  insert_order(table[tab],artist,song);
  return; 
}

struct node * src (char  * song, char * artist) {
  int tab = (int) artist - 97;
  return src_song (artist, song, table[tab]);
}

struct node * src_art (char * artist) {
  int tab = (int) artist - 97;
  return src_artist (artist, table[tab]);
}

void print_letter (char let) {
  int tab = (int) artist - 97;
  print_list(table[tab]);

}

int main () {
  
}
