#ifndef CHECK_H
#define CHECK_H

#include <cstdlib>
#include <iostream>

#define CHECK(condition)                                  \
  do {                                                    \
    if (!(condition)) {                                   \
      std::cerr << __FILE__ << ":" << __LINE__            \
                << ": CHECK failed: " #condition << "\n"; \
      std::exit(1);                                       \
    }                                                     \
  } while (false)

#define CHECK_FAIL()                                            \
  std::cerr << __FILE__ << ":" << __LINE__ << ": CHECK_FAIL\n"; \
  std::exit(1)

#endif // CHECK_H
