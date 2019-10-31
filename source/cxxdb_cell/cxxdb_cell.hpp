#pragma once

#include "..//cxxdb_base/cxxdb_base.hpp"

#ifndef CXXDB_CELL_HPP
#define CXXDB_CELL_HPP

namespace cxxdb {
	namespace cell_type {
		enum cell_type {
			header,
			body
		};
	}

	template<typename charT>
	static bool (*comparator)(std_string<charT>, std_string<charT>) = NULL;

	template<typename charT, const cell_type::cell_type cellT>
	class basic_cell {
	private:
		std_string<charT>			content;
		std_string<charT>			intern;
	};
}
#endif // !_CXXDB_CELL_HPP_