typedef struct commit {
  char * user;
  char * message;
  char * date;
  struct commit * next;
}commit_t;
