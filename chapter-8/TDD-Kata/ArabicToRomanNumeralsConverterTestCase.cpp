#include <gtest/gtest.h>
#include <string>
#include <array>

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

struct ArabicToRomanMapping {
  unsigned int arabicNumber;
  std::string romanNumeral;
};

const std::array arabicToRomanMappings {
    ArabicToRomanMapping { 1000, "M"  },
    ArabicToRomanMapping {  900, "CM" },
    ArabicToRomanMapping {  500, "D"  },
    ArabicToRomanMapping {  400, "CD" },
    ArabicToRomanMapping {  100, "C"  },
    ArabicToRomanMapping {   90, "XC" },
    ArabicToRomanMapping {   50, "L"  },
    ArabicToRomanMapping {   40, "XL" },
    ArabicToRomanMapping {   10, "X"  },
    ArabicToRomanMapping {    9, "IX" },
    ArabicToRomanMapping {    5, "V"  },
    ArabicToRomanMapping {    4, "IV" },
    ArabicToRomanMapping {    1, "I"  }
};

std::string convertArabicNumberToRomanNumeral(unsigned int arabicNumber) {
  std::string romanNumeral;
  for (auto mapping : arabicToRomanMappings) {
    while (arabicNumber >= mapping.arabicNumber) {
      romanNumeral += mapping.romanNumeral;
      arabicNumber -= mapping.arabicNumber;
    }
  }
  return romanNumeral;
}

// Test code starts here...

class RomanNumeralAssert {
public:
  RomanNumeralAssert() = delete;
  explicit RomanNumeralAssert(const unsigned int arabicNumber) noexcept :
      arabicNumberToConvert(arabicNumber) { }
  void isConvertedToRomanNumeral(const std::string& expectedRomanNumeral) const {
    ASSERT_EQ(expectedRomanNumeral, convertArabicNumberToRomanNumeral(arabicNumberToConvert));
  }

private:
  const unsigned int arabicNumberToConvert;
};

RomanNumeralAssert checkIf(const unsigned int arabicNumber) noexcept {
  RomanNumeralAssert assert { arabicNumber };
  return assert;
}

TEST(ArabicToRomanNumeralsConverterTestCase, conversionOfArabicNumbersToRomanNumerals_Works) {
  checkIf(1).isConvertedToRomanNumeral("I");
  checkIf(2).isConvertedToRomanNumeral("II");
  checkIf(3).isConvertedToRomanNumeral("III");
  checkIf(4).isConvertedToRomanNumeral("IV");
  checkIf(5).isConvertedToRomanNumeral("V");
  checkIf(6).isConvertedToRomanNumeral("VI");
  checkIf(9).isConvertedToRomanNumeral("IX");
  checkIf(10).isConvertedToRomanNumeral("X");
  checkIf(20).isConvertedToRomanNumeral("XX");
  checkIf(30).isConvertedToRomanNumeral("XXX");
  checkIf(33).isConvertedToRomanNumeral("XXXIII");
  checkIf(37).isConvertedToRomanNumeral("XXXVII");
  checkIf(50).isConvertedToRomanNumeral("L");
  checkIf(99).isConvertedToRomanNumeral("XCIX");
  checkIf(100).isConvertedToRomanNumeral("C");
  checkIf(200).isConvertedToRomanNumeral("CC");
  checkIf(300).isConvertedToRomanNumeral("CCC");
  checkIf(499).isConvertedToRomanNumeral("CDXCIX");
  checkIf(500).isConvertedToRomanNumeral("D");
  checkIf(1000).isConvertedToRomanNumeral("M");
  checkIf(2000).isConvertedToRomanNumeral("MM");
  checkIf(2017).isConvertedToRomanNumeral("MMXVII");
  checkIf(3000).isConvertedToRomanNumeral("MMM");
  checkIf(3333).isConvertedToRomanNumeral("MMMCCCXXXIII");
  checkIf(3999).isConvertedToRomanNumeral("MMMCMXCIX");
}
