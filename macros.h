#pragma once

#include <cstdlib>
#include <new>

#if __GNUC__ >= 3
#define likely(x) (__builtin_expect((x), 1))
#define unlikely(x) (__builtin_expect((x), 0))
#else
#define likely(x) (x)
#define unlikely(x) (x)
#endif

#define CACHELINE_SIZE 64

#define DEFINE_TYPE_TRAIT(name, func)                            \
  template <typename T>                                          \
  class name {                                                   \
   private:                                                      \
    template <typename Class>                                    \
    static char Test(decltype(&Class::func)*);                   \
    template <typename>                                          \
    static int Test(...);                                        \
                                                                 \
   public:                                                       \
    static constexpr bool value = sizeof(Test<T>(nullptr)) == 1; \
  };                                                             \
                                                                 \
  template <typename T>                                          \
  constexpr bool name<T>::value;

inline void cpu_relax() { asm volatile("rep; nop" ::: "memory"); }

inline void* CheckedMalloc(size_t size) {
  void* ptr = std::malloc(size);
  if (!ptr) {
    throw std::bad_alloc();
  }
  return ptr;
}

inline void* CheckedCalloc(size_t num, size_t size) {
  void* ptr = std::calloc(num, size);
  if (!ptr) {
    throw std::bad_alloc();
  }
  return ptr;
}
