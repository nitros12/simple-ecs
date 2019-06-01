#ifndef __COMMON_MACROS_H_
#define __COMMON_MACROS_H_

#define RUNTIME_ERROR(F, ...)                                                  \
  do {                                                                         \
    fprintf(stderr, "Runtime Error (%s:%d): ", __func__, __LINE__);            \
    fprintf(stderr, F "\n", ##__VA_ARGS__);                                    \
    exit(1);                                                                   \
  } while (0)

#ifndef NDEBUG
#define DEBUG_LOG(F, ...)                                                      \
  do {                                                                         \
    fprintf(stderr, "DEBUG (%s:%d): ", __func__, __LINE__);                    \
    fprintf(stderr, (F "\n"), ##__VA_ARGS__);                                  \
  } while (0)
#else
#define DEBUG_LOG(...)                                                         \
  do {                                                                         \
  } while (0)
#endif // NDEBUG

#define ALLOC_SPRINTF(S, ...)                                                  \
  do {                                                                         \
    size_t needed = snprintf(NULL, 0, __VA_ARGS__) + 1;                        \
    char *buf = malloc(needed);                                                \
    sprintf(buf, __VA_ARGS__);                                                 \
    (S) = buf;                                                                 \
  } while (0)

#ifndef NDEBUG
#define DEBUG_FPRINTF(...) fprintf(__VA_ARGS__)
#else
#define DEBUG_FPRINTF(...) (void)0
#endif // NDEBUG

#ifndef NDEBUG
#define DEBUG_ONLY(expr) (expr)
#else
#define DEBUG_ONLY(expr) (0)
#endif // NDEBUG

#define SWAP(A, B)                                                             \
  do {                                                                         \
    typeof(A) temp = (A);                                                      \
    (A) = (B);                                                                 \
    (B) = temp;                                                                \
  } while (0)

#define ARRAY_LEN(A) (sizeof(A) / sizeof(*A))

#endif // __COMMON_MACROS_H_
