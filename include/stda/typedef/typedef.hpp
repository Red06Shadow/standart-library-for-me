#include <vector>
#include <stda/sstrings/sstrings.hpp>
#include <stda/numbers/numbers.hpp>

#ifndef TYPEDEFS
#define TYPEDEFS

/* @Documentacion:
 * Contiene una simplificacion de definiciones de clases para facilitar su uso
 */

typedef std::vector<Number::byte> vbytes;
typedef std::vector<Number::word> vword;
typedef std::vector<Number::dword> vdword;
typedef std::vector<Number::qword> vqword;
typedef std::vector<stringbuffer> vstringbuffers;
typedef std::vector<wstringbuffer> vwstringbuffers;
typedef std::vector<std::string> vstrings;
typedef std::vector<std::wstring> vwstrings;
typedef std::vector<char*> vcstr;
#endif