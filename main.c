#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "list.h"
#include "lib.h"



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
  test=insert_front(test, "ac/dc","dirty deeds done dirt cheap");
  print_list(test);
  printf("----------------------------------\n");
  printf("\nTesting insert_order and print_list:\n");
  insert_order(test, "ac/dc","problem child");
  insert_order(test, "arcade fire","neighborhood #1 (tunnels)");
  insert_order(test, "arcade fire","neighborhood #2 (laika)");
  insert_order(test,"annie lennox","no more i love you's");
  insert_order(test, "adele","rolling in the deep");
  insert_order(test,"adele","hello");
  insert_order(test, "annie lennox", "take me to the river");

  print_list(test);
  printf("----------------------------------\n");
  printf("\nTesting search for individual song\n");
  printf("searching for [%s] [%s]\n","ac/dc","problem child");
  if (src_song("ac/dc","problem child",test)){
    printf("song found. ");
  print_node(src_song("ac/dc","problem child",test));
  }
  else
    printf("not found\n");
  printf("searching for [%s] [%s]\n","green day","holiday");
  if (src_song("green day","holiday",test)) {
    printf("song found. ");
    print_node(src_song("green day","holiday",test));
  }
  else
    printf("not found\n");
      
  printf("----------------------------------\n");
  printf("\ntesting search for artist\n");
  printf("searching for [%s]\n","arcade fire");
  print_list(src_artist("arcade fire",test));
  printf("searching for [%s]\n","annie lennox");
  print_list(src_artist("annie lennox",test));
  printf("----------------------------------\n");
  printf("\ntesting size (helper)\n");
  print_list(test);
  printf("size of list is %d\n", list_size(test));
  printf("----------------------------------\n");

  printf("\nrandom songs:\n");
  print_node(rand_song(test));
  print_node(rand_song(test));
  print_node(rand_song(test));
  print_node(rand_song(test));
  printf("----------------------------------\n");
  printf("\ntesting remove individual songs\n");
  printf("removing [%s] and [%s]\n","problem child","rolling in the deep");
  remove_song("ac/dc","problem child",test);
  remove_song("adele","rolling in the deep",test);
  print_list(test);
  printf("----------------------------------\n");
 
  printf("\ntesting free entire list\n");
  test=free_list(test);
  printf("printing free list\n");
  print_list(test);
  printf("----------------------------------\n");

  initialize_table();
  
  printf("\nTESTING TABLE\n\n");
  printf("----------------------------------\n");
  printf("Testing add song and print_library\n");
  add_song("the beatles","here comes the sun");
  add_song("the beatles","yesterday");
  add_song("robert plant","house of love");
  add_song("robert plant","rainbow");
  add_song("radiohead","fake plastic trees");
  add_song("radiohead","backdrifts (honeymoon is over)");
  add_song("radiohead","creep");
  add_song("bon iver","skinny love");
  add_song("bon iver","for emma");
  add_song("birdy","beautiful lies");
  add_song("birdy","words");
  add_song("bob dylan","tombstone blues");
  printf("all songs added!\n");
  print_table();
  printf("----------------------------------\n");
  printf("\ntesting print artist\n");
  printf("printing all [%s] songs\n","radiohead");
  print_artist("radiohead");
  printf("printing all [%s] songs\n","birdy");
  print_artist("birdy");
  printf("----------------------------------\n");
  printf("\ntesting print letter\n");
  print_letter('r');
  print_letter('b');
  printf("----------------------------------\n");
  printf("\ntesting search song\n");
  printf("searching for [%s] [%s]\n","bon iver","skinny love");
  if (src("bon iver","skinny love")){
    printf("song found. ");
  print_node(src("bon iver","skinny love"));
  }
  else
    printf("not found\n");
  printf("searching for [%s] [%s]\n","bon iver","flume");
  if (src("bon iver","flume")){
    printf("song found. ");
    print_node(src("bon iver","flume"));
  }
  else
    printf("not found\n");
  printf("----------------------------------\n");
  printf("\ntesting search for artist\n");
  printf("searching for [%s]\n","bob dylan");
  if (src_art("bob dylan")){
    printf("artist found. ");
  print_list(src_art("bob dylan"));
  }
  else
    printf("not found\n");
  printf("searching for [%s]\n","led zeppelin");
  if (src_art("led zeppelin")){
    printf("song found. ");
    print_list(src_art("led zeppelin"));
  }
  else
    printf("not found\n");
  printf("----------------------------------\n");
  printf("\nshuffling\n");
  shuffle();
  printf("----------------------------------\n");
  printf("\ntesting delete single song\n");
  printf("deleting [%s] [%s]\n","radiohead","fake plastic trees");
  delete_node("fake plastic trees","radiohead");
  printf("deleting [%s] [%s]\n","birdy","words");
  delete_node("words","birdy");
  print_table();
  printf("----------------------------------\n");
  printf("\ndeleting library\n");
  delete_lib();
  print_table();
  printf("----------------------------------\n");
  return 0;
}
