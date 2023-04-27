#include <stdio.h>
#include <string.h>

#include "command.h"

int main(int argv, char **argc) {
  if (argv != 4) {
    printf("./coder encode <input file> <output file>\n"
           "./coder decode <input file> <output file>\n");
    return 0;
  }
  char *command = argc[1], *in_file = argc[2], *out_file = argc[3];

  if (strcmp(command, "encode") == 0) {
    encode_file(in_file, out_file);
  } else if (strcmp(command, "decode") == 0) {
    decode_file(in_file, out_file);
  } else if (strcmp(command, "test") == 0) {
    test_file(in_file, out_file);
  } else {
    printf("coder <encode> or <decode>\n");
    return 0;
  }

  return 0;
}