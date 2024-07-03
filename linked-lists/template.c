#include "template.h"

/*Function: Create_Node() creates a node for a Linked List;
 *Parameters: Integer value;
 *Returns: Pointer to node;
 *
 */
node_t * create_node(int value) {
  //function variables
  node_t * node = NULL;
  //making space for node
  node = (node_t *)malloc(sizeof(node_t));
  //if malloc failed
  if (node == NULL) {
    return NULL;
  }
  //set next pointer to NULL
  node -> next = NULL;
  //copy parameter value to nodde's allocated space
  node -> value = value;
  //return the node;
  return node;
}//create_node()

/*Function: add_node() adds a node to a Linked List;
 *Parameters: Pointer to Node to be added, Pointer to Head Node
 *Returns: Pointer to Head Node;
 *
 */
node_t * add_node(node_t * node, node_t * head) {
  //function variables
  node_t * iter = head;
  node_t * slow_ptr = NULL;
  //node is NULL
  if (node == NULL) {
    return NULL;
  }
  //go to the node to add
  while (iter != NULL) {
    slow_ptr = iter;
    iter = iter -> next;
  }
  //assumes node's next pointers are NULL
  if (slow_ptr == NULL) {
    head = node;
  }//head is null
  else {
    slow_ptr -> next = node;
  }//the last pointer points to the node
  return head;
}//add_node()

/*Function: delete_node() delete a node in a Linked List;
 *Parameters: Pointer to Node to be deleted, Pointer to Head Node;
 *Returns: Pointer to Head Node;
 *
 */
node_t * delete_node(node_t * node, node_t * head) {
  //function variables
  node_t * iter = head;
  node_t * slow_ptr = NULL;
  //check if head or node are NULL
  if ((head == NULL) || (node == NULL)) {
    return head;
  }
  //go to node to delete
  while (iter != NULL) {
    if ((iter == node) && (slow_ptr == NULL)) {
      // Moves the head pointer one over;
      // Frees the node (old head);
      head = head -> next;
      free(node);
      node = NULL;
      return head;
    }//end if the node is the head node
    else if (iter == node) {
      //if node is not head node
      slow_ptr -> next = iter -> next;
      iter -> next = NULL;
      free(iter);
      iter = NULL;
      return head;
    }//end if the node is not head node
    slow_ptr = iter;
    iter = iter -> next;
  }
  //node is not in list
  return (node_t *) NULL;
}//delete_node()
