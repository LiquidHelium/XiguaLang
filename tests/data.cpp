
#include "gtest/gtest.h"

#include "data.hpp"

using namespace xig;

TEST(Data, Equality) {
	EXPECT_EQ(make_number(2), make_number(2));
	EXPECT_EQ(make_string("2"), make_string("2"));
	EXPECT_EQ(make_keyword("2"), make_keyword("2"));
	EXPECT_EQ(make_boolean(false), make_boolean(false));
}
