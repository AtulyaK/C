#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
//function prototypes
char * contains_char(char *, char);
void print_out(char *, char *, char, char *);
int main(int argc,char * argv[]) {
  //malloc strings for testing
  char * str_1 = strcpy(malloc(sizeof(char) * 27),"abcdefghijklmnopqrstuvwxyz");
  assert(str_1);
  //testing different positions in a char array
  char * ptr_test = contains_char(str_1,'a');
  print_out(ptr_test, str_1,'a',&str_1[0]);
  ptr_test = contains_char(str_1,'z');
  print_out(ptr_test, str_1, 'z',&str_1[25]);
  ptr_test = contains_char(str_1,'\0');
  print_out(ptr_test, str_1, 'k',&str_1[10]);
  ptr_test = contains_char(str_1, 'c');
  print_out(ptr_test, str_1, 'c',&str_1[2]);
  ptr_test = contains_char(str_1,'h');
  print_out(ptr_test, str_1, 'h',&str_1[7]);
  ptr_test = contains_char(str_1, 'H');
  print_out(ptr_test, str_1, 'H',&str_1[7]);
}//main()

char * contains_char(char * string, char c) {
  assert(string != NULL);
  while (*string != '\0') {
    if (*string == c) {
      return string;
    }
    string++;
  }
  return NULL;
}//contains()

void print_out(char* tested, char *src, char str, char* actual) {
  if (*tested == *actual) {
    fprintf(stdout, "Succes.\n String:%s\n Src:%c\nCharacter of string in source:%c\n",src,str,*actual);
  }
  else {
    fprintf(stdout,"Failed.\n String:%s\n Src:%c\nCharacter of string in source:%c\n",src,str,*actual);
  }
}
