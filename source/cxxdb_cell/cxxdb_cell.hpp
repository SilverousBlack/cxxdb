#pragma once

#include "..//cxxdb_base/cxxdb_base.hpp"

#ifndef CXXDB_CELL_HPP
#define CXXDB_CELL_HPP

namespace cxxdb {
	enum cell_mode {
		header,
		general,
		function
	};

	enum content_type {
		numerical,
		string,
		func,
		gen
	};

	/* string comparator */
	template<typename charT>
	static bool (*comparator)(std_string<charT>, std_string<charT>) = 0;
	template<typename charT>
	inline void set_comparator_common() {
		comparator<charT> = common_str_comparator<charT>;
	}
	template<typename charT>
	inline bool call_comparator(std_string<charT> lstr, std_string<charT> rstr) {
		if (comparator<charT> != NULL) return (*comparator<charT>)(lstr, rstr);
		else return false;
	}

	/* string content_type identifier */
	template<typename charT>
	static content_type (*identifier)(std_string<charT>) = 0;
	template<typename charT>
	inline content_type common_content_identifier(std_string<charT>) {
		return content_type(0);
	}
	template<typename charT>
	inline void set_identifier_common() {
		identifier<charT> = common_content_identifier<charT>;
	}
	template<typename charT>
	inline content_type call_identifier(std_string<charT>) {
		return content_type();
	}

	template<typename charT, const cell_mode cellMode>
	class basic_cell {
	private:
		std_string<charT>	content;
		content_type		contentType;
	public:

	};

	template<typename charT>
	class basic_cell_header : public basic_cell<charT, header> {
	private:

	public:

	};

	template<typename charT>
	class basic_cell_general : public basic_cell<charT, general> {
	private:
		basic_cell_header<charT>* header;

	public:

	};

	template<typename charT>
	class basic_cell_function : public basic_cell<charT, function> {};
}

#endif // !_CXXDB_CELL_HPP_