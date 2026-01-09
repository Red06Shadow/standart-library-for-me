#include <stda/numbers/numbers.hpp>

stringbuffer Number::Binary::operator<<(u8 __value)
{
    return Binary::binary<u8>(__value);
}
stringbuffer Number::Binary::operator<<(i8 __value)
{
    return Binary::binary<u8>(__value);
}
stringbuffer Number::Binary::operator<<(byte __value)
{
    return Binary::binary<u8>(__value.value_unsigned());
}
stringbuffer Number::Binary::operator<<(u16 __value)
{
    return Binary::binary<u16>(__value);
}
stringbuffer Number::Binary::operator<<(i16 __value)
{
    return Binary::binary<u16>(__value);
}
stringbuffer Number::Binary::operator<<(word __value)
{
    return Binary::binary<u16>(__value.value_unsigned());
}
stringbuffer Number::Binary::operator<<(u32 __value)
{
    return Binary::binary<u32>(__value);
}
stringbuffer Number::Binary::operator<<(i32 __value)
{
    return Binary::binary<u32>(__value);
}
stringbuffer Number::Binary::operator<<(dword __value)
{
    return Binary::binary<u32>(__value.value_unsigned());
}
stringbuffer Number::Binary::operator<<(u64 __value)
{
    return Binary::binary<u64>(__value);
}
stringbuffer Number::Binary::operator<<(i64 __value)
{
    return Binary::binary<u64>(__value);
}
stringbuffer Number::Binary::operator<<(Number::qword __value)
{
    return Binary::binary<u64>(__value.value_unsigned());
}

stringbuffer Number::Hexadecimal::operator<<(u8 __value)
{
    return Hexadecimal::hexadecimal<u8>(__value);
}
stringbuffer Number::Hexadecimal::operator<<(i8 __value)
{
    return Hexadecimal::hexadecimal<u8>(__value);
}
stringbuffer Number::Hexadecimal::operator<<(byte __value)
{
    return Hexadecimal::hexadecimal<u8>(__value.value_unsigned());
}
stringbuffer Number::Hexadecimal::operator<<(u16 __value)
{
    return Hexadecimal::hexadecimal<u16>(__value);
}
stringbuffer Number::Hexadecimal::operator<<(i16 __value)
{
    return Hexadecimal::hexadecimal<u16>(__value);
}
stringbuffer Number::Hexadecimal::operator<<(word __value)
{
    return Hexadecimal::hexadecimal<u16>(__value.value_unsigned());
}
stringbuffer Number::Hexadecimal::operator<<(u32 __value)
{
    return Hexadecimal::hexadecimal<u32>(__value);
}
stringbuffer Number::Hexadecimal::operator<<(i32 __value)
{
    return Hexadecimal::hexadecimal<u32>(__value);
}
stringbuffer Number::Hexadecimal::operator<<(dword __value)
{
    return Hexadecimal::hexadecimal<u32>(__value.value_unsigned());
}
stringbuffer Number::Hexadecimal::operator<<(u64 __value)
{
    return Hexadecimal::hexadecimal<u64>(__value);
}
stringbuffer Number::Hexadecimal::operator<<(i64 __value)
{
    return Hexadecimal::hexadecimal<u64>(__value);
}
stringbuffer Number::Hexadecimal::operator<<(qword __value)
{
    return Hexadecimal::hexadecimal<u64>(__value.value_unsigned());
}

template <>
f32 Number::limits<f32>::min()
{
    return 10e-46;
}
template <>
f32 Number::limits<f32>::max()
{
    return 10e38;
}
template <>
f64 Number::limits<f64>::min()
{
    return 10e-324;
}
template <>
f64 Number::limits<f64>::max()
{
    return 10e307;
}

