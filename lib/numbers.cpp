#include <stda/standart/numbers.hpp>

stringbuffer numbers::Binary::operator<<(u8 __value)
{
    return Binary::binary<u8>(__value);
}
stringbuffer numbers::Binary::operator<<(i8 __value)
{
    return Binary::binary<u8>(__value);
}
stringbuffer numbers::Binary::operator<<(byte __value)
{
    return Binary::binary<u8>(__value.value_unsigned());
}
stringbuffer numbers::Binary::operator<<(u16 __value)
{
    return Binary::binary<u16>(__value);
}
stringbuffer numbers::Binary::operator<<(i16 __value)
{
    return Binary::binary<u16>(__value);
}
stringbuffer numbers::Binary::operator<<(word __value)
{
    return Binary::binary<u16>(__value.value_unsigned());
}
stringbuffer numbers::Binary::operator<<(u32 __value)
{
    return Binary::binary<u32>(__value);
}
stringbuffer numbers::Binary::operator<<(i32 __value)
{
    return Binary::binary<u32>(__value);
}
stringbuffer numbers::Binary::operator<<(dword __value)
{
    return Binary::binary<u32>(__value.value_unsigned());
}
stringbuffer numbers::Binary::operator<<(u64 __value)
{
    return Binary::binary<u64>(__value);
}
stringbuffer numbers::Binary::operator<<(i64 __value)
{
    return Binary::binary<u64>(__value);
}
stringbuffer numbers::Binary::operator<<(numbers::qword __value)
{
    return Binary::binary<u64>(__value.value_unsigned());
}

stringbuffer numbers::Hexadecimal::operator<<(u8 __value)
{
    return Hexadecimal::hexadecimal<u8>(__value);
}
stringbuffer numbers::Hexadecimal::operator<<(i8 __value)
{
    return Hexadecimal::hexadecimal<u8>(__value);
}
stringbuffer numbers::Hexadecimal::operator<<(byte __value)
{
    return Hexadecimal::hexadecimal<u8>(__value.value_unsigned());
}
stringbuffer numbers::Hexadecimal::operator<<(u16 __value)
{
    return Hexadecimal::hexadecimal<u16>(__value);
}
stringbuffer numbers::Hexadecimal::operator<<(i16 __value)
{
    return Hexadecimal::hexadecimal<u16>(__value);
}
stringbuffer numbers::Hexadecimal::operator<<(word __value)
{
    return Hexadecimal::hexadecimal<u16>(__value.value_unsigned());
}
stringbuffer numbers::Hexadecimal::operator<<(u32 __value)
{
    return Hexadecimal::hexadecimal<u32>(__value);
}
stringbuffer numbers::Hexadecimal::operator<<(i32 __value)
{
    return Hexadecimal::hexadecimal<u32>(__value);
}
stringbuffer numbers::Hexadecimal::operator<<(dword __value)
{
    return Hexadecimal::hexadecimal<u32>(__value.value_unsigned());
}
stringbuffer numbers::Hexadecimal::operator<<(u64 __value)
{
    return Hexadecimal::hexadecimal<u64>(__value);
}
stringbuffer numbers::Hexadecimal::operator<<(i64 __value)
{
    return Hexadecimal::hexadecimal<u64>(__value);
}
stringbuffer numbers::Hexadecimal::operator<<(qword __value)
{
    return Hexadecimal::hexadecimal<u64>(__value.value_unsigned());
}

template <>
f32 numbers::limits<f32>::min()
{
    return 10e-46;
}
template <>
f32 numbers::limits<f32>::max()
{
    return 10e38;
}
template <>
f64 numbers::limits<f64>::min()
{
    return 10e-324;
}
template <>
f64 numbers::limits<f64>::max()
{
    return 10e307;
}

