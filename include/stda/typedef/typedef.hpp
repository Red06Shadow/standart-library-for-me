#include <vector>
#include <stda/standart/utilitys.hpp>
#include <stda/standart/numbers.hpp>
#include <stda/sstrings/sstrings.hpp>

#ifndef TYPEDEFS
#define TYPEDEFS
typedef std::vector<numbers::byte> vbytes;
typedef std::vector<numbers::word> vword;
typedef std::vector<numbers::dword> vdword;
typedef std::vector<numbers::qword> vqword;
typedef std::vector<stringbuffer> vstringbuffers;
typedef std::vector<wstringbuffer> vwstringbuffers;
typedef std::vector<std::string> vstrings;
typedef std::vector<std::wstring> vwstrings;
typedef std::vector<char*> vcstr;
#endif