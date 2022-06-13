#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LEN 100

int main(void) {
  FILE *f, *g;
  char buf[LEN];
  char mesaj[LEN];
  int sleep_sec;

  printf("Introdu numele: \n");
  fgets(mesaj, sizeof(mesaj), stdin);
  mesaj[strcspn(mesaj, "\n")] = '\0';

  f = fopen("/mesaj.txt", "w+");
  fprintf(f, mesaj);
  fclose(f);

  g = fopen("/mesaj.txt", "r");
  fgets(buf, sizeof(buf), g);
  fclose(g);
  printf("Numele este: %s. Cat timp se suspenda executia?\n", buf);
  scanf("%d", &sleep_sec);

  printf("Suspenda %d secunde...\n", sleep_sec);
  sleep(sleep_sec);
  printf("Inchei executia.\n");

  return 0;
}
