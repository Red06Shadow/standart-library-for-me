#include <iostream>
#include <stda/sstrings/stringbuffer.hpp>

#ifndef HEXADECIMALS
#define HEXADECIMALS

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

namespace numbers
{
    class byte
    {
    public:
        u8 value;
        byte(u8 data) : value(data) {}
        u8 number() { return value; }
        static u8 number(byte value) { return value.value; }
        u8 &numberref() { return value; }
        static u8 &numberref(byte &value) { return value.value; }
        static void getbits(u8 __v, bool *bit7 = nullptr, bool *bit6 = nullptr, bool *bit5 = nullptr, bool *bit4 = nullptr, bool *bit3 = nullptr, bool *bit2 = nullptr, bool *bit1 = nullptr, bool *bit0 = nullptr)
        {
            if (bit7)
                *bit7 = __v & (u8)(0b10000000);
            if (bit6)
                *bit6 = __v & (u8)(0b01000000);
            if (bit5)
                *bit5 = __v & (u8)(0b00100000);
            if (bit4)
                *bit4 = __v & (u8)(0b00010000);
            if (bit3)
                *bit3 = __v & (u8)(0b00001000);
            if (bit2)
                *bit2 = __v & (u8)(0b00000100);
            if (bit1)
                *bit1 = __v & (u8)(0b00000010);
            if (bit0)
                *bit0 = __v & (u8)(0b00000001);
        }
        friend byte operator+(byte _byte, byte _byte2) { return _byte.value + _byte2.value; }
        friend byte operator+(byte _byte, u8 value2) { return _byte.value + value2; }
        friend byte operator+(u8 value2, byte _byte) { return value2 + _byte.value; }
        byte operator+=(u8 value2)
        {
            this->value += value2;
            return *this;
        }
        byte operator+=(byte _byte2)
        {
            this->value += _byte2.value;
            return *this;
        }
        friend byte operator-(byte _byte, byte _byte2) { return _byte.value - _byte2.value; }
        friend byte operator-(byte _byte, u8 value2) { return _byte.value - value2; }
        friend byte operator-(u8 value2, byte _byte) { return value2 - _byte.value; }
        byte operator-=(u8 value2)
        {
            this->value -= value2;
            return *this;
        }
        byte operator-=(byte _byte2)
        {
            this->value -= _byte2.value;
            return *this;
        }
        friend byte operator*(byte _byte, byte _byte2) { return _byte.value * _byte2.value; }
        friend byte operator*(byte _byte, u8 value2) { return _byte.value * value2; }
        friend byte operator*(u8 value2, byte _byte) { return value2 * _byte.value; }
        byte operator*=(u8 value2)
        {
            this->value *= value2;
            return *this;
        }
        byte operator*=(byte _byte2)
        {
            this->value *= _byte2.value;
            return *this;
        }
        friend byte operator/(byte _byte, byte _byte2) { return _byte.value / _byte2.value; }
        friend byte operator/(byte _byte, u8 value2) { return _byte.value / value2; }
        friend byte operator/(u8 value2, byte _byte) { return value2 / _byte.value; }
        byte operator/=(u8 value2)
        {
            this->value /= value2;
            return *this;
        }
        byte operator/=(byte _byte2)
        {
            this->value /= _byte2.value;
            return *this;
        }
        friend byte operator%(byte _byte, byte _byte2) { return _byte.value % _byte2.value; }
        friend byte operator%(byte _byte, u8 value2) { return _byte.value % value2; }
        friend byte operator%(u8 value2, byte _byte) { return value2 % _byte.value; }
        byte operator%=(u8 value2)
        {
            this->value %= value2;
            return *this;
        }
        byte operator%=(byte _byte2)
        {
            this->value %= _byte2.value;
            return *this;
        }
        friend byte operator>>(byte _byte, u8 value2) { return _byte.value >> value2; }
        friend byte operator<<(byte _byte, u8 value2) { return _byte.value << value2; }
        friend std::ostream &operator<<(std::ostream &os, byte v)
        {
            os << v.value;
            return os;
        }
        byte operator++(int) {
            return value++;
        }
        byte operator--(int) {
            return value--;
        }
    };
    class word
    {
    public:
        byte low;
        byte higth;
        word(u16 value) : low((u8)(value)), higth(value / maxu8) {}
        word(u8 _low, u8 _higth) : low(_low), higth(_higth) {}
        word(byte _low, byte _higth) : low(_low), higth(_higth) {}
        u16 number() { return *(u16 *)(this); }
        static u16 number(word value) { return *(u16 *)(&value); }
        u16 &numberref() { return *(u16 *)(this); }
        ///////////////////////////////////////////////////////////
        static u16 union16(u8 _low, u8 _higth) {return (u16(_higth) << 8) + _higth;}
        ///////////////////////////////////////////////////////////
        static u16 &numberref(word &value) { return *(u16 *)(&value); }
        friend word operator+(word _short, word _short2) { return word::number(_short) + word::number(_short2); }
        friend word operator+(word _short, u16 value2) { return word::number(_short) + value2; }
        friend word operator+(u16 value2, word _short) { return value2 + word::number(_short); }
        word operator+=(u16 value2)
        {
            word::numberref(*this) += value2;
            return *this;
        }
        word operator+=(word _short2)
        {
            word::numberref(*this) += word::number(_short2);
            return *this;
        }
        friend word operator-(word _short, word _short2) { return word::number(_short) - word::number(_short2); }
        friend word operator-(word _short, u16 value2) { return word::number(_short) - value2; }
        friend word operator-(u16 value2, word _short) { return value2 - word::number(_short); }
        word operator-=(u16 value2)
        {
            word::numberref(*this) -= value2;
            return *this;
        }
        word operator-=(word _short2)
        {
            word::numberref(*this) -= word::number(_short2);
            return *this;
        }
        friend word operator*(word _short, word _short2) { return word::number(_short) * word::number(_short2); }
        friend word operator*(word _short, u16 value2) { return word::number(_short) * value2; }
        friend word operator*(u16 value2, word _short) { return value2 * word::number(_short); }
        word operator*=(u16 value2)
        {
            word::numberref(*this) *= value2;
            return *this;
        }
        word operator*=(word _short2)
        {
            word::numberref(*this) *= word::number(_short2);
            return *this;
        }
        friend word operator/(word _short, word _short2) { return word::number(_short) / word::number(_short2); }
        friend word operator/(word _short, u16 value2) { return word::number(_short) / value2; }
        friend word operator/(u16 value2, word _short) { return value2 / word::number(_short); }
        word operator/=(u16 value2)
        {
            word::numberref(*this) /= value2;
            return *this;
        }
        word operator/=(word _short2)
        {
            word::numberref(*this) /= word::number(_short2);
            return *this;
        }
        friend word operator%(word _short, word _short2) { return word::number(_short) % word::number(_short2); }
        friend word operator%(word _short, u16 value2) { return word::number(_short) % value2; }
        friend word operator%(u16 value2, word _short) { return value2 % word::number(_short); }
        word operator%=(u16 value2)
        {
            word::numberref(*this) %= value2;
            return *this;
        }
        word operator%=(word _short2)
        {
            word::numberref(*this) %= word::number(_short2);
            return *this;
        }
        friend word operator>>(word __short, u16 value2) { return word::number(__short) >> value2; }
        friend word operator<<(word __short, u16 value2) { return word::number(__short) << value2; }
        friend std::ostream &operator<<(std::ostream &os, word v)
        {
            os << word::number(v);
            return os;
        }
        word operator++(int) {
            return numbers::word(++(*(u16*)(this)));
        }
        word operator--(int) {
            return numbers::word(--(*(u16*)(this)));
        }
    };
    class dword
    {
    public:
        word low;
        word higth;
        dword(u32 value) : low(value), higth(value / maxu16) {}
        dword(f32 value) : low(*(u16 *)(&value)), higth((u16)(*(u32 *)(&value) / maxu16)) {}
        dword(u16 _low, u16 _higth) : low(_low), higth(_higth) {}
        dword(word _low, word _higth) : low(_low), higth(_higth) {}
        u32 number() { return *(u32 *)(this); }
        f32 fnumber() { return *(f32 *)(this); }
        static u32 number(dword value) { return *(u32 *)(&value); }
        u32 &numberref() { return *(u32 *)(this); }
        ///////////////////////////////////////////////////////////
        static u32 union32(u16 _low, u16 _higth) {return (u32(_higth) << 16) + _higth;}
        ///////////////////////////////////////////////////////////
        static u32 &numberref(dword &value) { return *(u32 *)(&value); }
        friend dword operator+(dword _int_, dword _int_2) { return dword::number(_int_) + dword::number(_int_2); }
        friend dword operator+(dword _int_, u32 value2) { return dword::number(_int_) + value2; }
        friend dword operator+(u32 value2, dword _int_) { return value2 + dword::number(_int_); }
        dword operator+=(u32 value2)
        {
            dword::numberref(*this) += value2;
            return *this;
        }
        dword operator+=(dword _int_2)
        {
            dword::numberref(*this) += dword::number(_int_2);
            return *this;
        }
        friend dword operator-(dword _int_, dword _int_2) { return dword::number(_int_) - dword::number(_int_2); }
        friend dword operator-(dword _int_, u32 value2) { return dword::number(_int_) - value2; }
        friend dword operator-(u32 value2, dword _int_) { return value2 - dword::number(_int_); }
        dword operator-=(u32 value2)
        {
            dword::numberref(*this) -= value2;
            return *this;
        }
        dword operator-=(dword _int_2)
        {
            dword::numberref(*this) -= dword::number(_int_2);
            return *this;
        }
        friend dword operator*(dword _int_, dword _int_2) { return dword::number(_int_) * dword::number(_int_2); }
        friend dword operator*(dword _int_, u32 value2) { return dword::number(_int_) * value2; }
        friend dword operator*(u32 value2, dword _int_) { return value2 * dword::number(_int_); }
        dword operator*=(u32 value2)
        {
            dword::numberref(*this) *= value2;
            return *this;
        }
        dword operator*=(dword _int_2)
        {
            dword::numberref(*this) *= dword::number(_int_2);
            return *this;
        }
        friend dword operator/(dword _int_, dword _int_2) { return dword::number(_int_) / dword::number(_int_2); }
        friend dword operator/(dword _int_, u32 value2) { return dword::number(_int_) / value2; }
        friend dword operator/(u32 value2, dword _int_) { return value2 / dword::number(_int_); }
        dword operator/=(u32 value2)
        {
            dword::numberref(*this) /= value2;
            return *this;
        }
        dword operator/=(dword _int_2)
        {
            dword::numberref(*this) /= dword::number(_int_2);
            return *this;
        }
        friend dword operator%(dword _int_, dword _int_2) { return dword::number(_int_) % dword::number(_int_2); }
        friend dword operator%(dword _int_, u32 value2) { return dword::number(_int_) % value2; }
        friend dword operator%(u32 value2, dword _int_) { return value2 % dword::number(_int_); }
        dword operator%=(u32 value2)
        {
            dword::numberref(*this) %= value2;
            return *this;
        }
        dword operator%=(dword _int_2)
        {
            dword::numberref(*this) %= dword::number(_int_2);
            return *this;
        }
        friend dword operator>>(dword __integ, u32 value2) { return dword::number(__integ) >> value2; }
        friend dword operator<<(dword __integ, u32 value2) { return dword::number(__integ) << value2; }
        friend std::ostream &operator<<(std::ostream &os, dword v)
        {
            os << dword::number(v);
            return os;
        }
        dword operator++(int) {
            return numbers::dword(++(*(u32*)(this)));
        }
        dword operator--(int) {
            return numbers::dword(--(*(u32*)(this)));
        }
    };
    class qword
    {
    public:
        dword low;
        dword higth;
        qword(u64 value) : low((u32)(value)), higth((u32)(value / maxu32)) {}
        qword(f64 value) : low(*(u32 *)(&value)), higth((u32)(*(u64 *)(&value) / (u64)(maxu32))) {}
        qword(u32 _low, u32 _higth) : low(_low), higth(_higth) {}
        qword(dword _low, dword _higth) : low(_low), higth(_higth) {}
        u64 number() { return *(u64 *)(this); }
        f64 fnumber() { return *(f64 *)(this); }
        ///////////////////////////////////////////////////////////
        static u64 number(qword value) { return *(u64 *)(&value); }
        u64 &numberref() { return *(u64 *)(this); }
        ///////////////////////////////////////////////////////////
        static u64 union64(u32 _low, u32 _higth) {return (u64(_higth) << 32) + _higth;}
        ///////////////////////////////////////////////////////////
        static u64 &numberref(qword &value) { return *(u64 *)(&value); }
        friend qword operator+(qword _long_, qword _long_2) { return qword::number(_long_) + qword::number(_long_2); }
        friend qword operator+(qword _long_, u64 value2) { return qword::number(_long_) + value2; }
        friend qword operator+(u64 value2, qword _long_) { return value2 + qword::number(_long_); }
        qword operator+=(u64 value2)
        {
            qword::numberref(*this) += value2;
            return *this;
        }
        qword operator+=(qword _long_2)
        {
            qword::numberref(*this) += qword::number(_long_2);
            return *this;
        }
        friend qword operator-(qword _long_, qword _long_2) { return qword::number(_long_) - qword::number(_long_2); }
        friend qword operator-(qword _long_, u64 value2) { return qword::number(_long_) - value2; }
        friend qword operator-(u64 value2, qword _long_) { return value2 - qword::number(_long_); }
        qword operator-=(u64 value2)
        {
            qword::numberref(*this) -= value2;
            return *this;
        }
        qword operator-=(qword _long_2)
        {
            qword::numberref(*this) -= qword::number(_long_2);
            return *this;
        }
        friend qword operator*(qword _long_, qword _long_2) { return qword::number(_long_) * qword::number(_long_2); }
        friend qword operator*(qword _long_, u64 value2) { return qword::number(_long_) * value2; }
        friend qword operator*(u64 value2, qword _long_) { return value2 * qword::number(_long_); }
        qword operator*=(u64 value2)
        {
            qword::numberref(*this) *= value2;
            return *this;
        }
        qword operator*=(qword _long_2)
        {
            qword::numberref(*this) *= qword::number(_long_2);
            return *this;
        }
        friend qword operator/(qword _long_, qword _long_2) { return qword::number(_long_) / qword::number(_long_2); }
        friend qword operator/(qword _long_, u64 value2) { return qword::number(_long_) / value2; }
        friend qword operator/(u64 value2, qword _long_) { return value2 / qword::number(_long_); }
        qword operator/=(u64 value2)
        {
            qword::numberref(*this) /= value2;
            return *this;
        }
        qword operator/=(qword _long_2)
        {
            qword::numberref(*this) /= qword::number(_long_2);
            return *this;
        }
        friend qword operator%(qword _long_, qword _long_2) { return qword::number(_long_) % qword::number(_long_2); }
        friend qword operator%(qword _long_, u64 value2) { return qword::number(_long_) % value2; }
        friend qword operator%(u64 value2, qword _long_) { return value2 % qword::number(_long_); }
        qword operator%=(u64 value2)
        {
            qword::numberref(*this) %= value2;
            return *this;
        }
        qword operator%=(qword _long_2)
        {
            qword::numberref(*this) %= qword::number(_long_2);
            return *this;
        }
        friend qword operator>>(qword __long, u64 value2) { return qword::number(__long) >> value2; }
        friend qword operator<<(qword __long, u64 value2) { return qword::number(__long) << value2; }
        friend std::ostream &operator<<(std::ostream &os, qword v)
        {
            os << qword::number(v);
            return os;
        }
        qword operator++(int) {
            return numbers::qword(++(*(u64*)(this)));
        }
        qword operator--(int) {
            return numbers::qword(--(*(u64*)(this)));
        }
    };
    class Binary
    {
    public:
        template <typename T>
        static stringbuffer binary(T value)
        {
            stringbuffer __bin__("0b", sizeof(T) * 8 + 2);
            i16 i = sizeof(T) * 8;
            while (--i >= 0)
                __bin__[(sizeof(T) * 8) - i + 1] = value & ((T)(1) << i) ? '1' : '0';
            return __bin__;
        }
        stringbuffer operator<<(u8 __value)
        {
            return Binary::binary<u8>(__value);
        }
        stringbuffer operator<<(i8 __value)
        {
            return Binary::binary<u8>(__value);
        }
        stringbuffer operator<<(byte __value)
        {
            return Binary::binary<u8>(__value.number());
        }
        stringbuffer operator<<(u16 __value)
        {
            return Binary::binary<u16>(__value);
        }
        stringbuffer operator<<(i16 __value)
        {
            return Binary::binary<u16>(__value);
        }
        stringbuffer operator<<(word __value)
        {
            return Binary::binary<u16>(__value.number());
        }
        stringbuffer operator<<(u32 __value)
        {
            return Binary::binary<u32>(__value);
        }
        stringbuffer operator<<(i32 __value)
        {
            return Binary::binary<u32>(__value);
        }
        stringbuffer operator<<(dword __value)
        {
            return Binary::binary<u32>(__value.number());
        }
        stringbuffer operator<<(u64 __value)
        {
            return Binary::binary<u64>(__value);
        }
        stringbuffer operator<<(i64 __value)
        {
            return Binary::binary<u64>(__value);
        }
        stringbuffer operator<<(qword __value)
        {
            return Binary::binary<u64>(__value.number());
        }
    };
    inline Binary bin;
    class Hexadecimal
    {
    private:
        static char __hexadecimal__caracter__(u8 value) { return (value < 10) ? '0' + value : value - 10 + 'a'; }

