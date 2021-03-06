#pragma once

#include <vector>
#include <chrono>

#include "xigua/data.hpp"
#include "xigua/enviroment.hpp"
#include "xigua/evaluate.hpp"
#include "xigua/error.hpp"

#include "stdlib/utils.hpp"

namespace xig {
namespace stdlib {

class benchmark : public method {
  int amount_of_arguments() const { return 3; }
  bool should_evaluate_arguments() const { return false; }

  data_ptr run(call_info fci) {
    if (fci.args.at(0)->type() != data_type::string)
      throw error(error_type::invalid_arguments, "Not A String", fci.debug);

    if (fci.args.at(1)->type() != data_type::integer)
      throw error(error_type::invalid_arguments, "Not A Integer", fci.debug);

    if (fci.args.at(2)->type() != data_type::process)
      throw error(error_type::invalid_arguments, "Not A Process", fci.debug);

    std::chrono::steady_clock::time_point start_time =
        std::chrono::steady_clock::now();

    long long times = fci.args.at(1)->as_integer().as_int();
    for (long i = 0; i < times; i++) {
      evaluate(fci.env, fci.args.at(2), fci.debug);
    }

    std::chrono::steady_clock::time_point end_time =
        std::chrono::steady_clock::now();

    auto dur =
        std::chrono::duration_cast<std::chrono::duration<int, std::milli>>(
            end_time - start_time).count();
    auto average = dur / times;

    std::cout << "Benchmark: " << fci.args.at(0)->as_string().as_std_string()
              << std::endl << "Total Time: " << dur << "ms" << std::endl
              << "Average Time: " << average << "ms" << std::endl;

    return make_none();
  }
};
}
}
