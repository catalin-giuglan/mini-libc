// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	int i = 0;
	while(source[i] != '\0') {
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	int i = 0;
	while(i < (int)len) {
		destination[i] = source[i];
		i++;
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	int i = strlen(destination);
	int j = 0;
	while(source[j] != '\0') {
		destination[i] = source[j];
		i++;
		j++;
	}
	destination[i] = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	int i = strlen(destination);
	int j = 0;
	while(source[j] != '\0' && j < (int)len) {
		destination[i] = source[j];
		i++;
		j++;
	}
	destination[i] = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	int i = 0;
	int ok;
	while (str1[i] != '\0' || str2[i] != '\0') {
		if (str1[i] > str2[i]) {
			return 1;
		} else if (str1[i] < str2[i]) {
			return -1;
		} else {
			ok = 0;
			i++;
		}
	}
	if (ok == 0) {
		return 0;
	}
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	int i = 0;
	int ok;
	while (str1[i] != '\0' && i < (int)len) {
		if (str1[i] > str2[i]) {
			return 1;
		} else if (str1[i] < str2[i]) {
			return -1;
		} else {
			ok = 0;
			i++;
		}
	}
	if (ok == 0) {
		return 0;
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	int i = 0;
	char* aux = (char *)str;
	while (aux[i] != '\0') {
		if (aux[i] == c) {
			return aux + i;
		}
		i++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	int i = 0;
	char* aux = NULL;
	while (str[i] != '\0') {
		if (str[i] == c) {
			aux = (char*)str + i;
		}
		i++;
	}
	return aux;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	int i = 0;
	char* aux = (char *)haystack;
	while (aux[i] != '\0') {
		if (strncmp(aux + i, needle, strlen(needle)) == 0) {
			return aux + i;
		}
		i++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	int i = 0;
	char* aux = NULL;
	while (haystack[i + strlen(needle)] != '\0') {
		if (strncmp(haystack + i, needle, strlen(needle)) == 0) {
			aux = (char *)haystack + i;
		}
		i++;
	}
	return aux;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char* auxsrc = (char *)source;
	char* auxdest = (char *)destination;
	for (int i = 0; i < (int)num; i++) {
		auxdest[i] = auxsrc[i];
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char* auxsrc = (char *)source;
	char* auxdest = (char *)destination;
	*auxdest = '\0';
	int i = 0;
	while (i < (int)num) {
		auxdest[i] = auxsrc[i];
		i++;
	}
	auxdest[i] = '\0';
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	char* auxsrc = (char *)ptr1;
	char* auxdest = (char *)ptr2;
	int i = 0;
	int ok;
	while ((auxsrc[i] != '\0' || auxdest[i] != '\0') && (i < (int)num)) {
		if (auxsrc[i] > auxdest[i]) {
			return *auxsrc - *auxdest;
		} else if (auxsrc[i] < auxdest[i]) {
			return *auxdest - *auxsrc;
		} else {
			ok = 0;
		}
		i++;
	}
	if (ok == 0) {
		return 0;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	unsigned char* aux = source;
    int i = 0;
	while (i < (int)num)
    {
        aux[i] = (unsigned char)value;
		i++;
    }
	return source;
}
