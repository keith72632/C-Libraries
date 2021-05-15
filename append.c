#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_INIT {NULL, 0}

struct abuf {
    char *buf;
    int len;
};

void bufferAppend(struct abuf *ab, const char *s, int len) {
  char *new = realloc(ab->buf, ab->len + len);
  if (new == NULL) return;

  //copies string of len bytes to address of end of new
  memcpy(&new[ab->len], s, len);
  ab->buf = new;
  ab->len += len;
}

int main(int argc, char **argv)
{
    struct abuf ab = BUF_INIT;
    char msg[] = "hello";
    char msg2[] = "world";
    printf("%s\n", msg);

    bufferAppend(&ab, msg, 6);
    printf("%s\n", ab.buf);

    bufferAppend(&ab, msg2, 12);
    printf("%s\n", ab.buf);
    
    return 0;
}
