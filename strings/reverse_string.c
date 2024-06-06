//Includes + function prototypes
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <assert.h>
char * reverse_string(char *);
/**
 *
 *
 */
int main(int argc, char* argv[]) {
  char test_alpha [26] = "zyxwvutsrqponmlkjihgfedcba";
  char *string = malloc(sizeof(int)*26);
  assert(string);
  char temp[26] = "abcdefghijklmnopqrstuvwxyz";
  strncpy(string, temp, 26);
  string = reverse_string(string);
  for (int i = 0; i <= 26; i++) {
    fprintf(stdout,"%c",string[i]);
    if (string[i] != test_alpha[i]) {
      fprintf(stdout,"failed reverse on:%c",string[i]);
    }
  }
  fprintf(stdout,"\n");
  free(string);
  string = NULL;
}//end main()

char * reverse_string(char *string) {
  assert(string);
  char temp[strlen(string)];
  strncpy(temp, string, strlen(string));
  char * letter = &temp[25];
  for (int i = 0; i < 26; i++) {
    string[i] = *letter;
    letter--;
  }
  return string;
}//reverse_string()
