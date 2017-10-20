#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "list.h"
#include <ctype.h>


int main () {

  srand(time(NULL));

  struct node * test=0;
  printf("----------------------------------\n");
  printf("TESTING LIST FUNCTIONS\n");
  printf("----------------------------------\n");
  printf("Printing empty list:\n");
  print_list(test);
  printf("----------------------------------\n");
  printf("\nTesting insert_front:\n");
  test=insert_front(test, "AC\\DC","Dirty Deeds Done Dirt Cheap");
  print_list(test);
  printf("----------------------------------\n");
  printf("\nTesting insert_order:\n");
  insert_order(test, "AC\\DC","Problem Child");
  insert_order(test, "Arcade Fire","Neighborhood #1 (Tunnels)");
  insert_order(test, "Arcade Fire","Neighborhood #2 (Laika)");
  insert_order(test,"Annie Lennox","No More I Love You's");
  insert_order(test, "Adele","Rolling In the Deep");
  insert_order(test,"Adele","Hello");
  insert_order(test, "Annie Lennox", "Take Me To The River");

  print_list(test);
  printf("----------------------------------\n");

  printf("Searching for AC\\DC Problem Child\n");
  print_node(src_song("AC\\DC","Problem Child",test));
  printf("----------------------------------\n");
  printf("Searching for Arcade Fire\n");
  print_node(src_artist("Arcade Fire",test));
  printf("----------------------------------\n");
  printf("Size of list is %d\n\n", list_size(test));
  printf("----------------------------------\n");

  printf("Random songs:\n");
  print_node(rand_song(test));
  print_node(rand_song(test));
  print_node(rand_song(test));
  printf("----------------------------------\n");

  printf("Removing Problem Child and Rolling in the Deep\n");
  remove_song("AC\\DC","Problem Child",test);
  remove_song("Adele","Rolling In The Deep",test);
  print_list(test);
  printf("----------------------------------\n");
 
  printf("Printing freed list\n");
  test=free_list(test);
  print_list(test);
  printf("----------------------------------\n");

  initialize_table();
  
  printf("\n\nTABLE\n\nTesting add song\n");
  add_song("The Beatles","Here Comes the Sun");
  add_song("The Beatles","Yesterday");
  add_song("Robert Plant","House of Love");
  add_song("Robert Plant","Rainbows");
  //print_list(table[17]);
  add_song("Radiohead","Fake Plastic Trees");
  //print_list(table[17]);
  add_song("Radiohead","Backdrifts (Honeymoon Is Over)");
  //print_list(table[17]);
  add_song("Bon Iver","Skinny Love");
  add_song("Bon Iver","For Emma");
  add_song("Birdy","Beautiful Lies");
  add_song("Birdy","Words");
  //print_list(table[1]);
  add_song("Bob Dylan","Tombstone Blues");
  //print_list(table[1]);
  printf("\nall songs added!\n");
  print_table();
  printf("----------------------------------\n");
  printf("Printing all Radiohead songs\n");
  print_artist("Radiohead");
  printf("----------------------------------\n");
  printf("Printing all [b] songs\n");
  print_letter('b');
  printf("----------------------------------\n");
  printf("Shuffling\n");
  shuffle();
  printf("----------------------------------\n");

  printf("Deleting library\n");
  delete_lib();
  print_table();
  return 0;
}
