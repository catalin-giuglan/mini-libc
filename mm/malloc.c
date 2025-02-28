// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *ret = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (ret == NULL) {
		return MAP_FAILED;
	}
	return ret;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	void *ret = mmap(NULL, nmemb * size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	if (ret == NULL) {
		return MAP_FAILED;
	}
	memset(ret, 0, nmemb * size);
	return ret;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	void *ret = mremap(ptr, sizeof(*ptr), size, MAP_ANONYMOUS | MAP_PRIVATE);
	if (ret == NULL) {
		return MAP_FAILED;
	}
	return ret;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	void *ret = mremap(ptr, sizeof(*ptr), nmemb * size, MAP_ANONYMOUS | MAP_PRIVATE);
	if (ret == NULL) {
		return MAP_FAILED;
	}
	return ret;
}
