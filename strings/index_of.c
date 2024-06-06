#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>

//function prototypes
int index_of(char *, char*);
void print_out(int, char*, char*, int);
int main(int argc, char* argv[]) {
  // malloc + copying strings into allocated memory
  char *str_1 = strcpy((char *)malloc(sizeof(char) * (26 + 1) ),"abcdefghijklmnopqrstuvwxyz");
  assert(str_1);
  char *str_2 = strcpy((char *)malloc(sizeof(char) *(2 + 1)), "ab");
  assert(str_2);
  char * str_3 = strcpy((char *)malloc(sizeof(char) *(3 + 1)), "fgh");
  assert(str_3);
  char * str_4 = strcpy((char *)malloc(sizeof(char) *(3 + 1)),"xyz");
  assert(str_4);
  char * str_5 = strcpy((char *)malloc(sizeof(char) *(6 + 1)), "atulya");
  assert(str_5);
  //caling index_of and testing output
  print_out(0,str_1, str_2, index_of(str_1, str_2));
  print_out(5,str_1, str_3, index_of(str_1, str_3));
  print_out(23,str_1, str_4, index_of(str_1, str_4));
  print_out(-1,str_1, str_5, index_of(str_1, str_5));
}//end main()

int index_of(char * src, char *str) {
  int index = 0;
  int len = strlen(str);
  int check_len = 0;
  int check_following = 0;
  char * begining = str;
  assert(src);
  assert(str);
  fprintf(stdout, "src:%s\n",src);
  fprintf(stdout,"str:%s\n",str);
  while (*src != '\0') {
    fprintf(stdout, "src:%c, str:%c, index:%d, check_following:%d, len:%d, check_len:%d\n",*src,*str,index, check_following,len,check_len);
    if ((*src == *str) && (check_following == (index - 1))) {
      check_len++;
      str++;
      if (len == check_len) {
        return index - len + 1;
      }
      check_following = index;
    }
    else if ((*src == *str) && (check_following == 0)) {
      check_following = index;
      check_len++;
      str++;
    }
    else {
      check_following = 0;
      check_len = 0;
      str = begining;
    }
    src++;
    index++;
  }

  return -1;
}//index_of()

void print_out(int tested, char *src, char*str, int actual) {
  if (tested == actual) {
    fprintf(stdout, "Succes.\n String:%s\n Src:%s\nIndex of string in source:%d\n",src,str,actual);
  }
  else {
    fprintf(stdout,"Failed.\n String:%s\n Src:%s\nIndex of string in source:%d\n",src,str,actual);
  }
}
