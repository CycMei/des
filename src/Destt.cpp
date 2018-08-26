#include <cstddef>
#include <type_traits>
#include <iostream>

#include "Des.h"

namespace des {







	const unsigned char Des::m_pc1Table[m_pclLen] = 
	{

		57, 49, 41, 33, 25, 17, 9,
		1,  58, 50, 42, 34, 26, 18,
		10, 2,  59, 51, 43, 35, 27,
		19, 11, 3,  60, 52, 44, 36,

		63, 55, 47, 39, 31, 23, 15,
		7,  62, 54, 46, 38, 30, 22,
		14, 6,  61, 53, 45, 37, 29,
		21, 13, 5,  28, 20, 12, 4

	};

	const unsigned char Des::m_pc2Table[pc2Len] =
	{
		14,    17,   11,    24,     1,    5,
		3,     28,   15,     6,    21,   10,
		23,    19,   12,     4,    26,    8,
		16,    7,   27,    20,    13,    2,
		41,    52,   31,    37,    47,   55,
		30,    40,   51,    45,    33,   48,
		44,    49,   39,    56,    34,   53,
		46,    42,   50,    36,    29,   32,
	};


	const unsigned char Des::m_moveTimes[forTimes] = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };




}

namespace des {


	//Des::Des(const keyStr_t &keyStr) : m_keyStr(keyStr){

	//	Init();
	//}


	//Des::~Des() {

	//}



	//void Des::Init() {

	//	std::string str = "0001001100110100010101110111100110011011101111001101111111110001";
	//	for (unsigned int i = 0; i != 64; ++i) {
	//		auto num = str[i] - '0';
	//		m_key64.set(i, num);
	//	}


	//	return;

	//	m_key64.reset();
	//	Byte8To64Bit(m_keyStr, m_key64);
	//}




	//void Des::IPTransform(data_t &data) {

	//	data_t temp = { '\0' };
	//	

	//	const std::size_t len = sizeof ip_table / sizeof *ip_table;
	//	for (std::size_t i = 0; i != len; ++i) {
	//		temp[i] = data[ip_table[i]];
	//	}
	//	
	//	std::memcpy(data, temp, sizeof data);
	//}



}

namespace des {


	/*
		c : 输入字符
		bits : 返回字符 c 的二进制形式 从左到右 -> 低位到高位
	*/

	//void Des::ByteToBit(byte_t c, bit8_t &bits) {

	//	constexpr unsigned char len = std::extent<bit8_t, 0>::value;

	//	for (unsigned char i = 0; i != len; ++i) {
	//		bits[0] = (c >> i) & 1;
	//	}

	//}



	/*
		从左到右 -> 从低位到高位
		例如：
		3 的二进制为 0000 0011
		std::bitset<8> btt = 3;
		btt 应该为 1100 0000
	*/

	//inline void Des::ByteToBit(char c, bitset8_t &bits) {
		bits = c;
	}







	//void Des::Byte8To64Bit(byte8_t &bytes, bit64_t &bits) {
	//	constexpr unsigned char len = std::extent<byte8_t, 0>::value;
	//	for (unsigned char i = 0; i != len; ++i) {
	//		bit8_t bit = { '\0' };
	//		ByteToBit(bytes[i], bit);
	//		const unsigned char star = i << 3;
	//		constexpr unsigned char ln = std::extent<bit8_t, 0>::value;

	//		for (unsigned char j = 0; j != ln; ++j) {
	//			bits[star + j] = bit[j];
	//		}
	//	}

	//}





	//void Des::Byte8To64Bit(const byte8_t &bytes, bitset64_t &bits) {

	//	bits.reset();
	//	constexpr auto len = std::extent<byte8_t, 0>::value;
	//	for (unsigned char i = 0; i != len; ++i) {
	//		bitset8_t bit;
	//		ByteToBit(bytes[i], bit);
	//		const unsigned char star = i << 3;
	//		for (std::size_t j = 0; j != bit.size(); ++j) {
	//			bits.set(star + j, bit[j]);
	//		}
	//	}

	//	PrintKey64HTL();

	//}


	//void Des::PrintKey64HTL() {
	//	
	//	unsigned char space = 0;
	//	const char *spaceChar = " ";
	//	const unsigned char maxSapce = 4;
	//	const char *maxSapceChar = "  ";

	//	std::size_t hig = m_key64.size();

	//	std::cout << "Hight to low: " << std::endl;
	//	while (hig > 0)
	//	{
	//		--hig;
	//		std::cout << m_key64[hig] << spaceChar;
	//		++space;
	//		if (space >= maxSapce) {
	//			std::cout << maxSapceChar;
	//			space = 0;
	//		}
	//	}
	//}




}

namespace des {

	//void Des::TransformForPc1() {

	//	m_bit56.reset();

	//	for (std::size_t i = 0; i != m_bit56.size(); ++i) {
	//		m_bit56.set(i, m_key64[m_pc1Table[i] - 1]);
	//	}

	//}

	//void Des::TransformForPc2(bitset48_t &subKeys) {
	//	
	//	subKeys.reset();
	//	for (std::size_t i = 0; i != subKeys.size(); ++i) {
	//		subKeys.set(i, m_bit56[m_pc2Table[i] - 1]);
	//	}

	//}



	//void Des::Rol(unsigned short fortime) {

	//	// left right  从左到右 都是 低位到高位
	//	bitset28_t left;
	//	bitset28_t right;

	//	std::size_t pi = m_bit56.size() / 2;
	//	for (std::size_t i = 0; i != pi; ++i) {
	//		left.set(i, m_bit56[i]);
	//		right.set(i, m_bit56[i + pi]);
	//	}

	//	bool bl = Same(left, "1111000011001100101010101111");
	//	bl = Same(right, "0101010101100110011110001111");


	//	unsigned short times = m_moveTimes[fortime];

	//	{
	//		// ????????????
	//		// bitset 位移，如果向左 其实是二进制形式的右位移 因为bitset从左到右->低位到高位
	//		// 总之要满足内置数值的位移模式（比如向左位移 那一定是二进制的高位向左移）


	//		//(x >> (N - n)) | (x << n)

	//		left = (left >> (pi - times)) | (left << times);
	//		bl = Same(left, "1110000110011001010101011111");

	//		
	//	}
	//	
	//	{
	//		right = (right >> (pi - times)) | (right << times);
	//		bl = Same(right, "1010101011001100111100011110");

	//	}

	//	m_bit56.reset();
	//	for (unsigned char i = 0; i != pi; ++i) {
	//		m_bit56.set(i, left[i]);
	//		auto rightIndex = i + pi;
	//		m_bit56.set(rightIndex, right[rightIndex]);
	//	}


	//}


	//void Des::MakeSubKeys() {
	//	TransformForPc1();
	//	bool bl = Same(m_bit56, "11110000110011001010101011110101010101100110011110001111");
	//	
	//	m_subKeys.clear();
	//	for (unsigned char i = 0; i != forTimes; ++i) {
	//		Rol(i);
	//		bitset48_t subKeys;
	//		TransformForPc2(subKeys);
	//		m_subKeys.push_back(subKeys);
	//	}
	//}



}

       