#ifndef ANSI_H
#define ANSI_H

#include <initializer_list>
#include <iostream>
#include <vector>
#include <cstdint>

namespace psx::ansi {

	enum : std::uint8_t{
		Bold = 1,
		Faint = 2,
		Italic = 3,
		Underline = 4,
		Slow_blink = 5,
		Rapid_blink = 6,
		Invert = 7,
		Conceal = 8,
		Crossed_out = 9,
		Fraktur = 20
	};

	struct ResetType{};

	struct Foreground{
		std::uint8_t r = 0, g = 0, b = 0;
	};

	struct Background{
		std::uint8_t r = 0, g = 0, b = 0;
	};

	struct SGR{
		std::uint8_t n;
	};

	struct Atributes{
		std::vector<std::uint8_t> atribs;
		Atributes(std::initializer_list<std::uint8_t> atr): atribs(atr){}
	};

	constexpr static ResetType Reset{};
}

std::ostream& operator<<(std::ostream& os, const psx::ansi::ResetType& rt);
std::ostream& operator<<(std::ostream& os, const psx::ansi::Background& bg);
std::ostream& operator<<(std::ostream& os, const psx::ansi::Foreground& fg);
std::ostream& operator<<(std::ostream& os, const psx::ansi::SGR& sgr);
std::ostream& operator<<(std::ostream& os, const psx::ansi::Atributes& atr);
#endif

