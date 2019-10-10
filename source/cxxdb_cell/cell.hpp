#pragma once

#include "..//cxxdb_base/cxxdb_base.hpp"

#ifndef _CXXDB_CELL_HPP_
#define _CXXDB_CELL_HPP_

namespace cxxdb {
	enum cell_mode {
		header,
		general,
		function
	};

	template<typename charT, const cell_mode modeCell>
	class basic_cell {
	private:
		std_string<charT> content;
		bool (*comparator)(std_string<charT>, std_string<charT>);
	public:
		basic_cell();
		basic_cell(std_string<charT>, bool (*comp)(std_string<charT>, std_string<charT>) = common_str_comparator);
		~basic_cell();

		cell_mode			get_cell_mode();
		std_string<charT>	get_cell_content();
	};

	template<typename charT>
	class basic_cell_header : public basic_cell<charT, header> {
	private:
		uint64_t pos;
	public:
		basic_cell_header();
		basic_cell_header(basic_cell<charT, header>&, uint64_t);
		basic_cell_header(std_string<charT>, uint64_t, bool (std_string<charT>, std_string<charT>) = common_str_comparator);
		~basic_cell_header();
	};

	template<typename charT>
	class basic_cell_general : public basic_cell<charT, header> {
	private:
		basic_cell_header<charT> head;
		uint64_t posx;
		uint64_t posy;
	public:
		basic_cell_general();
	};

	// definitions
	template<typename charT, cell_mode modeCell>
	inline basic_cell<charT, modeCell>::basic_cell()
		: content()
		, comparator(NULL)
	{}

	template<typename charT, cell_mode modeCell>
	inline basic_cell<charT, modeCell>::basic_cell(std_string<charT> str, bool(*comp)(std_string<charT>, std_string<charT>))
		: content(str)
		, comparator(comp)
	{}

	template<typename charT, cell_mode modeCell>
	inline basic_cell<charT, modeCell>::~basic_cell()
	{}

	template<typename charT>
	inline basic_cell_header<charT>::basic_cell_header()
		: pos(0)
	{}

	template<typename charT>
	inline basic_cell_header<charT>::basic_cell_header(basic_cell<charT, header>&head, uint64_t x)
		: pos(x)
		, basic_cell<charT, header>(head)
	{}

}

#endif // !_CXXDB_CELL_HPP_

