// SPDX-License-Identifier: BSD-3-Clause

#include <internal/syscall.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

int nanosleep(const struct timespec *t1, struct timespec *t2)
{
    int ret =  syscall(__NR_nanosleep, &t1, &t2);

	if (ret < 0) {
		errno = -ret;
		return -1;
	}

	return ret;
}

int sleep(unsigned int s)
{
	struct timespec aux_1;
    struct timespec aux_2;
    aux_1.tm_sec = s;
    aux_1.tm_nsec = 0;
    while (nanosleep(&aux_1, &aux_2) != 0 && errno != 1) {
        aux_1.tm_sec = aux_2.tm_sec;
        aux_1.tm_nsec = aux_2.tm_nsec;
    }
    return 0;
}
