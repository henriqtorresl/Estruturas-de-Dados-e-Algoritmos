#include <stdio.h>
#include <stdbool.h>

bool exists[(int)1e6 + 1];

int main(void) {
  int n;
  scanf("%d", &n);

  int distinct_count = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);

    if (!exists[x]) {
      exists[x] = true;
      distinct_count++;
    }
  }

  printf("%d\n", distinct_count);
  return 0;
}