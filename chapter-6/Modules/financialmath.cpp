module financialmath;

#include <cmath>

namespace financialmath {
  long double calculateCompoundedInterest(const long double initialCapital,
    const long double rate,
    const unsigned short term) {
    return initialCapital * pow((1.0 + rate / 100.0), term);
  }
}