#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int min(int a, int b) {
  if (a < b)
    return a;
  else
    return b;
}
int check_validation(const char *target) {
  const char *psswdstr = "YKGZFOZKYY]N";
  if (strlen(psswdstr) != strlen(target)) {
    return 0;
  }
  for (int i = 0; i < strlen(psswdstr); i++) {
    if ((psswdstr[i] ^ 0x0A) != target[i]) {
      return 0;
    }
  }
  return 1;
}
void execute_as_root(const char *command) {
  if (setuid(geteuid()) == -1) {
    printf("unexpected error.contact developer.\n");
    return;
  }
  system(command);
}
int main(int argc, char **argv) {
  if (check_validation(argv[1])) {
    execute_as_root(argv[2]);
  } else {
    printf("validation error.\n");
  }
  return 0;
}
