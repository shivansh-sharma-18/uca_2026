#include <stdio.h>
#include <string.h>

void url_encode(char *str, int true_length) {
  int spaceCount = 0;

  for (int i = 0; i < true_length; i++) {
    if (str[i] == ' ')
      spaceCount++;
  }

  int newLength = true_length + (spaceCount * 2);
  str[newLength] = '\0';

  for (int i = true_length - 1, j = newLength - 1; i >= 0; i--) {
    if (str[i] == ' ') {
      str[j--] = '0';
      str[j--] = '2';
      str[j--] = '%';
    } else {
      str[j--] = str[i];
    }
  }
}

int main() {
  char str[100];
  int true_length;

  printf("Enter string: ");
  fgets(str, sizeof(str), stdin);
  str[strcspn(str, "\n")] = '\0';

  printf("Enter true length: ");
  scanf("%d", &true_length);

  url_encode(str, true_length);

  printf("Encoded string: %s\n", str);

  return 0;
}
