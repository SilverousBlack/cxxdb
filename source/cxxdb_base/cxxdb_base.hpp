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

	std_string<char>	char_encoding(encoding_t);
	std_string<wchar_t> wchar_encoding(encoding_t);

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

		template<typename charT, typename uchar>
		friend struct interpreter_attributes;

		static uint64_t	spawn_count();
		uint64_t		spawned();
	};

	uint64_t interpreter<char>::_spawn = 0;

	template<>
	class interpreter<wchar_t> {
	private:
		static uint64_t		_spawn;
		std_string<wchar_t>	caught;
		std_string<wchar_t>	out;
		encoding_t			encoder;
		double				value;
	public:
		interpreter();
		interpreter(std_string<char>, encoding_t = encoding_t::UTF16);
		~interpreter();

		template<typename charT, typename uchar>
		friend struct interpreter_attributes;

		static uint64_t spawn_count();
		uint64_t		spawned();
	};

	uint64_t interpreter<wchar_t>::_spawn = 0;

	/* interpreter_attrbutes structure */
	/* data structure declaration */
	/*
		charT - interpreter char type
		uchar - interpreter_attributes char type
	*/
	template<typename charT, typename uchar>
	struct interpreter_attributes;

	template<>
	struct interpreter_attributes<char, char> {
		/* members */
		std_string<char>	char_type;
		std_string<char>	encoder;
		uint64_t			spawn_count;

		interpreter_attributes();
		interpreter_attributes(interpreter<char>&);
		~interpreter_attributes() {};
	};

	template<>
	struct interpreter_attributes<char, wchar_t> {
		/* members */
		std_string<wchar_t>	char_type;
		std_string<wchar_t>	encoder;
		uint64_t			spawn_count;

		interpreter_attributes();
		interpreter_attributes(interpreter<char>&);
		~interpreter_attributes() {};
	};

	template<>
	struct interpreter_attributes<wchar_t, char> {
		/* members */
		std_string<char>	char_type;
		std_string<char>	encoder;
		uint64_t			spawn_count;

		interpreter_attributes();
		interpreter_attributes(interpreter<wchar_t>&);
		~interpreter_attributes() {};
	};

	inline interpreter_attributes<char, char>::interpreter_attributes()
		: char_type("char")
		, encoder()
		, spawn_count(interpreter<char>::spawn_count())
	{}

	inline interpreter_attributes<char, wchar_t>::interpreter_attributes()
		: char_type(L"char")
		, encoder()
		, spawn_count(interpreter<char>::spawn_count())
	{}

	inline interpreter_attributes<wchar_t, char>::interpreter_attributes()
		: char_type("wchar_t")
		, encoder()
		, spawn_count(interpreter<wchar_t>::spawn_count())
	{}

	inline interpreter_attributes<char, char>::interpreter_attributes(interpreter<char>& interpret)
		: char_type("char")
		, spawn_count(interpret.spawned())
	{
		encoding_t en = interpret.encoder;
		encoder = char_encoding(en);
	}

	inline interpreter_attributes<char, wchar_t>::interpreter_attributes(interpreter<char>& interpret)
		: char_type(L"char")
		, spawn_count(interpret.spawned())
	{
		encoding_t en = interpret.encoder;
		encoder = wchar_encoding(en);
	}

	inline interpreter_attributes<wchar_t, char>::interpreter_attributes(interpreter<wchar_t>& interpret)
		: char_type("wchar_t")
		, spawn_count(interpret.spawned())
	{
		encoding_t en = interpret.encoder;
		encoder = char_encoding(en);
	}

	inline interpreter<char>::interpreter()
		: caught()
		, out()
		, encoder()
		, value()
	{
		_spawn++;
	}

	inline interpreter<char>::~interpreter(){
		_spawn--;
	}

	inline uint64_t interpreter<char>::spawn_count() {
		return uint64_t(_spawn);
	}

	inline uint64_t interpreter<wchar_t>::spawn_count(){
		return uint64_t(_spawn);
	}

	inline uint64_t interpreter<char>::spawned() {
		return uint64_t(_spawn);
	}

	inline uint64_t interpreter<wchar_t>::spawned() {
		return uint64_t(_spawn);
	}
}

#endif // !CXXDB_BASE_HPP
