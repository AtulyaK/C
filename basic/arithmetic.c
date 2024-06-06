//Includes for C libraries
#include <stdio.h>
#include <malloc.h>
//Function definitions
int add(int ,int);
int add_ptr(int *, int *);
/**Main function 
 *
 *
 */

int main(int argc, char* argv[]) {
  int a = 1;
  int b = 2;
  int c = 3;
  int d = 4;
  int *ptr_1 = 0;
  int *ptr_2 = 0;
  //unit tests for basic pointer functionalities
  int result = add(a,b);
  if (result != (a+b)) {
    fprintf(stdout, "add function with no pointers failed\n");
  }
  ptr_1 = malloc(sizeof(int));
  ptr_2 = malloc(sizeof(int));
  ptr_1 = &c;
  ptr_2 = &d;
  result = add_ptr(ptr_1, ptr_2);
  if (result != (c+d)) {
    fprintf(stdout, "add function with no pointers failed\n");
  }
  fprintf(stdout, "Successful run\n");
  free(ptr_1);
  ptr_1 = NULL;
  free(ptr_2);
  ptr_2 = NULL;
  return 1;
}//main()

/** Add function: adds two numbers given the address of two numbers.
 *
 *
 */

int add(int a, int b) {
  return a+b;
}//add()

int add_ptr(int *one, int *two) {
  return *one + *two;
}//add_ptr()

