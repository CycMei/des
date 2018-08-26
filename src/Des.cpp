
#include "Des.h"

namespace des {

	constexpr std::size_t Des::m_pclLen;


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

	Des::Des() {
		Init();
		MakeSubKeys();
	}

	void Des::Init() {
		std::bitset<64> sv("0001001100110100010101110111100110011011101111001101111111110001");
		BitSetToArr(m_bit64Key, sv);
	}

}


namespace des {




	void Des::TransformForPc1() {
		
		InitBits(m_bit56);
		for (bit56Size_t i = 0; i != m_bit56.size(); ++i) {
			m_bit56.at(i) = m_bit64Key.at(m_pc1Table[i] - 1);
		}

		CheckSame(m_bit56, "1111000 0110011 0010101 0101111 0101010 1011001 1001111 0001111");
	}


	void Des::Rol(unsigned short fortimes) {

		bit28_t left;
		bit28_t right;

		for (bit28Size_t i = 0; i != left.size(); ++i) {
			left.at(i) = m_bit56.at(i);
			right.at(i) = m_bit56.at(i + left.size());
		}

		//CheckSame(left, "1111000011001100101010101111");
		//CheckSame(right, "0101010101100110011110001111");

		

		const unsigned short times = m_moveTimes[fortimes];

		auto func = [this, &times](bit28_t &bit28)->void {
			std::string str = ArrToString(bit28);
			std::bitset<m_pclLen / 2> bits(str);
			//(x >> (N - n)) | (x << n)

			auto A = bits >> (bits.size() - times);
			auto B = bits << times;
			std::bitset<m_pclLen / 2> res = A | B;
			BitSetToArr(bit28, res);
		};

		func(left);
		//CheckSame(left, "1110000110011001010101011111");

		func(right);
		//CheckSame(right, "1010101011001100111100011110");


		for (bit28Size_t i = 0; i != left.size(); ++i) {
			m_bit56.at(i) = left.at(i);
			m_bit56.at(i + left.size()) = right.at(i);
		}

	}






	void Des::MakeSubKeys() {
		TransformForPc1();
		InitBits(m_bit48Keys);

		for (unsigned char i = 0; i != forTimes; ++i) {
			Rol(i);
			//bitset48_t subKeys;
			//TransformForPc2(subKeys);
			//m_subKeys.push_back(subKeys);
		}

	}



}