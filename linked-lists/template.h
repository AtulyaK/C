#include <stdlib.h>
//struct
typedef struct node {
  struct node * next;
  int value;
}node_t;

//function prototypes
node_t * create_node(int value);
node_t * add_node(node_t * node, node_t * head);
node_t * delete_node(node_t * node, node_t * head);
