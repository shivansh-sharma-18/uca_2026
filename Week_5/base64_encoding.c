#include <stdio.h>
#include <string.h>

void base64Encode(char input[]) {
  char table[] =
      "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
  int len = strlen(input);

  for (int i = 0; i < len; i += 3) {
    int a = input[i];
    int b = (i + 1 < len) ? input[i + 1] : 0;
    int c = (i + 2 < len) ? input[i + 2] : 0;

    int x = a >> 2;
    int y = ((a & 3) << 4) | (b >> 4);
    int z = ((b & 15) << 2) | (c >> 6);
    int w = c & 63;

    printf("%c", table[x]);
    printf("%c", table[y]);

    if (i + 1 < len)
      printf("%c", table[z]);
    else
      printf("=");

    if (i + 2 < len)
      printf("%c", table[w]);
    else
      printf("=");
  }

  printf("\n");
}

int main() {
  char input[1000];

  fgets(input, sizeof(input), stdin);
  input[strcspn(input, "\n")] = '\0';

  base64Encode(input);

  return 0;
}
