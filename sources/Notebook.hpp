#pragma once
#include "Direction.hpp"
#include <iostream>
#include <unordered_map>

namespace ariel {

	class Notebook {
		private:
			
			std::unordered_map<int,std::pair<int, int>> borders;
			std::unordered_map<std::string, char> my_nootbook;
			

		public:
			Notebook() {};
			~Notebook() {};

			void write(int page, int row, int column, ariel::Direction dir,const std::string& s);
			std::string read(int page, int row, int column, ariel::Direction dir, int chars) const;
			void erase(int page, int row, int column, ariel::Direction dir, int chars);
			void show(int page) const;

	};
}