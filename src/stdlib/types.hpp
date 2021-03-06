#pragma once

#include <vector>

#include "xigua/data.hpp"
#include "xigua/enviroment.hpp"
#include "xigua/error.hpp"

#include "stdlib/utils.hpp"

namespace xig {
namespace stdlib {

class type_query_base : public method {
  int amount_of_arguments() const { return 1; }

  virtual data_type expected_type() const = 0;

  data_ptr run(call_info fci) {
    auto argument_type = fci.args.at(0)->type();

    bool ret = false;
    if (argument_type == expected_type())
      ret = true;

    return make_boolean(ret);
  }
};

class is_string : public type_query_base {
  data_type expected_type() const { return data_type::string; }
};
class is_decimal : public type_query_base {
  data_type expected_type() const { return data_type::decimal; }
};
class is_integer : public type_query_base {
  data_type expected_type() const { return data_type::integer; }
};
class is_boolean : public type_query_base {
  data_type expected_type() const { return data_type::boolean; }
};
class is_tuple : public type_query_base {
  data_type expected_type() const { return data_type::tuple; }
};
class is_map : public type_query_base {
  data_type expected_type() const { return data_type::map; }
};
class is_none : public type_query_base {
  data_type expected_type() const { return data_type::none; }
};
class is_keyword : public type_query_base {
  data_type expected_type() const { return data_type::keyword; }
};
class is_function : public type_query_base {
  data_type expected_type() const { return data_type::function; }
};
}
}
