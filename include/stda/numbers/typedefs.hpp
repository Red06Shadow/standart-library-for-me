
#ifndef TYPEDEFNUMBERS
#define TYPEDEFNUMBERS

using i8 = char;
using u8 = unsigned char;
#define sizeu8 sizeof(u8)
#define nbitsu8 8
#define maxu8 size_t(256)

using i16 = short;
using u16 = unsigned short;
#define sizeu16 sizeof(u16)
#define nbitsu16 16
#define maxu16 size_t(maxu8 *maxu8)

using i32 = int;
using u32 = unsigned int;
#define sizeu32 sizeof(u32)
#define nbitsu32 32
#define maxu32 size_t(maxu16 *maxu16)

using i64 = long long;
using u64 = unsigned long long;
#define sizeu64 sizeof(u64)
#define nbitsu64 64
#define maxu64l size_t(-1)

using f32 = float;
#define sizef32 sizeof(f32)
#define nbitsf32 32

using f64 = double;
#define sizef64 sizeof(f64)
#define nbitsf64 64

using f128 = long double;
#define sizef128 sizeof(f128)
#define nbitsf128 128

#endif