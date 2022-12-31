#include "ansi.h"

std::ostream& operator<<(std::ostream& os, const psx::ansi::ResetType& rt){
	os << "\033[0m";
	return os;
}
std::ostream& operator<<(std::ostream& os, const psx::ansi::Background& bg){
	os << "\033[48;2;" << (int) bg.r << ";" << (int) bg.g << ";" << (int) bg.b << "m";
	return os;
}
std::ostream& operator<<(std::ostream& os, const psx::ansi::Foreground& fg){
	os << "\033[38;2;" << (int) fg.r << ";" << (int) fg.g << ";" << (int) fg.b << "m";
	return os;
}
std::ostream& operator<<(std::ostream& os, const psx::ansi::SGR& sgr){
	os << "\033[" << (int) sgr.n << "m";
	return os;
}

std::ostream& operator<<(std::ostream& os, const psx::ansi::Atributes& atr){
	decltype(atr.atribs.size()) i = 0;
	for(; i < atr.atribs.size(); ++i)
		os << "\033[" << (int) atr.atribs[i] << "m";
	return os;
}
