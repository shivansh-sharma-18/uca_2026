#include <stdio.h>

int my_strlen(const char *str) {
  int length = 0;

  while (str[length] != '\0') {
    length++;
  }

  return length;
}

int main() {
  char str[100];

  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin);

  int len = my_strlen(str);
  if (len > 0 && str[len - 1] == '\n') {
    str[len - 1] = '\0';
    len--;
  }

  printf("Length of the string: %d\n", len);

  return 0;
}
