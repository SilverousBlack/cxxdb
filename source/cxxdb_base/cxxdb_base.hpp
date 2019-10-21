#include "pch.h"

#ifndef CXXDB_BASE_HPP
#define CXXDB_BASE_HPP

namespace cxxdb {
	/* allocator */
	template<typename type>
	using std_allocator = std::allocator<type>;

	/* ios */
	template<typename charT, typename charTraits = std::char_traits< charT > >
	using std_ios = std::basic_ios<charT, charTraits>;
	template<typename charT, typename charTraits = std::char_traits< charT > >
	using std_iostream = std::basic_iostream<charT, charTraits>;
	template<typename charT, typename charTraits = std::char_traits< charT > >
	using std_istream = std::basic_istream<charT, charTraits>;
	template<typename charT, typename charTraits = std::char_traits< charT > >
	using std_ostream = std::basic_ostream<charT, charTraits>;
	template<typename charT, typename charTraits = std::char_traits< charT > >
	using std_streambuf = std::basic_streambuf<charT, charTraits>;

	/* fstream */
	template<typename charT, typename charTraits = std::char_traits< charT > >
	using std_fstream = std::basic_fstream<charT, charTraits>;
	template<typename charT, typename charTraits = std::char_traits< charT > >
	using std_ifstream = std::basic_ifstream<charT, charTraits>;
	template<typename charT, typename charTraits = std::char_traits< charT > >
	using std_ofstream = std::basic_ofstream<charT, charTraits>;
	template<typename charT, typename charTraits = std::char_traits< charT > >
	using std_filebuf = std::basic_filebuf<charT, charT>;

	/* string and stringstream */
	template<typename charT, typename charTraits = std::char_traits< charT >, typename allocator = std::allocator < charT > >
	using std_string = std::basic_string<charT, charTraits, allocator>;
	template<typename charT, typename charTraits = std::char_traits< charT >, typename allocator = std::allocator < charT > >
	using std_stringstream = std::basic_stringstream<charT, charTraits, allocator>;
	template<typename charT, typename charTraits = std::char_traits< charT >, typename allocator = std::allocator < charT > >
	using std_istringstream = std::basic_istringstream<charT, charTraits, allocator>;
	template<typename charT, typename charTraits = std::char_traits< charT >, typename allocator = std::allocator < charT > >
	using std_ostringstream = std::basic_ostringstream<charT, charTraits, allocator>;
	template<typename charT, typename charTraits = std::char_traits< charT >, typename allocator = std::allocator < charT > >
	using std_stringbuf = std::basic_stringbuf<charT, charTraits, allocator>;

	/* vector */
	template<typename type, typename allocator = std::allocator < type > >
	using std_vector = std::vector<type, allocator>;

	/* comparators */
	template<typename charT>
	inline bool common_str_comparator(std_string<charT> lstr, std_string<charT> rstr) {
		return lstr == rstr;
	}
	template<typename type>
	inline bool common_type_comparator(type left, type right) {
		return left == right;
	}


	/* string content type */
	namespace content_type {
		enum content_type {
			str,
			num,
			cur,
			bin,
			oct,
			hex,
			dat,
		};
	}

	using content_t = content_type::content_type;
	const content_t content_str = content_type::str;
	const content_t content_num = content_type::num;
	const content_t content_cur = content_type::bin;
	const content_t content_oct = content_type::oct;
	const content_t content_hex = content_type::hex;
	const content_t content_dat = content_type::dat;

	/* string encoding */
	namespace encoding {
		enum encoding {
			ANSI,
			UTF8,
			UTF16,
			UTF32,
		};
	}

	using encoding_t = encoding::encoding;
	const encoding_t encoding_ansi = encoding::ANSI;
	const encoding_t encoding_utf8 = encoding::UTF8;
	const encoding_t encoding_utf16 = encoding::UTF16;
	const encoding_t encoding_utf32 = encoding::UTF32;
	
	/* interpreter object */
	/* class decleration */
	template<typename charT, encoding_t encodingT = encoding_ansi>
	class interpreter {
	private:
		std_string<charT>	intern;
		std_string<charT>	content;
		long long double	val;
		
	public:
		interpreter(std_string<charT>);
		interpreter(const charT*);
		~interpreter();
	protected:
		bool util_isdatfunc(std_string<charT>);
		bool util_isstr(std_string<charT>);

	};

	/* class implemetation */
	template<typename charT, encoding_t encodingT>
	inline interpreter<charT, encodingT>::interpreter(std_string<charT> str)
		: intern(str)
	{
		size_t sz = str.size();
		if(s)
	}
}

#endif // !CXXDB_BASE_HPP
