#ifndef DES_H
#define DES_H

#include <vector>
#include <bitset>
#include <cassert>


namespace des {


	//64 for bit

	using data_t = char[64];


	using byte_t = char;
	using byte8_t = char[8];




	using bit8_t = char[8];
	using bit64_t = char[64];




	using bitset8_t = std::bitset<8>;
	using bitset64_t = std::bitset<64>;


	//key str
	using keyStr_t = char[8];


	//pc1
	constexpr std::size_t pclLen = 7 * 8;
	constexpr std::size_t rolLen = pclLen / 2;
	using bitset56_t = std::bitset<pclLen>;
	using bitset28_t = std::bitset<rolLen>;


	//pc2
	constexpr std::size_t pc2Len = 6 * 8;
	using bitset48_t = std::bitset<pc2Len>;



	//make subkeys
	constexpr unsigned char forTimes = 16;



	extern const unsigned short ip_table[];

	class Des {

	private:

		static const unsigned char m_pc1Table[pclLen];
		static const unsigned char m_pc2Table[pc2Len];

		
		static const unsigned char m_moveTimes[forTimes];

	private:
		//const keyStr_t &m_keyStr;
		//bitset64_t m_key64;
		//bitset56_t m_bit56;
		//std::vector<bitset48_t> m_subKeys;

	public:
		//explicit Des(const keyStr_t &keyStr);
		//~Des();
		//Des(const Des &rhs) = delete;
		//Des &operator=(const Des &rhs) = delete;
		//Des(Des &&rhs) = delete;
		//Des &operator=(Des &&rhs) = delete;

	public:
		//void Init();

	public:

		////IP
		////void IPTransform(data_t &data);



		////common
		////void ByteToBit(byte_t c, bit8_t &bits);
		//void ByteToBit(char c, bitset8_t &bits);

		////void Byte8To64Bit(byte8_t &bytes, bit64_t &bits);
		//void Byte8To64Bit(const byte8_t &bytes, bitset64_t &bits);
		////从高位到低位打印
		//void PrintKey64HTL();


		//
	private:
		//void TransformForPc1();
		//void TransformForPc2( bitset48_t &subKeys);
		//void Rol(unsigned short fortime);

		//template <std::size_t N> void HTFlip(std::bitset<N> &bits);

		//template <unsigned int T>
		//bool Same(const std::bitset<T> &bits, const std::string &str) {
		//	assert(str.size() == T);

		//	std::string tstr;
		//	for (const auto &c : str) {
		//		if (c != ' ')
		//			tstr.push_back(c);
		//	}

		//	for (std::size_t i = 0; i != bits.size(); ++i) {
		//		bool n = tstr[i] - '0';
		//		if (bits[i] != n) {
		//			assert(false);
		//			return false;
		//		}
		//	}
		//	return true;
		//}

	public:
		//void MakeSubKeys();



	};


	//template <std::size_t N>
	//void Des::HTFlip(std::bitset<N> &bits) {
	//	std::bitset<N> temp;
	//	//for()
	//}

}


#endif DES_H