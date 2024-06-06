#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>
void print_array(char *);
int main(int argc, char * argv[]) {
  char *temp = malloc(sizeof(char)*10);
  assert(temp != NULL);
  char *arr = "abcdefghi";
  strncpy(temp, arr,9);
  print_array(temp);
  free(temp);
  temp = NULL;
}//end main()

void print_array(char *letter) {
  assert(letter != NULL);
  int count = 0;
  fprintf(stdout, "length = %li\n",strlen(letter));
  int len = strlen(letter);
  while (count < len) {
    fprintf(stdout, "letter #%i:%c\n",count + 1, *letter);
    letter++;
    count++;
    fprintf(stdout,"count:%i\n",count);
  }
}//end print_array()

/** Mistakes I made:
 * 1. The biggest which took my some time to figure out was why it was not printing the full way through.
 *    I realized that the reason for that was because length of the pointer to the character to print was changing each time when I did pointer arithmetic.
 *    I did not account for that and it onyl printed 5 times.
 *2. I forgot to free the pointer after I malloced it.
 *3. I initially had reassigned the temp variable to have the first 9 letters of the alphabet instead of copying the values into the location.
 */
