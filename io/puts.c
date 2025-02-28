#include <stdlib.h>
#include <string.h>
#include <internal/io.h>

int puts(const char *str) {
    int ret = write(1, str, strlen(str));
    write(1, "\n", 1);
    return ret;
}
