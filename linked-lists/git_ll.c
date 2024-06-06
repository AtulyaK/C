#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include "git_ll.h"
//function prototypes
commit_t * create_commit(char *, char *, char *, commit_t *);
commit_t * delete_commit(commit_t *, commit_t *);
int main (int argc, char* argv[]) {
  //variable declaration and definition + malloc of the commit variables
  commit_t * commit_0 = create_commit("Robber", "I will break your stuff", "6/3/24", (commit_t *)NULL);
  commit_t * commit_1 = create_commit("Bob", "first commit", "6/4/24", (commit_t *)NULL);
  create_commit("Jane","I am pushing something","6/4/24", commit_1);
  create_commit("Louis", "Hi I'm Louis! :)", "6/5/24", commit_1);
  //test if create_commit method worked to make all the commits
  commit_t * head = commit_1;
  while (head != NULL) {
    fprintf(stdout, "User:%s, Message:%s, Date:%s\n",head -> user, head -> message, head -> date);
  }
  // test delete_commit method works for bad input
  commit_t * commit_2 = delete_commit(commit_1, commit_0);
  if (commit_2 == NULL) {
    fprintf(stdout, "delete commit works when the commit to be deleted is not in the linked list\n");
  }
  else {
    fprintf(stdout, "delete commit DOES NOT works when the commit to be deleted is not in the linked list\n");
  }
  // test delete commit method works for good input
  commit_t * next_ptr = (commit_1 -> next) -> next;
  commit_2 = delete_commit(commit_1, commit_1 -> next);
  if (commit_2 == next_ptr) {
    fprintf(stdout, "delete commit works when the commit to be deleted is in the linked list\n");
  }
  else {
    fprintf(stdout, "delete commit DOES NOT work when the commit to be deleted is in the linked list\n");
  }
  return 0;
}//main()

commit_t * create_commit(char * user, char* message, char * date, commit_t * head) {
  //variable declaration/definition
  commit_t * commit = NULL;
  commit_t * iterator = head;
  // assertions to check if the data inputter are valid
  assert(user);
  assert(message);
  assert(date);
  //malloc space for the information
  commit = (commit_t *)malloc(sizeof(commit_t));
  assert(commit);
  commit -> user = strcpy(malloc(sizeof(char) * (strlen(user) + 1)),user);
  assert(commit -> user);
  commit -> message = strcpy(malloc(sizeof(char) * (strlen(message) + 1)), message);
  assert(commit -> message);
  commit -> date = strcpy(malloc(sizeof(char) * (strlen(date) + 1)), date);
  assert(commit -> date);
  commit -> next = NULL;
  //adding commit to Linked List
  if (head == NULL) {
    head = commit;
  }
  else {
    while (iterator -> next != NULL) {
      iterator = iterator -> next;
    }
    iterator -> next = commit;
  }
  return head;
}//create_commit()

commit_t * delete_commit(commit_t * head, commit_t * commit) {
  // variable declaration/definition
  commit_t * head_ptr = head;
  commit_t * prev_ptr = NULL;
  //inital assertions to check input is valid
  assert(head);
  assert(commit);
  //while loop to find the commit
  while ((head != commit) && (head != NULL)) {
    prev_ptr = head;
    head = head -> next;
  }// end while searching for commit
  //check if the commit is not null, meaning the commit was found
  if (head != NULL) {
    // if commit is found, fix pointers then free commit
    prev_ptr -> next = head -> next;
    head -> next = NULL;
    free(head);
    head = NULL;
    return head_ptr;
  }
  // commit was not found :(
  return NULL;
}