Number::byte Number::byte::operator+=(int value2)
{
    this->reference_signed() += (i8)value2;
    return *this;
}
Number::byte Number::byte::operator+=(i8 value2)
{
    this->reference_signed() += value2;
    return *this;
}
Number::byte Number::byte::operator+=(u8 value2)
{
    this->reference_unsigned() += value2;
    return *this;
}
Number::byte Number::byte::operator+=(byte _dword2)
{
    this->reference_unsigned() += _dword2.value_unsigned();
    return *this;
}
Number::byte Number::byte::operator-=(int value2)
{
    this->reference_signed() -= (i8)value2;
    return *this;
}
Number::byte Number::byte::operator-=(i8 value2)
{
    this->reference_signed() -= value2;
    return *this;
}
Number::byte Number::byte::operator-=(u8 value2)
{
    this->reference_unsigned() -= value2;
    return *this;
}
Number::byte Number::byte::operator-=(byte _dword2)
{
    this->reference_unsigned() -= _dword2.value_unsigned();
    return *this;
}
Number::byte Number::byte::operator*=(int value2)
{
    this->reference_signed() *= (i8)value2;
    return *this;
}
Number::byte Number::byte::operator*=(i8 value2)
{
    this->reference_signed() *= value2;
    return *this;
}
Number::byte Number::byte::operator*=(u8 value2)
{
    this->reference_unsigned() *= value2;
    return *this;
}
Number::byte Number::byte::operator*=(byte _dword2)
{
    this->reference_unsigned() *= _dword2.value_unsigned();
    return *this;
}

Number::byte Number::byte::operator/=(int value2)
{
    this->reference_signed() /= (i8)value2;
    return *this;
}
Number::byte Number::byte::operator/=(i8 value2)
{
    this->reference_signed() /= value2;
    return *this;
}
Number::byte Number::byte::operator/=(u8 value2)
{
    this->reference_unsigned() /= value2;
    return *this;
}
Number::byte Number::byte::operator/=(byte _dword2)
{
    this->reference_unsigned() /= _dword2.value_unsigned();
    return *this;
}

Number::byte Number::byte::operator%=(int value2)
{
    this->reference_signed() %= (i8)value2;
    return *this;
}
Number::byte Number::byte::operator%=(i8 value2)
{
    this->reference_signed() %= value2;
    return *this;
}
Number::byte Number::byte::operator%=(u8 value2)
{
    this->reference_unsigned() %= value2;
    return *this;
}
Number::byte Number::byte::operator%=(byte _dword2)
{
    this->reference_unsigned() %= _dword2.value_unsigned();
    return *this;
}
Number::byte Number::byte::operator&=(u8 value2)
{
    this->reference_unsigned() &= value2;
    return *this;
}
Number::byte Number::byte::operator&=(byte _dword2)
{
    this->reference_unsigned() &= _dword2.value_unsigned();
    return *this;
}

Number::byte Number::byte::operator|=(u8 value2)
{
    this->reference_unsigned() |= value2;
    return *this;
}
Number::byte Number::byte::operator|=(byte _dword2)
{
    this->reference_unsigned() |= _dword2.value_unsigned();
    return *this;
}

Number::byte Number::byte::operator^=(u8 value2)
{
    this->reference_unsigned() ^= value2;
    return *this;
}
Number::byte Number::byte::operator^=(byte _dword2)
{
    this->reference_unsigned() ^= _dword2.value_unsigned();
    return *this;
}

