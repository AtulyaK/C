#include <stdio.h>
#include <malloc.h>
#include <assert.h>
int strlen_mine(char *);
int main (int argc, char* argv[]) {
  
  return 1;
}//end main()

int strlen_mine(char *string) {
  assert(string != NULL);
  int count = 0;
  while (*string != '\0') {
    count++;
    string++;
  }
  return count;
}// strlen_mine()
