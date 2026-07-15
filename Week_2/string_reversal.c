#include <stdio.h>
#include <string.h>

void reverse_string(char *str) {
  if (str == NULL || *str == '\0') {
    return;
  }

  int left = 0;
  int right = strlen(str) - 1;

  while (left < right) {
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;

    left++;
    right--;
  }
}

int main() {
  char str[100];

  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin);

  int i = 0;
  while (str[i] != '\0') {
    if (str[i] == '\n') {
      str[i] = '\0';
      break;
    }
    i++;
  }

  reverse_string(str);

  printf("Reversed string: %s\n", str);

  return 0;
}
