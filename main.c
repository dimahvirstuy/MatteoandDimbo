#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "list.h"
#include "lib.h"
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
  test=insert_front(test, "AC/DC","Dirty Deeds Done Dirt Cheap");
  print_list(test);
  printf("----------------------------------\n");
  printf("\nTesting insert_order:\n");
  insert_order(test, "AC/DC","Problem Child");
  insert_order(test, "Arcade Fire","Neighborhood #1 (Tunnels)");
  insert_order(test, "Arcade Fire","Neighborhood #2 (Laika)");
  insert_order(test,"Annie Lennox","No More I Love You's");
  insert_order(test, "Adele","Rolling In the Deep");
  insert_order(test,"Adele","Hello");
  insert_order(test, "Annie Lennox", "Take Me To The River");

  print_list(test);
  printf("----------------------------------\n");
  printf("Testing search for individual song\n");
  printf("Searching for AC/DC Problem Child\n");
  if (src_song("AC/DC","Problem Child",test)){
    printf("Song found. ");
  print_node(src_song("AC/DC","Problem Child",test));
  }
  else
    printf("Not found\n");
  printf("Searching for [Green Day] [Holiday]\n");
  if (src_song("Green Day","Holiday",test)) {
    printf("Song found. ");
    print_node(src_song("Green Day","Holiday",test));
  }
  else
    printf("Not found\n");
      
  printf("----------------------------------\n");
  printf("Testing search for artist\n");
  printf("Searching for [Arcade Fire]\n");
  print_list(src_artist("Arcade Fire",test));
  printf("Searching for [Annie Lennox]\n");
  print_list(src_artist("Annie Lennox",test));
  printf("----------------------------------\n");
  printf("Testing size (helper)\n");
  print_list(test);
  printf("Size of list is %d\n", list_size(test));
  printf("----------------------------------\n");

  printf("Random songs:\n");
  print_node(rand_song(test));
  print_node(rand_song(test));
  print_node(rand_song(test));
  print_node(rand_song(test));
  printf("----------------------------------\n");
  printf("Testing remove individual songs\n");
  printf("Removing [Problem Child] and [Rolling in the Deep]\n");
  remove_song("AC/DC","Problem Child",test);
  remove_song("Adele","Rolling In The Deep",test);
  print_list(test);
  printf("----------------------------------\n");
 
  printf("Testing free entire list\n");
  test=free_list(test);
  printf("Printing free list\n");
  print_list(test);
  printf("----------------------------------\n");

  initialize_table();
  
  printf("\nTESTING TABLE\n\n");
  printf("----------------------------------\n");
  printf("Testing add song\n");
  add_song("The Beatles","Here Comes the Sun");
  add_song("The Beatles","Yesterday");
  add_song("Robert Plant","House of Love");
  add_song("Robert Plant","Rainbow");
  add_song("Radiohead","Fake Plastic Trees");
  add_song("Radiohead","Backdrifts (Honeymoon Is Over)");
  add_song("Bon Iver","Skinny Love");
  add_song("Bon Iver","For Emma");
  add_song("Birdy","Beautiful Lies");
  add_song("Birdy","Words");
  add_song("Bob Dylan","Tombstone Blues");
  //print_list(table[1]);
  printf("\nall songs added!\n");
  print_table();
  printf("----------------------------------\n");
  printf("Testing print artist\n");
  printf("Printing all [Radiohead] songs\n");
  print_artist("Radiohead");
  printf("Printing all [Birdy] songs\n");
  print_artist("Birdy");
  printf("----------------------------------\n");
  printf("Testing print letter\n");
  print_letter('r');
  print_letter('b');
  printf("----------------------------------\n");
  printf("Shuffling\n");
  shuffle();
  printf("----------------------------------\n");
  printf("Testing delete single song\n");
  printf("Deleting [Radiohead] [Fake Plastic Trees]\n");
  delete_node("Fake Plastic Trees","Radiohead");
  printf("Deleting [Birdy] [Words]\n");
  delete_node("Words","Birdy");
  print_table();
  printf("----------------------------------\n");
  printf("Deleting library\n");
  delete_lib();
  print_table();
  printf("----------------------------------\n");
  return 0;
}
