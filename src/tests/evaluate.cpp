#include "gtest/gtest.h"
#include "xigua/xigua.hpp"
#include "xigua/stdlib.hpp"

using namespace xig;

TEST(Evaluate, Evaluate) {
  xig::enviroment env = xig::stdlib::get_global_enviroment();

  EXPECT_EQ(*make_integer(4),
            *xig::evaluate(env, parser::from_string("[+ 2 2]")));
}
