#include "pch.h"
#include "cxxdb_base.hpp"
namespace cxxdb {
	std_string<char> char_encoding(encoding_t encoder){
		std_string<char> internal = "";
		if (encoder == encoding_t::ANSI) internal = "ANSI";
		else if (encoder == encoding_t::UTF8) internal = "UTF8";
		else if (encoder == encoding_t::UTF16) internal = "UTF16";
		else if (encoder == encoding_t::UTF32) internal = "UTF32";
		else;
		return std_string<char>(internal);
	}
	std_string<wchar_t> wchar_encoding(encoding_t encoder){
		std_string<wchar_t> internal = L"";
		if (encoder == encoding_t::ANSI) internal = L"ANSI";
		else if (encoder == encoding_t::UTF8) internal = L"UTF8";
		else if (encoder == encoding_t::UTF16) internal = L"UTF16";
		else if (encoder == encoding_t::UTF32) internal = L"UTF32";
		else;
		return std_string<wchar_t>(internal);
	}
}