numbers::byte numbers::byte::operator+=(int value2)
{
    this->reference_signed() += (i8)value2;
    return *this;
}
numbers::byte numbers::byte::operator+=(i8 value2)
{
    this->reference_signed() += value2;
    return *this;
}
numbers::byte numbers::byte::operator+=(u8 value2)
{
    this->reference_unsigned() += value2;
    return *this;
}
numbers::byte numbers::byte::operator+=(byte _dword2)
{
    this->reference_unsigned() += _dword2.value_unsigned();
    return *this;
}
numbers::byte numbers::byte::operator-=(int value2)
{
    this->reference_signed() -= (i8)value2;
    return *this;
}
numbers::byte numbers::byte::operator-=(i8 value2)
{
    this->reference_signed() -= value2;
    return *this;
}
numbers::byte numbers::byte::operator-=(u8 value2)
{
    this->reference_unsigned() -= value2;
    return *this;
}
numbers::byte numbers::byte::operator-=(byte _dword2)
{
    this->reference_unsigned() -= _dword2.value_unsigned();
    return *this;
}
numbers::byte numbers::byte::operator*=(int value2)
{
    this->reference_signed() *= (i8)value2;
    return *this;
}
numbers::byte numbers::byte::operator*=(i8 value2)
{
    this->reference_signed() *= value2;
    return *this;
}
numbers::byte numbers::byte::operator*=(u8 value2)
{
    this->reference_unsigned() *= value2;
    return *this;
}
numbers::byte numbers::byte::operator*=(byte _dword2)
{
    this->reference_unsigned() *= _dword2.value_unsigned();
    return *this;
}

numbers::byte numbers::byte::operator/=(int value2)
{
    this->reference_signed() /= (i8)value2;
    return *this;
}
numbers::byte numbers::byte::operator/=(i8 value2)
{
    this->reference_signed() /= value2;
    return *this;
}
numbers::byte numbers::byte::operator/=(u8 value2)
{
    this->reference_unsigned() /= value2;
    return *this;
}
numbers::byte numbers::byte::operator/=(byte _dword2)
{
    this->reference_unsigned() /= _dword2.value_unsigned();
    return *this;
}

numbers::byte numbers::byte::operator%=(int value2)
{
    this->reference_signed() %= (i8)value2;
    return *this;
}
numbers::byte numbers::byte::operator%=(i8 value2)
{
    this->reference_signed() %= value2;
    return *this;
}
numbers::byte numbers::byte::operator%=(u8 value2)
{
    this->reference_unsigned() %= value2;
    return *this;
}
numbers::byte numbers::byte::operator%=(byte _dword2)
{
    this->reference_unsigned() %= _dword2.value_unsigned();
    return *this;
}
numbers::byte numbers::byte::operator&=(u8 value2)
{
    this->reference_unsigned() &= value2;
    return *this;
}
numbers::byte numbers::byte::operator&=(byte _dword2)
{
    this->reference_unsigned() &= _dword2.value_unsigned();
    return *this;
}

numbers::byte numbers::byte::operator|=(u8 value2)
{
    this->reference_unsigned() |= value2;
    return *this;
}
numbers::byte numbers::byte::operator|=(byte _dword2)
{
    this->reference_unsigned() |= _dword2.value_unsigned();
    return *this;
}

numbers::byte numbers::byte::operator^=(u8 value2)
{
    this->reference_unsigned() ^= value2;
    return *this;
}
numbers::byte numbers::byte::operator^=(byte _dword2)
{
    this->reference_unsigned() ^= _dword2.value_unsigned();
    return *this;
}