    public:
        template <typename T>
        static stringbuffer hexadecimal(T value)
        {
            stringbuffer __hex__("0x", sizeof(T) * 2 + 2);
            i16 i = sizeof(T) * 2;
            while (--i >= 0)
            {
                __hex__[sizeof(T) * 2 - i + 1] = __hexadecimal__caracter__(value / ((T)(1) << (4 * i)));
                value %= ((T)(1) << (T)(4 * i));
            }
            return __hex__;
        }
        stringbuffer operator<<(u8 __value)
        {
            return Hexadecimal::hexadecimal<u8>(__value);
        }
        stringbuffer operator<<(i8 __value)
        {
            return Hexadecimal::hexadecimal<u8>(__value);
        }
        stringbuffer operator<<(byte __value)
        {
            return Hexadecimal::hexadecimal<u8>(__value.number());
        }
        stringbuffer operator<<(u16 __value)
        {
            return Hexadecimal::hexadecimal<u16>(__value);
        }
        stringbuffer operator<<(i16 __value)
        {
            return Hexadecimal::hexadecimal<u16>(__value);
        }
        stringbuffer operator<<(word __value)
        {
            return Hexadecimal::hexadecimal<u16>(__value.number());
        }
        stringbuffer operator<<(u32 __value)
        {
            return Hexadecimal::hexadecimal<u32>(__value);
        }
        stringbuffer operator<<(i32 __value)
        {
            return Hexadecimal::hexadecimal<u32>(__value);
        }
        stringbuffer operator<<(dword __value)
        {
            return Hexadecimal::hexadecimal<u32>(__value.number());
        }
        stringbuffer operator<<(u64 __value)
        {
            return Hexadecimal::hexadecimal<u64>(__value);
        }
        stringbuffer operator<<(i64 __value)
        {
            return Hexadecimal::hexadecimal<u64>(__value);
        }
        stringbuffer operator<<(qword __value)
        {
            return Hexadecimal::hexadecimal<u64>(__value.number());
        }
    };
    inline Hexadecimal hex;
}
#endif