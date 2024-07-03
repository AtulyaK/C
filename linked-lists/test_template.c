#include <stdio.h>
#include <assert.h>
#include "template.h"
//#defines
#define ARR_SIZE 10
int main(int argc, char ** argv) {
  //function variables
  node_t * node_arr[ARR_SIZE];
  node_t * head = NULL;
  node_t * test = NULL;
  //make nodes
  for (int i = 0; i < ARR_SIZE; i++) {
    node_arr[i] = create_node(i);
    if (node_arr[i] == NULL) {
      return 0;
    }
  }
  //test add and delete
  for(int i = 0; i < ARR_SIZE; i++) {
    if (i == 0) {
      head = add_node(node_arr[0], head);
      fprintf(stdout, "Add_Node test:");
      fprintf(stdout, "Head: %p Node: %p\n", head, node_arr[0]);
      if (head == NULL) {
        fprintf(stdout, "MISTAKE: add_node tested and a valid node and NULL head entered. Expected output is NOT NULL\n");
      }//not what is wanted
      assert(head);
      head = delete_node(node_arr[0], head);
      fprintf(stdout, "Delete_Node test:");
      fprintf(stdout, "head: %p node: %p\n",head,node_arr[0]);
      if (head == NULL) {
        fprintf(stdout, "SUCCESS: delete_node tested and a valid node and valid head entered. Expected output is NULL after");
        fprintf(stdout," testing if the information is in fact not in the list anymore.\n");
      }//what is wanted
      assert(!head);
    }//if i = 0
    else {
      head = add_node(node_arr[i], head);
      fprintf(stdout, "Test if adding new nodes work: %p == %p\n", node_arr[i], head);
      if (head == NULL) {
        fprintf(stdout, "MISTAKE: add_node tested and a valid node and NULL head entered. Expected output is NOT NULL\n");
      }//not what is wanted
      assert(head);
    }//end else adding the nodes
  }
  head = delete_node(node_arr[9], head);
  test = delete_node(node_arr[9], head);
  assert(!test);
  fprintf(stdout, "SUCCESS: delete_node tested and a valid node and valid head entered. Expected output is NULL after");
  fprintf(stdout," testing if the information is in fact not in the list anymore.\n");
  head = delete_node(node_arr[4],head);
  test = delete_node(node_arr[4],head);
  assert(!test);
  fprintf(stdout, "SUCCESS: delete_node tested and a valid node and valid head entered. Expected output is NULL after");
  fprintf(stdout," testing if the information is in fact not in the list anymore.\n");
  head = delete_node(node_arr[1],head);
  fprintf(stdout, "Test if it works in pushing the head out if there is stuff after: %p == %p\n", node_arr[2], head);
  test = delete_node(node_arr[1],head);
  assert(!test);
  fprintf(stdout, "SUCCESS: delete_node tested and a valid node and valid head entered. Expected output is NULL after");
  fprintf(stdout," testing if the information is in fact not in the list anymore.\n");
}//main()
