#pragma once
#include "Direction.hpp"
#include <iostream>
#include <unordered_map>

namespace ariel {
/*	struct postion
	{
		unsigned int page;
		unsigned int row;
		unsigned int column;
	};
	*/


	class Notebook {
		private:
			
			std::unordered_map<unsigned int,std::pair<unsigned int, unsigned int>> borders;
			std::unordered_map<std::string, char> my_nootbook;
			

		public:
			Notebook() {};
			~Notebook() {};

			void write(unsigned int page, unsigned int row, unsigned int column, ariel::Direction dir,const std::string& s);
			std::string read(unsigned int page, unsigned int row, unsigned int column, ariel::Direction dir, unsigned int chars) const;
			void erase(unsigned int page, unsigned int row, unsigned int column, ariel::Direction dir, unsigned int chars);
			void show(unsigned int page) const;

	};
}