#ifndef DES_H
#define DES_H

#include <cassert>
#include <string>
#include <array>
#include <vector>
#include <bitset>

namespace des {




	//pc2
	constexpr std::size_t pc2Len = 6 * 8;
	//using bitset48_t = std::bitset<pc2Len>;



	//make subkeys
	constexpr unsigned char forTimes = 16;


	class Des {
	public:
		using byte_t = char;
		using bit8_t = std::array<byte_t, 8>;
		using bit64_t = std::array<byte_t, 64>;


		//pc1
		constexpr static std::size_t m_pclLen = 7 * 8;
		using bit56_t = std::array<byte_t, m_pclLen>;
		using bit56Size_t = bit56_t::size_type;

		using bit28_t = std::array<byte_t, m_pclLen / 2>;
		using bit28Size_t = bit28_t::size_type;




		using bit48_t = std::array<byte_t, 48>;
		using bit48Ctr_t = std::array<bit48_t, forTimes>;


	private:

		static const unsigned char m_pc1Table[m_pclLen];
		static const unsigned char m_pc2Table[pc2Len];
		static const unsigned char m_moveTimes[forTimes];

	private:
		bit64_t m_bit64Key;
		bit56_t m_bit56;
		bit48Ctr_t m_bit48Keys;


	public:
		Des();
		void Init();

	public:
		template <typename T, std::size_t N> void InitBits(std::array<T, N> &bits);
		template <std::size_t N> std::string ArrToString(const std::array<byte_t, N> &bits);
		template <std::size_t N> void BitSetToArr(std::array<byte_t, N> &bits, const std::bitset<N> &bitset);
		template <std::size_t N> bool CheckSame(const std::array<byte_t, N> &bits, const std::string &str);

		void TransformForPc1();
		void Rol(unsigned short fortimes);
		void MakeSubKeys();


	};

}


namespace des {

	template <typename T, std::size_t N> void Des::InitBits(std::array<T, N> &bits) {

		for (auto &c : bits) {
			c = {};
		}

	}


	template <std::size_t N>  std::string Des::ArrToString(const std::array<byte_t, N> &bits) {
		std::string str(bits.size(), '\0');
		typename std::decay<decltype(bits)>::type::size_type i = 0;
		for (; i != bits.size(); ++i) {
			auto svv = bits.at(i);
			str.at(i) = svv + '0';
		}
		return str;
	}

	template <std::size_t N> void Des::BitSetToArr(std::array<byte_t, N> &bits, const std::bitset<N> &bitset) {
		typename std::decay<decltype(bits)>::type::size_type i = 0;
		for (; i != bits.size(); ++i) {
			bits.at(i) = bitset[bits.size() - 1 - i];
		}
	}


	template <std::size_t N> bool Des::CheckSame(const std::array<byte_t, N> &bits, const std::string &str) {
		std::string tstr;
		for (const auto &c : str) {
			if (c != ' ')
				tstr.push_back(c);
		}
		assert(tstr.size() == N);

		for (std::size_t i = 0; i != bits.size(); ++i) {
			bool n = tstr[i] - '0';
			if (bits[i] != n) {
				assert(false);
				return false;
			}
		}
		return true;
	}


}


#endif // !DES_H