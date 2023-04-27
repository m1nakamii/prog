#include "task1.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argv, char **argc) {
  if (argc[1]) {
    FILE *test = fopen("test", "wb");
    uint32_t code_point;
    uint8_t code_unit[4];
    sscanf(argc[1], "%x", &code_point);
    int lenght = encode_varint(code_point, code_unit);
    fwrite(code_unit, sizeof(uint8_t), lenght, test);
    fclose(test);
  }
  const char *compress = "compressed.dat", *uncompress = "uncompressed.dat";

  write_rand(uncompress, compress, MaxNumbers);
  uint32_t *uncom_buff = read_uncompress(uncompress);
  uint32_t *com_buff = read_compress(compress);

  for (int i = 0; i < MaxNumbers; i++)
    if (uncom_buff[i] != com_buff[i]) {
      fprintf(stderr, "Not identity");
      return 1;
    }
  fprintf(stdout, "Identity\n");

  free(uncom_buff);
  free(com_buff);
  return 0;
}