bool Number::byte::operator==(Number::byte v)
{
    return value_unsigned() == v.value_unsigned();
}
bool Number::byte::operator==(u8 v)
{
    return value_unsigned() == v;
}
bool Number::byte::operator==(i8 v)
{
    return value_signed() == v;
}
bool Number::byte::operator==(int v)
{
    return value_signed() == (i8)v;
}
bool Number::byte::operator!=(Number::byte v)
{
    return value_unsigned() != v.value_unsigned();
}
bool Number::byte::operator!=(u8 v)
{
    return value_unsigned() != v;
}
bool Number::byte::operator!=(i8 v)
{
    return value_signed() != v;
}
bool Number::byte::operator!=(int v)
{
    return value_signed() != (i8)v;
}
bool Number::byte::operator<(Number::byte v)
{
    return value_unsigned() < v.value_unsigned();
}
bool Number::byte::operator<(u8 v)
{
    return value_unsigned() < v;
}
bool Number::byte::operator<(i8 v)
{
    return value_signed() < v;
}
bool Number::byte::operator<(int v)
{
    return value_signed() < (i8)v;
}
bool Number::byte::operator>(Number::byte v)
{
    return value_unsigned() > v.value_unsigned();
}
bool Number::byte::operator>(u8 v)
{
    return value_unsigned() > v;
}
bool Number::byte::operator>(i8 v)
{
    return value_signed() > v;
}
bool Number::byte::operator>(int v)
{
    return value_signed() > (i8)v;
}
bool Number::byte::operator>=(Number::byte v)
{
    return value_unsigned() >= v.value_unsigned();
}
bool Number::byte::operator>=(u8 v)
{
    return value_unsigned() >= v;
}
bool Number::byte::operator>=(i8 v)
{
    return value_signed() >= v;
}
bool Number::byte::operator>=(int v)
{
    return value_signed() >= (i8)v;
}
bool Number::byte::operator<=(Number::byte v)
{
    return value_unsigned() <= v.value_unsigned();
}
bool Number::byte::operator<=(u8 v)
{
    return value_unsigned() <= v;
}
bool Number::byte::operator<=(i8 v)
{
    return value_signed() <= v;
}
bool Number::byte::operator<=(int v)
{
    return value_signed() <= (i8)v;
}
bool Number::byte::operator&&(Number::byte v)
{
    return value_unsigned() && v.value_unsigned();
}
bool Number::byte::operator&&(u8 v)
{
    return value_unsigned() && v;
}
bool Number::byte::operator&&(i8 v)
{
    return value_signed() && v;
}
bool Number::byte::operator&&(int v)
{
    return value_signed() && (i8)v;
}
bool Number::byte::operator||(Number::byte v)
{
    return value_unsigned() || v.value_unsigned();
}
bool Number::byte::operator||(u8 v)
{
    return value_unsigned() || v;
}
bool Number::byte::operator||(i8 v)
{
    return value_signed() || v;
}
bool Number::byte::operator||(int v)
{
    return value_signed() || (i8)v;
}
bool Number::byte::operator!()
{
    return !value_signed();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
Number::byte Number::byte::operator++()
{
    return ++(this->reference_unsigned());
}
Number::byte Number::byte::operator--()
{
    return --(this->reference_unsigned());
}
Number::byte Number::byte::operator++(int)
{
    return this->reference_unsigned()++;
}
Number::byte Number::byte::operator--(int)
{
    return this->reference_unsigned()--;
}

Number::word Number::word::operator+=(int value2)
{
    this->reference_signed() += (i16)value2;
    return *this;
}
Number::word Number::word::operator+=(i16 value2)
{
    this->reference_signed() += value2;
    return *this;
}
Number::word Number::word::operator+=(u16 value2)
{
    this->reference_unsigned() += value2;
    return *this;
}
Number::word Number::word::operator+=(word _dword2)
{
    this->reference_unsigned() += _dword2.value_unsigned();
    return *this;
}
Number::word Number::word::operator-=(int value2)
{
    this->reference_signed() -= (i16)value2;
    return *this;
}
Number::word Number::word::operator-=(i16 value2)
{
    this->reference_signed() -= value2;
    return *this;
}
Number::word Number::word::operator-=(u16 value2)
{
    this->reference_unsigned() -= value2;
    return *this;
}
Number::word Number::word::operator-=(word _dword2)
{
    this->reference_unsigned() -= _dword2.value_unsigned();
    return *this;
}
Number::word Number::word::operator*=(int value2)
{
    this->reference_signed() *= (i16)value2;
    return *this;
}
Number::word Number::word::operator*=(i16 value2)
{
    this->reference_signed() *= value2;
    return *this;
}
Number::word Number::word::operator*=(u16 value2)
{
    this->reference_unsigned() *= value2;
    return *this;
}
Number::word Number::word::operator*=(word _dword2)
{
    this->reference_unsigned() *= _dword2.value_unsigned();
    return *this;
}

Number::word Number::word::operator/=(int value2)
{
    this->reference_signed() /= (i16)value2;
    return *this;
}
Number::word Number::word::operator/=(i16 value2)
{
    this->reference_signed() /= value2;
    return *this;
}
Number::word Number::word::operator/=(u16 value2)
{
    this->reference_unsigned() /= value2;
    return *this;
}
Number::word Number::word::operator/=(word _dword2)
{
    this->reference_unsigned() /= _dword2.value_unsigned();
    return *this;
}

Number::word Number::word::operator%=(int value2)
{
    this->reference_signed() %= (i16)value2;
    return *this;
}
Number::word Number::word::operator%=(i16 value2)
{
    this->reference_signed() %= value2;
    return *this;
}
Number::word Number::word::operator%=(u16 value2)
{
    this->reference_unsigned() %= value2;
    return *this;
}
Number::word Number::word::operator%=(word _dword2)
{
    this->reference_unsigned() %= _dword2.value_unsigned();
    return *this;
}
Number::word Number::word::operator&=(u16 value2)
{
    this->reference_unsigned() &= value2;
    return *this;
}
Number::word Number::word::operator&=(word _dword2)
{
    this->reference_unsigned() &= _dword2.value_unsigned();
    return *this;
}

Number::word Number::word::operator|=(u16 value2)
{
    this->reference_unsigned() |= value2;
    return *this;
}
Number::word Number::word::operator|=(word _dword2)
{
    this->reference_unsigned() |= _dword2.value_unsigned();
    return *this;
}

Number::word Number::word::operator^=(u16 value2)
{
    this->reference_unsigned() ^= value2;
    return *this;
}
Number::word Number::word::operator^=(word _dword2)
{
    this->reference_unsigned() ^= _dword2.value_unsigned();
    return *this;
}

bool Number::word::operator==(Number::word v)
{
    return value_unsigned() == v.value_unsigned();
}
bool Number::word::operator==(u16 v)
{
    return value_unsigned() == v;
}
bool Number::word::operator==(i16 v)
{
    return value_signed() == v;
}
bool Number::word::operator==(int v)
{
    return value_signed() == (i16)v;
}
bool Number::word::operator!=(Number::word v)
{
    return value_unsigned() != v.value_unsigned();
}
bool Number::word::operator!=(u16 v)
{
    return value_unsigned() != v;
}
bool Number::word::operator!=(i16 v)
{
    return value_signed() != v;
}
bool Number::word::operator!=(int v)
{
    return value_signed() != (i16)v;
}
bool Number::word::operator<(Number::word v)
{
    return value_unsigned() < v.value_unsigned();
}
bool Number::word::operator<(u16 v)
{
    return value_unsigned() < v;
}
bool Number::word::operator<(i16 v)
{
    return value_signed() < v;
}
bool Number::word::operator<(int v)
{
    return value_signed() < (i16)v;
}
bool Number::word::operator>(Number::word v)
{
    return value_unsigned() > v.value_unsigned();
}
bool Number::word::operator>(u16 v)
{
    return value_unsigned() > v;
}
bool Number::word::operator>(i16 v)
{
    return value_signed() > v;
}
bool Number::word::operator>(int v)
{
    return value_signed() > (i16)v;
}
bool Number::word::operator>=(Number::word v)
{
    return value_unsigned() >= v.value_unsigned();
}
bool Number::word::operator>=(u16 v)
{
    return value_unsigned() >= v;
}
bool Number::word::operator>=(i16 v)
{
    return value_signed() >= v;
}
bool Number::word::operator>=(int v)
{
    return value_signed() >= (i16)v;
}
bool Number::word::operator<=(Number::word v)
{
    return value_unsigned() <= v.value_unsigned();
}
bool Number::word::operator<=(u16 v)
{
    return value_unsigned() <= v;
}
bool Number::word::operator<=(i16 v)
{
    return value_signed() <= v;
}
bool Number::word::operator<=(int v)
{
    return value_signed() <= (i16)v;
}
bool Number::word::operator&&(Number::word v)
{
    return value_unsigned() && v.value_unsigned();
}
bool Number::word::operator&&(u16 v)
{
    return value_unsigned() && v;
}
bool Number::word::operator&&(i16 v)
{
    return value_signed() && v;
}
bool Number::word::operator&&(int v)
{
    return value_signed() && (i16)v;
}
bool Number::word::operator||(Number::word v)
{
    return value_unsigned() || v.value_unsigned();
}
bool Number::word::operator||(u16 v)
{
    return value_unsigned() || v;
}
bool Number::word::operator||(i16 v)
{
    return value_signed() || v;
}
bool Number::word::operator||(int v)
{
    return value_signed() || (i16)v;
}
bool Number::word::operator!()
{
    return !value_signed();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
Number::word Number::word::operator++()
{
    return ++(this->reference_unsigned());
}
Number::word Number::word::operator--()
{
    return --(this->reference_unsigned());
}
Number::word Number::word::operator++(int)
{
    return this->reference_unsigned()++;
}
Number::word Number::word::operator--(int)
{
    return this->reference_unsigned()--;
}

Number::dword Number::dword::operator+=(i32 value2)
{
    this->reference_signed() += (i32)value2;
    return *this;
}
Number::dword Number::dword::operator+=(u32 value2)
{
    this->reference_unsigned() += value2;
    return *this;
}
Number::dword Number::dword::operator+=(dword _dword2)
{
    this->reference_unsigned() += _dword2.value_unsigned();
    return *this;
}
Number::dword Number::dword::operator-=(i32 value2)
{
    this->reference_signed() -= (i32)value2;
    return *this;
}
Number::dword Number::dword::operator-=(u32 value2)
{
    this->reference_unsigned() -= value2;
    return *this;
}
Number::dword Number::dword::operator-=(dword _dword2)
{
    this->reference_unsigned() -= _dword2.value_unsigned();
    return *this;
}
Number::dword Number::dword::operator*=(i32 value2)
{
    this->reference_signed() *= (i32)value2;
    return *this;
}
Number::dword Number::dword::operator*=(u32 value2)
{
    this->reference_unsigned() *= value2;
    return *this;
}
Number::dword Number::dword::operator*=(dword _dword2)
{
    this->reference_unsigned() *= _dword2.value_unsigned();
    return *this;
}

Number::dword Number::dword::operator/=(i32 value2)
{
    this->reference_signed() /= (i32)value2;
    return *this;
}
Number::dword Number::dword::operator/=(u32 value2)
{
    this->reference_unsigned() /= value2;
    return *this;
}
Number::dword Number::dword::operator/=(dword _dword2)
{
    this->reference_unsigned() /= _dword2.value_unsigned();
    return *this;
}
Number::dword Number::dword::operator%=(i32 value2)
{
    this->reference_signed() %= value2;
    return *this;
}
Number::dword Number::dword::operator%=(u32 value2)
{
    this->reference_unsigned() %= value2;
    return *this;
}
Number::dword Number::dword::operator%=(dword _dword2)
{
    this->reference_unsigned() %= _dword2.value_unsigned();
    return *this;
}
Number::dword Number::dword::operator&=(u32 value2)
{
    this->reference_unsigned() &= value2;
    return *this;
}
Number::dword Number::dword::operator&=(dword _dword2)
{
    this->reference_unsigned() &= _dword2.value_unsigned();
    return *this;
}

Number::dword Number::dword::operator|=(u32 value2)
{
    this->reference_unsigned() |= value2;
    return *this;
}
Number::dword Number::dword::operator|=(dword _dword2)
{
    this->reference_unsigned() |= _dword2.value_unsigned();
    return *this;
}

Number::dword Number::dword::operator^=(u32 value2)
{
    this->reference_unsigned() ^= value2;
    return *this;
}
Number::dword Number::dword::operator^=(dword _dword2)
{
    this->reference_unsigned() ^= _dword2.value_unsigned();
    return *this;
}

bool Number::dword::operator==(Number::dword v)
{
    return value_unsigned() == v.value_unsigned();
}
bool Number::dword::operator==(u32 v)
{
    return value_unsigned() == v;
}
bool Number::dword::operator==(i32 v)
{
    return value_signed() == v;
}
bool Number::dword::operator!=(Number::dword v)
{
    return value_unsigned() != v.value_unsigned();
}
bool Number::dword::operator!=(u32 v)
{
    return value_unsigned() != v;
}
bool Number::dword::operator!=(i32 v)
{
    return value_signed() != v;
}
bool Number::dword::operator<(Number::dword v)
{
    return value_unsigned() < v.value_unsigned();
}
bool Number::dword::operator<(u32 v)
{
    return value_unsigned() < v;
}
bool Number::dword::operator<(i32 v)
{
    return value_signed() < v;
}
bool Number::dword::operator>(Number::dword v)
{
    return value_unsigned() > v.value_unsigned();
}
bool Number::dword::operator>(u32 v)
{
    return value_unsigned() > v;
}
bool Number::dword::operator>(i32 v)
{
    return value_signed() > v;
}
bool Number::dword::operator>=(Number::dword v)
{
    return value_unsigned() >= v.value_unsigned();
}
bool Number::dword::operator>=(u32 v)
{
    return value_unsigned() >= v;
}
bool Number::dword::operator>=(i32 v)
{
    return value_signed() >= v;
}
bool Number::dword::operator<=(Number::dword v)
{
    return value_unsigned() <= v.value_unsigned();
}
bool Number::dword::operator<=(u32 v)
{
    return value_unsigned() <= v;
}
bool Number::dword::operator<=(i32 v)
{
    return value_signed() <= v;
}
bool Number::dword::operator&&(Number::dword v)
{
    return value_unsigned() && v.value_unsigned();
}
bool Number::dword::operator&&(u32 v)
{
    return value_unsigned() && v;
}
bool Number::dword::operator&&(i32 v)
{
    return value_signed() && v;
}
bool Number::dword::operator||(Number::dword v)
{
    return value_unsigned() || v.value_unsigned();
}
bool Number::dword::operator||(u32 v)
{
    return value_unsigned() || v;
}
bool Number::dword::operator||(i32 v)
{
    return value_signed() || v;
}
bool Number::dword::operator!()
{
    return !value_signed();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
Number::dword Number::dword::operator++()
{
    return ++(this->reference_unsigned());
}
Number::dword Number::dword::operator--()
{
    return --(this->reference_unsigned());
}
Number::dword Number::dword::operator++(int)
{
    return this->reference_unsigned()++;
}
Number::dword Number::dword::operator--(int)
{
    return this->reference_unsigned()--;
}

Number::qword Number::qword::operator+=(int value2)
{
    this->reference_signed() += (i64)value2;
    return *this;
}
Number::qword Number::qword::operator+=(i64 value2)
{
    this->reference_signed() += value2;
    return *this;
}
Number::qword Number::qword::operator+=(u64 value2)
{
    this->reference_unsigned() += value2;
    return *this;
}
Number::qword Number::qword::operator+=(qword _dword2)
{
    this->reference_unsigned() += _dword2.value_unsigned();
    return *this;
}
Number::qword Number::qword::operator-=(int value2)
{
    this->reference_signed() -= (i64)value2;
    return *this;
}
Number::qword Number::qword::operator-=(i64 value2)
{
    this->reference_signed() -= value2;
    return *this;
}
Number::qword Number::qword::operator-=(u64 value2)
{
    this->reference_unsigned() -= value2;
    return *this;
}
Number::qword Number::qword::operator-=(qword _dword2)
{
    this->reference_unsigned() -= _dword2.value_unsigned();
    return *this;
}
Number::qword Number::qword::operator*=(int value2)
{
    this->reference_signed() *= (i64)value2;
    return *this;
}
Number::qword Number::qword::operator*=(i64 value2)
{
    this->reference_signed() *= value2;
    return *this;
}
Number::qword Number::qword::operator*=(u64 value2)
{
    this->reference_unsigned() *= value2;
    return *this;
}
Number::qword Number::qword::operator*=(qword _dword2)
{
    this->reference_unsigned() *= _dword2.value_unsigned();
    return *this;
}

Number::qword Number::qword::operator/=(int value2)
{
    this->reference_signed() /= (i64)value2;
    return *this;
}
Number::qword Number::qword::operator/=(i64 value2)
{
    this->reference_signed() /= value2;
    return *this;
}
Number::qword Number::qword::operator/=(u64 value2)
{
    this->reference_unsigned() /= value2;
    return *this;
}
Number::qword Number::qword::operator/=(qword _dword2)
{
    this->reference_unsigned() /= _dword2.value_unsigned();
    return *this;
}

Number::qword Number::qword::operator%=(int value2)
{
    this->reference_signed() %= (i64)value2;
    return *this;
}
Number::qword Number::qword::operator%=(i64 value2)
{
    this->reference_signed() %= value2;
    return *this;
}
Number::qword Number::qword::operator%=(u64 value2)
{
    this->reference_unsigned() %= value2;
    return *this;
}
Number::qword Number::qword::operator%=(qword _dword2)
{
    this->reference_unsigned() %= _dword2.value_unsigned();
    return *this;
}
Number::qword Number::qword::operator&=(u64 value2)
{
    this->reference_unsigned() &= value2;
    return *this;
}
Number::qword Number::qword::operator&=(qword _dword2)
{
    this->reference_unsigned() &= _dword2.value_unsigned();
    return *this;
}

Number::qword Number::qword::operator|=(u64 value2)
{
    this->reference_unsigned() |= value2;
    return *this;
}
Number::qword Number::qword::operator|=(qword _dword2)
{
    this->reference_unsigned() |= _dword2.value_unsigned();
    return *this;
}

Number::qword Number::qword::operator^=(u64 value2)
{
    this->reference_unsigned() ^= value2;
    return *this;
}
Number::qword Number::qword::operator^=(qword _dword2)
{
    this->reference_unsigned() ^= _dword2.value_unsigned();
    return *this;
}

bool Number::qword::operator==(Number::qword v)
{
    return value_unsigned() == v.value_unsigned();
}
bool Number::qword::operator==(u64 v)
{
    return value_unsigned() == v;
}
bool Number::qword::operator==(i64 v)
{
    return value_signed() == v;
}
bool Number::qword::operator==(int v)
{
    return value_signed() == (i64)v;
}
bool Number::qword::operator!=(Number::qword v)
{
    return value_unsigned() != v.value_unsigned();
}
bool Number::qword::operator!=(u64 v)
{
    return value_unsigned() != v;
}
bool Number::qword::operator!=(i64 v)
{
    return value_signed() != v;
}
bool Number::qword::operator!=(int v)
{
    return value_signed() != (i64)v;
}
bool Number::qword::operator<(Number::qword v)
{
    return value_unsigned() < v.value_unsigned();
}
bool Number::qword::operator<(u64 v)
{
    return value_unsigned() < v;
}
bool Number::qword::operator<(i64 v)
{
    return value_signed() < v;
}
bool Number::qword::operator<(int v)
{
    return value_signed() < (i64)v;
}
bool Number::qword::operator>(Number::qword v)
{
    return value_unsigned() > v.value_unsigned();
}
bool Number::qword::operator>(u64 v)
{
    return value_unsigned() > v;
}
bool Number::qword::operator>(i64 v)
{
    return value_signed() > v;
}
bool Number::qword::operator>(int v)
{
    return value_signed() > (i64)v;
}
bool Number::qword::operator>=(Number::qword v)
{
    return value_unsigned() >= v.value_unsigned();
}
bool Number::qword::operator>=(u64 v)
{
    return value_unsigned() >= v;
}
bool Number::qword::operator>=(i64 v)
{
    return value_signed() >= v;
}
bool Number::qword::operator>=(int v)
{
    return value_signed() >= (i64)v;
}
bool Number::qword::operator<=(Number::qword v)
{
    return value_unsigned() <= v.value_unsigned();
}
bool Number::qword::operator<=(u64 v)
{
    return value_unsigned() <= v;
}
bool Number::qword::operator<=(i64 v)
{
    return value_signed() <= v;
}
bool Number::qword::operator<=(int v)
{
    return value_signed() <= (i64)v;
}
bool Number::qword::operator&&(Number::qword v)
{
    return value_unsigned() && v.value_unsigned();
}
bool Number::qword::operator&&(u64 v)
{
    return value_unsigned() && v;
}
bool Number::qword::operator&&(i64 v)
{
    return value_signed() && v;
}
bool Number::qword::operator&&(int v)
{
    return value_signed() && (i64)v;
}
bool Number::qword::operator||(Number::qword v)
{
    return value_unsigned() || v.value_unsigned();
}
bool Number::qword::operator||(u64 v)
{
    return value_unsigned() || v;
}
bool Number::qword::operator||(i64 v)
{
    return value_signed() || v;
}
bool Number::qword::operator||(int v)
{
    return value_signed() || (i64)v;
}
bool Number::qword::operator!()
{
    return !value_signed();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
Number::qword Number::qword::operator++()
{
    return ++(this->reference_unsigned());
}
Number::qword Number::qword::operator--()
{
    return --(this->reference_unsigned());
}
Number::qword Number::qword::operator++(int)
{
    return this->reference_unsigned()++;
}
Number::qword Number::qword::operator--(int)
{
    return this->reference_unsigned()--;
}