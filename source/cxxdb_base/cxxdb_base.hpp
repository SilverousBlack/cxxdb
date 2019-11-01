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
	inline bool common_str_comparator(std_string<charT> lstr, std_string<charT> rstr){
		return (lstr == rstr);
	}
	template<typename type>
	inline bool common_type_comparator(type left, type right) {
		return left == right;
	}


	/* string content type */
	enum class content_t {
		str,
		num,
		cur,
		bin,
		oct,
		hex,
		dat,
	};

	/* string encoding */
	enum class encoding_t {
		ANSI,
		UTF8,
		UTF16,
		UTF32
	};

	/* interpreter object */
	/* class decleration */
	template<typename charT>
	class interpreter;

	/* definition for char-based interpreter */
	template<>
	class interpreter<char> {
	private:
		static uint64_t		_spawn;
		std_string<char>	caught;
		std_string<char>	out;
		encoding_t			encoder;
		double				value;
	public:
		interpreter();
		interpreter(std_string<char>, encoding_t = encoding_t::ANSI);
		~interpreter();

		uint64_t			spawned();
		std_string<char>	encoding();
	};

	/* interpreter_attrbutes structure */
	/* data structure declaration */
	template<typename charT, typename uchar>
	struct interpreter_attributes;

	template<>
	struct interpreter_attributes<char, char> {
		/* members */
		std_string<char>	char_type;
		std_string<char>	encoder;
		uint64_t			spawn_count;

		interpreter_attributes();
		interpreter_attributes(interpreter<char>);
		~interpreter_attributes() {};
	};

	inline interpreter_attributes<char, char>::interpreter_attributes()
		: char_type("char")
		, encoder()
		, spawn_count()
	{}

	inline interpreter_attributes<char, char>::interpreter_attributes(interpreter<char> interpret)
		: char_type("char")
		, encoder(interpret.encoding())
		, spawn_count(interpret.spawned())
	{}

	inline uint64_t interpreter<char>::spawned(){
		return uint64_t(_spawn);
	}

	inline std_string<char> interpreter<char>::encoding(){
		std_string<char> internal = "";
		if (encoder == encoding_t::ANSI) internal = "ANSI";
		else if (encoder == encoding_t::UTF8) internal = "UTF8";
		else if (encoder == encoding_t::UTF16) internal = "UTF16";
		else if (encoder == encoding_t::UTF32) internal = "UTF32";
		else;
		return std_string<char>(internal);
	}

}

#endif // !CXXDB_BASE_HPP
