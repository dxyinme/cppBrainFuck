#include "util.h"
#include "types.h"
#include <cstdio>
#include <cstring>
#include <iostream>

int ReadInput(const char * filename, char * input) {
  auto f = fopen(filename, "r");
  memset(input, 0, sizeof(char) * MACHINE_LEGTH);
  char buf[BUF_LENGTH];
  int len = 0;
  while (fgets(buf, BUF_LENGTH, f)) {
    int buf_len = strlen(buf);
    for (int i = 0; i < buf_len; i++) {
      if (GetOp(buf[i]) != Operator::USELESS) {
        input[len++] = buf[i];
      }
    }
  }
  fclose(f);
  input[len] = '\0';
  return len;
}