#include "gtest/gtest.h"

import financialmath;

TEST(FinancialmathModuleTest, FinalCapitalIsCalculatedCorrectly) {
  auto finalCapital = financialmath::calculateCompoundedInterest(3500.0, 4.0, 3);
  EXPECT_DOUBLE_EQ(3937.024, finalCapital);
}