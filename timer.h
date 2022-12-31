#ifndef TIMER_H
#define TIMER_H

#include "ansi.h"
#include <chrono>
#include <string>

namespace psx {
	template <typename T = std::chrono::microseconds>
	class Timer{
		public:
			typedef T timeUnit;
			Timer(std::string name = ""): m_Name(name){
				m_StartTimepoint = std::chrono::high_resolution_clock::now();
			}
			void Stop(){
				auto endTimePoint = std::chrono::high_resolution_clock::now();
				auto start = std::chrono::time_point_cast<timeUnit>(m_StartTimepoint).time_since_epoch().count();

				auto end = std::chrono::time_point_cast<timeUnit>(endTimePoint).time_since_epoch().count();
				auto duration = end - start;
				
				std::cout << ansi::Atributes{ansi::Bold} << ansi::Foreground{255,0,0}; 
				std::cout << m_Name << ansi::Reset;
				std::cout << ": duration " << duration;

				using namespace std::chrono;
				if(typeid(timeUnit) == typeid(nanoseconds)){
					std::cout << "ns\n";
				}
				
				else if(typeid(timeUnit) == typeid(microseconds)){
					std::cout << "us\n";
				}

				else if(typeid(timeUnit) == typeid(milliseconds)){
					std::cout << "ms\n";
				}

				else if(typeid(timeUnit) == typeid(seconds)){
					std::cout << "s\n";
				}

				else if(typeid(timeUnit) == typeid(minutes)){
					std::cout << "m\n";
				}
				else if(typeid(timeUnit) == typeid(hours)){
					std::cout << "h\n";
				}
				else {
					std::cout << "units\n";
				}
			}
			~Timer(){
				Stop();
			}
		private:
			std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
			std::string m_Name;
	};
}

#endif