bool numbers::byte::operator==(numbers::byte v)
{
    return value_unsigned() == v.value_unsigned();
}
bool numbers::byte::operator==(u8 v)
{
    return value_unsigned() == v;
}
bool numbers::byte::operator==(i8 v)
{
    return value_signed() == v;
}
bool numbers::byte::operator==(int v)
{
    return value_signed() == (i8)v;
}
bool numbers::byte::operator!=(numbers::byte v)
{
    return value_unsigned() != v.value_unsigned();
}
bool numbers::byte::operator!=(u8 v)
{
    return value_unsigned() != v;
}
bool numbers::byte::operator!=(i8 v)
{
    return value_signed() != v;
}
bool numbers::byte::operator!=(int v)
{
    return value_signed() != (i8)v;
}
bool numbers::byte::operator<(numbers::byte v)
{
    return value_unsigned() < v.value_unsigned();
}
bool numbers::byte::operator<(u8 v)
{
    return value_unsigned() < v;
}
bool numbers::byte::operator<(i8 v)
{
    return value_signed() < v;
}
bool numbers::byte::operator<(int v)
{
    return value_signed() < (i8)v;
}
bool numbers::byte::operator>(numbers::byte v)
{
    return value_unsigned() > v.value_unsigned();
}
bool numbers::byte::operator>(u8 v)
{
    return value_unsigned() > v;
}
bool numbers::byte::operator>(i8 v)
{
    return value_signed() > v;
}
bool numbers::byte::operator>(int v)
{
    return value_signed() > (i8)v;
}
bool numbers::byte::operator>=(numbers::byte v)
{
    return value_unsigned() >= v.value_unsigned();
}
bool numbers::byte::operator>=(u8 v)
{
    return value_unsigned() >= v;
}
bool numbers::byte::operator>=(i8 v)
{
    return value_signed() >= v;
}
bool numbers::byte::operator>=(int v)
{
    return value_signed() >= (i8)v;
}
bool numbers::byte::operator<=(numbers::byte v)
{
    return value_unsigned() <= v.value_unsigned();
}
bool numbers::byte::operator<=(u8 v)
{
    return value_unsigned() <= v;
}
bool numbers::byte::operator<=(i8 v)
{
    return value_signed() <= v;
}
bool numbers::byte::operator<=(int v)
{
    return value_signed() <= (i8)v;
}
bool numbers::byte::operator&&(numbers::byte v)
{
    return value_unsigned() && v.value_unsigned();
}
bool numbers::byte::operator&&(u8 v)
{
    return value_unsigned() && v;
}
bool numbers::byte::operator&&(i8 v)
{
    return value_signed() && v;
}
bool numbers::byte::operator&&(int v)
{
    return value_signed() && (i8)v;
}
bool numbers::byte::operator||(numbers::byte v)
{
    return value_unsigned() || v.value_unsigned();
}
bool numbers::byte::operator||(u8 v)
{
    return value_unsigned() || v;
}
bool numbers::byte::operator||(i8 v)
{
    return value_signed() || v;
}
bool numbers::byte::operator||(int v)
{
    return value_signed() || (i8)v;
}
bool numbers::byte::operator!()
{
    return !value_signed();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
numbers::byte numbers::byte::operator++()
{
    return ++(this->reference_unsigned());
}
numbers::byte numbers::byte::operator--()
{
    return --(this->reference_unsigned());
}
numbers::byte numbers::byte::operator++(int)
{
    return this->reference_unsigned()++;
}
numbers::byte numbers::byte::operator--(int)
{
    return this->reference_unsigned()--;
}

numbers::word numbers::word::operator+=(int value2)
{
    this->reference_signed() += (i16)value2;
    return *this;
}
numbers::word numbers::word::operator+=(i16 value2)
{
    this->reference_signed() += value2;
    return *this;
}
numbers::word numbers::word::operator+=(u16 value2)
{
    this->reference_unsigned() += value2;
    return *this;
}
numbers::word numbers::word::operator+=(word _dword2)
{
    this->reference_unsigned() += _dword2.value_unsigned();
    return *this;
}
numbers::word numbers::word::operator-=(int value2)
{
    this->reference_signed() -= (i16)value2;
    return *this;
}
numbers::word numbers::word::operator-=(i16 value2)
{
    this->reference_signed() -= value2;
    return *this;
}
numbers::word numbers::word::operator-=(u16 value2)
{
    this->reference_unsigned() -= value2;
    return *this;
}
numbers::word numbers::word::operator-=(word _dword2)
{
    this->reference_unsigned() -= _dword2.value_unsigned();
    return *this;
}
numbers::word numbers::word::operator*=(int value2)
{
    this->reference_signed() *= (i16)value2;
    return *this;
}
numbers::word numbers::word::operator*=(i16 value2)
{
    this->reference_signed() *= value2;
    return *this;
}
numbers::word numbers::word::operator*=(u16 value2)
{
    this->reference_unsigned() *= value2;
    return *this;
}
numbers::word numbers::word::operator*=(word _dword2)
{
    this->reference_unsigned() *= _dword2.value_unsigned();
    return *this;
}

numbers::word numbers::word::operator/=(int value2)
{
    this->reference_signed() /= (i16)value2;
    return *this;
}
numbers::word numbers::word::operator/=(i16 value2)
{
    this->reference_signed() /= value2;
    return *this;
}
numbers::word numbers::word::operator/=(u16 value2)
{
    this->reference_unsigned() /= value2;
    return *this;
}
numbers::word numbers::word::operator/=(word _dword2)
{
    this->reference_unsigned() /= _dword2.value_unsigned();
    return *this;
}

numbers::word numbers::word::operator%=(int value2)
{
    this->reference_signed() %= (i16)value2;
    return *this;
}
numbers::word numbers::word::operator%=(i16 value2)
{
    this->reference_signed() %= value2;
    return *this;
}
numbers::word numbers::word::operator%=(u16 value2)
{
    this->reference_unsigned() %= value2;
    return *this;
}
numbers::word numbers::word::operator%=(word _dword2)
{
    this->reference_unsigned() %= _dword2.value_unsigned();
    return *this;
}
numbers::word numbers::word::operator&=(u16 value2)
{
    this->reference_unsigned() &= value2;
    return *this;
}
numbers::word numbers::word::operator&=(word _dword2)
{
    this->reference_unsigned() &= _dword2.value_unsigned();
    return *this;
}

numbers::word numbers::word::operator|=(u16 value2)
{
    this->reference_unsigned() |= value2;
    return *this;
}
numbers::word numbers::word::operator|=(word _dword2)
{
    this->reference_unsigned() |= _dword2.value_unsigned();
    return *this;
}

numbers::word numbers::word::operator^=(u16 value2)
{
    this->reference_unsigned() ^= value2;
    return *this;
}
numbers::word numbers::word::operator^=(word _dword2)
{
    this->reference_unsigned() ^= _dword2.value_unsigned();
    return *this;
}

bool numbers::word::operator==(numbers::word v)
{
    return value_unsigned() == v.value_unsigned();
}
bool numbers::word::operator==(u16 v)
{
    return value_unsigned() == v;
}
bool numbers::word::operator==(i16 v)
{
    return value_signed() == v;
}
bool numbers::word::operator==(int v)
{
    return value_signed() == (i16)v;
}
bool numbers::word::operator!=(numbers::word v)
{
    return value_unsigned() != v.value_unsigned();
}
bool numbers::word::operator!=(u16 v)
{
    return value_unsigned() != v;
}
bool numbers::word::operator!=(i16 v)
{
    return value_signed() != v;
}
bool numbers::word::operator!=(int v)
{
    return value_signed() != (i16)v;
}
bool numbers::word::operator<(numbers::word v)
{
    return value_unsigned() < v.value_unsigned();
}
bool numbers::word::operator<(u16 v)
{
    return value_unsigned() < v;
}
bool numbers::word::operator<(i16 v)
{
    return value_signed() < v;
}
bool numbers::word::operator<(int v)
{
    return value_signed() < (i16)v;
}
bool numbers::word::operator>(numbers::word v)
{
    return value_unsigned() > v.value_unsigned();
}
bool numbers::word::operator>(u16 v)
{
    return value_unsigned() > v;
}
bool numbers::word::operator>(i16 v)
{
    return value_signed() > v;
}
bool numbers::word::operator>(int v)
{
    return value_signed() > (i16)v;
}
bool numbers::word::operator>=(numbers::word v)
{
    return value_unsigned() >= v.value_unsigned();
}
bool numbers::word::operator>=(u16 v)
{
    return value_unsigned() >= v;
}
bool numbers::word::operator>=(i16 v)
{
    return value_signed() >= v;
}
bool numbers::word::operator>=(int v)
{
    return value_signed() >= (i16)v;
}
bool numbers::word::operator<=(numbers::word v)
{
    return value_unsigned() <= v.value_unsigned();
}
bool numbers::word::operator<=(u16 v)
{
    return value_unsigned() <= v;
}
bool numbers::word::operator<=(i16 v)
{
    return value_signed() <= v;
}
bool numbers::word::operator<=(int v)
{
    return value_signed() <= (i16)v;
}
bool numbers::word::operator&&(numbers::word v)
{
    return value_unsigned() && v.value_unsigned();
}
bool numbers::word::operator&&(u16 v)
{
    return value_unsigned() && v;
}
bool numbers::word::operator&&(i16 v)
{
    return value_signed() && v;
}
bool numbers::word::operator&&(int v)
{
    return value_signed() && (i16)v;
}
bool numbers::word::operator||(numbers::word v)
{
    return value_unsigned() || v.value_unsigned();
}
bool numbers::word::operator||(u16 v)
{
    return value_unsigned() || v;
}
bool numbers::word::operator||(i16 v)
{
    return value_signed() || v;
}
bool numbers::word::operator||(int v)
{
    return value_signed() || (i16)v;
}
bool numbers::word::operator!()
{
    return !value_signed();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
numbers::word numbers::word::operator++()
{
    return ++(this->reference_unsigned());
}
numbers::word numbers::word::operator--()
{
    return --(this->reference_unsigned());
}
numbers::word numbers::word::operator++(int)
{
    return this->reference_unsigned()++;
}
numbers::word numbers::word::operator--(int)
{
    return this->reference_unsigned()--;
}

numbers::dword numbers::dword::operator+=(i32 value2)
{
    this->reference_signed() += (i32)value2;
    return *this;
}
numbers::dword numbers::dword::operator+=(u32 value2)
{
    this->reference_unsigned() += value2;
    return *this;
}
numbers::dword numbers::dword::operator+=(dword _dword2)
{
    this->reference_unsigned() += _dword2.value_unsigned();
    return *this;
}
numbers::dword numbers::dword::operator-=(i32 value2)
{
    this->reference_signed() -= (i32)value2;
    return *this;
}
numbers::dword numbers::dword::operator-=(u32 value2)
{
    this->reference_unsigned() -= value2;
    return *this;
}
numbers::dword numbers::dword::operator-=(dword _dword2)
{
    this->reference_unsigned() -= _dword2.value_unsigned();
    return *this;
}
numbers::dword numbers::dword::operator*=(i32 value2)
{
    this->reference_signed() *= (i32)value2;
    return *this;
}
numbers::dword numbers::dword::operator*=(u32 value2)
{
    this->reference_unsigned() *= value2;
    return *this;
}
numbers::dword numbers::dword::operator*=(dword _dword2)
{
    this->reference_unsigned() *= _dword2.value_unsigned();
    return *this;
}

numbers::dword numbers::dword::operator/=(i32 value2)
{
    this->reference_signed() /= (i32)value2;
    return *this;
}
numbers::dword numbers::dword::operator/=(u32 value2)
{
    this->reference_unsigned() /= value2;
    return *this;
}
numbers::dword numbers::dword::operator/=(dword _dword2)
{
    this->reference_unsigned() /= _dword2.value_unsigned();
    return *this;
}
numbers::dword numbers::dword::operator%=(i32 value2)
{
    this->reference_signed() %= value2;
    return *this;
}
numbers::dword numbers::dword::operator%=(u32 value2)
{
    this->reference_unsigned() %= value2;
    return *this;
}
numbers::dword numbers::dword::operator%=(dword _dword2)
{
    this->reference_unsigned() %= _dword2.value_unsigned();
    return *this;
}
numbers::dword numbers::dword::operator&=(u32 value2)
{
    this->reference_unsigned() &= value2;
    return *this;
}
numbers::dword numbers::dword::operator&=(dword _dword2)
{
    this->reference_unsigned() &= _dword2.value_unsigned();
    return *this;
}

numbers::dword numbers::dword::operator|=(u32 value2)
{
    this->reference_unsigned() |= value2;
    return *this;
}
numbers::dword numbers::dword::operator|=(dword _dword2)
{
    this->reference_unsigned() |= _dword2.value_unsigned();
    return *this;
}

numbers::dword numbers::dword::operator^=(u32 value2)
{
    this->reference_unsigned() ^= value2;
    return *this;
}
numbers::dword numbers::dword::operator^=(dword _dword2)
{
    this->reference_unsigned() ^= _dword2.value_unsigned();
    return *this;
}

bool numbers::dword::operator==(numbers::dword v)
{
    return value_unsigned() == v.value_unsigned();
}
bool numbers::dword::operator==(u32 v)
{
    return value_unsigned() == v;
}
bool numbers::dword::operator==(i32 v)
{
    return value_signed() == v;
}
bool numbers::dword::operator!=(numbers::dword v)
{
    return value_unsigned() != v.value_unsigned();
}
bool numbers::dword::operator!=(u32 v)
{
    return value_unsigned() != v;
}
bool numbers::dword::operator!=(i32 v)
{
    return value_signed() != v;
}
bool numbers::dword::operator<(numbers::dword v)
{
    return value_unsigned() < v.value_unsigned();
}
bool numbers::dword::operator<(u32 v)
{
    return value_unsigned() < v;
}
bool numbers::dword::operator<(i32 v)
{
    return value_signed() < v;
}
bool numbers::dword::operator>(numbers::dword v)
{
    return value_unsigned() > v.value_unsigned();
}
bool numbers::dword::operator>(u32 v)
{
    return value_unsigned() > v;
}
bool numbers::dword::operator>(i32 v)
{
    return value_signed() > v;
}
bool numbers::dword::operator>=(numbers::dword v)
{
    return value_unsigned() >= v.value_unsigned();
}
bool numbers::dword::operator>=(u32 v)
{
    return value_unsigned() >= v;
}
bool numbers::dword::operator>=(i32 v)
{
    return value_signed() >= v;
}
bool numbers::dword::operator<=(numbers::dword v)
{
    return value_unsigned() <= v.value_unsigned();
}
bool numbers::dword::operator<=(u32 v)
{
    return value_unsigned() <= v;
}
bool numbers::dword::operator<=(i32 v)
{
    return value_signed() <= v;
}
bool numbers::dword::operator&&(numbers::dword v)
{
    return value_unsigned() && v.value_unsigned();
}
bool numbers::dword::operator&&(u32 v)
{
    return value_unsigned() && v;
}
bool numbers::dword::operator&&(i32 v)
{
    return value_signed() && v;
}
bool numbers::dword::operator||(numbers::dword v)
{
    return value_unsigned() || v.value_unsigned();
}
bool numbers::dword::operator||(u32 v)
{
    return value_unsigned() || v;
}
bool numbers::dword::operator||(i32 v)
{
    return value_signed() || v;
}
bool numbers::dword::operator!()
{
    return !value_signed();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
numbers::dword numbers::dword::operator++()
{
    return ++(this->reference_unsigned());
}
numbers::dword numbers::dword::operator--()
{
    return --(this->reference_unsigned());
}
numbers::dword numbers::dword::operator++(int)
{
    return this->reference_unsigned()++;
}
numbers::dword numbers::dword::operator--(int)
{
    return this->reference_unsigned()--;
}

numbers::qword numbers::qword::operator+=(int value2)
{
    this->reference_signed() += (i64)value2;
    return *this;
}
numbers::qword numbers::qword::operator+=(i64 value2)
{
    this->reference_signed() += value2;
    return *this;
}
numbers::qword numbers::qword::operator+=(u64 value2)
{
    this->reference_unsigned() += value2;
    return *this;
}
numbers::qword numbers::qword::operator+=(qword _dword2)
{
    this->reference_unsigned() += _dword2.value_unsigned();
    return *this;
}
numbers::qword numbers::qword::operator-=(int value2)
{
    this->reference_signed() -= (i64)value2;
    return *this;
}
numbers::qword numbers::qword::operator-=(i64 value2)
{
    this->reference_signed() -= value2;
    return *this;
}
numbers::qword numbers::qword::operator-=(u64 value2)
{
    this->reference_unsigned() -= value2;
    return *this;
}
numbers::qword numbers::qword::operator-=(qword _dword2)
{
    this->reference_unsigned() -= _dword2.value_unsigned();
    return *this;
}
numbers::qword numbers::qword::operator*=(int value2)
{
    this->reference_signed() *= (i64)value2;
    return *this;
}
numbers::qword numbers::qword::operator*=(i64 value2)
{
    this->reference_signed() *= value2;
    return *this;
}
numbers::qword numbers::qword::operator*=(u64 value2)
{
    this->reference_unsigned() *= value2;
    return *this;
}
numbers::qword numbers::qword::operator*=(qword _dword2)
{
    this->reference_unsigned() *= _dword2.value_unsigned();
    return *this;
}

numbers::qword numbers::qword::operator/=(int value2)
{
    this->reference_signed() /= (i64)value2;
    return *this;
}
numbers::qword numbers::qword::operator/=(i64 value2)
{
    this->reference_signed() /= value2;
    return *this;
}
numbers::qword numbers::qword::operator/=(u64 value2)
{
    this->reference_unsigned() /= value2;
    return *this;
}
numbers::qword numbers::qword::operator/=(qword _dword2)
{
    this->reference_unsigned() /= _dword2.value_unsigned();
    return *this;
}

numbers::qword numbers::qword::operator%=(int value2)
{
    this->reference_signed() %= (i64)value2;
    return *this;
}
numbers::qword numbers::qword::operator%=(i64 value2)
{
    this->reference_signed() %= value2;
    return *this;
}
numbers::qword numbers::qword::operator%=(u64 value2)
{
    this->reference_unsigned() %= value2;
    return *this;
}
numbers::qword numbers::qword::operator%=(qword _dword2)
{
    this->reference_unsigned() %= _dword2.value_unsigned();
    return *this;
}
numbers::qword numbers::qword::operator&=(u64 value2)
{
    this->reference_unsigned() &= value2;
    return *this;
}
numbers::qword numbers::qword::operator&=(qword _dword2)
{
    this->reference_unsigned() &= _dword2.value_unsigned();
    return *this;
}

numbers::qword numbers::qword::operator|=(u64 value2)
{
    this->reference_unsigned() |= value2;
    return *this;
}
numbers::qword numbers::qword::operator|=(qword _dword2)
{
    this->reference_unsigned() |= _dword2.value_unsigned();
    return *this;
}

numbers::qword numbers::qword::operator^=(u64 value2)
{
    this->reference_unsigned() ^= value2;
    return *this;
}
numbers::qword numbers::qword::operator^=(qword _dword2)
{
    this->reference_unsigned() ^= _dword2.value_unsigned();
    return *this;
}

bool numbers::qword::operator==(numbers::qword v)
{
    return value_unsigned() == v.value_unsigned();
}
bool numbers::qword::operator==(u64 v)
{
    return value_unsigned() == v;
}
bool numbers::qword::operator==(i64 v)
{
    return value_signed() == v;
}
bool numbers::qword::operator==(int v)
{
    return value_signed() == (i64)v;
}
bool numbers::qword::operator!=(numbers::qword v)
{
    return value_unsigned() != v.value_unsigned();
}
bool numbers::qword::operator!=(u64 v)
{
    return value_unsigned() != v;
}
bool numbers::qword::operator!=(i64 v)
{
    return value_signed() != v;
}
bool numbers::qword::operator!=(int v)
{
    return value_signed() != (i64)v;
}
bool numbers::qword::operator<(numbers::qword v)
{
    return value_unsigned() < v.value_unsigned();
}
bool numbers::qword::operator<(u64 v)
{
    return value_unsigned() < v;
}
bool numbers::qword::operator<(i64 v)
{
    return value_signed() < v;
}
bool numbers::qword::operator<(int v)
{
    return value_signed() < (i64)v;
}
bool numbers::qword::operator>(numbers::qword v)
{
    return value_unsigned() > v.value_unsigned();
}
bool numbers::qword::operator>(u64 v)
{
    return value_unsigned() > v;
}
bool numbers::qword::operator>(i64 v)
{
    return value_signed() > v;
}
bool numbers::qword::operator>(int v)
{
    return value_signed() > (i64)v;
}
bool numbers::qword::operator>=(numbers::qword v)
{
    return value_unsigned() >= v.value_unsigned();
}
bool numbers::qword::operator>=(u64 v)
{
    return value_unsigned() >= v;
}
bool numbers::qword::operator>=(i64 v)
{
    return value_signed() >= v;
}
bool numbers::qword::operator>=(int v)
{
    return value_signed() >= (i64)v;
}
bool numbers::qword::operator<=(numbers::qword v)
{
    return value_unsigned() <= v.value_unsigned();
}
bool numbers::qword::operator<=(u64 v)
{
    return value_unsigned() <= v;
}
bool numbers::qword::operator<=(i64 v)
{
    return value_signed() <= v;
}
bool numbers::qword::operator<=(int v)
{
    return value_signed() <= (i64)v;
}
bool numbers::qword::operator&&(numbers::qword v)
{
    return value_unsigned() && v.value_unsigned();
}
bool numbers::qword::operator&&(u64 v)
{
    return value_unsigned() && v;
}
bool numbers::qword::operator&&(i64 v)
{
    return value_signed() && v;
}
bool numbers::qword::operator&&(int v)
{
    return value_signed() && (i64)v;
}
bool numbers::qword::operator||(numbers::qword v)
{
    return value_unsigned() || v.value_unsigned();
}
bool numbers::qword::operator||(u64 v)
{
    return value_unsigned() || v;
}
bool numbers::qword::operator||(i64 v)
{
    return value_signed() || v;
}
bool numbers::qword::operator||(int v)
{
    return value_signed() || (i64)v;
}
bool numbers::qword::operator!()
{
    return !value_signed();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
numbers::qword numbers::qword::operator++()
{
    return ++(this->reference_unsigned());
}
numbers::qword numbers::qword::operator--()
{
    return --(this->reference_unsigned());
}
numbers::qword numbers::qword::operator++(int)
{
    return this->reference_unsigned()++;
}
numbers::qword numbers::qword::operator--(int)
{
    return this->reference_unsigned()--;
}