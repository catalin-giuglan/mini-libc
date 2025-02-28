//SURSA https://www.geeksforgeeks.org/time-h-header-file-in-c-with-examples/
#ifndef _TIMESPEC_DEFINED

struct timespec {
    // seconds,  range 0 to 59
    unsigned int tm_sec;
    unsigned int tm_nsec;
};
int nanosleep(const struct timespec *t1, struct timespec *t2);
int sleep(unsigned int s);


#define _TIMESPEC_DEFINED
#endif

