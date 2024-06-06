//#includes
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
//#include <string.h>
//function prototypes
char * strcpy(char *, char *);
int strlen_mine(char *string) {
  assert(string != NULL);
  int count = 0;
  while (*string != '\0') {
    count++;
    string++;
  }
  return count;
}// strlen_mine()

int main(int argc, char* argv[]) {
  // function variables
  char str1[10] = "abcdefghi";
  char str2[10] = "";
  char str3[2] = "";
  char *ptr_1 = NULL;
  char * ptr_2 = NULL;
  char * in = "Atulya is a sweet boy";
  char * out = malloc(strlen_mine(in) + 1);
  strcpy(out,in);
  fprintf(stdout, "output:%s\n", out);
  //Case 1: Null, NULL input
  if (strcpy(ptr_1, ptr_2) == NULL) {
    fprintf(stdout, "On input of Null, Null properly returned NULL");
  }
  else {
    fprintf(stdout,"Failed on input of NULL,NULL getting a NULL output");
  }
  //Case 2 and 3: NULL,___ or ____,NULL
  if ((strcpy(ptr_1, str1) == NULL) && (strcpy(str1 ,ptr_2) == NULL)) {
    fprintf(stdout,"On input of a Null pointer for either value it returns NULL");
  }
  else {
    fprintf(stdout, "Failed on input of Null,___ or ___,NULL");
  }
  //Case 4: empty string using array
  strcpy(str2,str3);
  if (str2[2] == '\0') {
    fprintf(stdout,"Succesful when using string array such that the destination has more space than the source");
  }
  else {
    fprintf(stdout,"Failed when using string array such that the destination has more space than the source");
  }
  strcpy(str3,str2);
  if ((str3[2] != '\0') && (str3[10] == '\0')) {
    fprintf(stdout, "Succesful when using a string array such that the destination has less space than the source leading to undefined behavior.");
  }
  else {
    fprintf(stdout, "Failed when using string array such that the destination has less space than the source leading to undefined behavior.");
  }
  //Case 5: empty string using pointer
  //Case 6: proper strings

}//end main()

char * strcpy(char * dest, char * src) {
  char * temp = dest;
  assert(dest);
  assert(src);
  while (*src != '\0') {
    *dest = *src;
    dest++;
    src++;
  }
  // also copy Null terminator
  *(dest++) = *(src++);
  return temp;
}//strcpy()


