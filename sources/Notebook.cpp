#include <iostream>
#include "Notebook.hpp"
using namespace ariel;
using namespace std;

const int border = 99;
const int char_min = 32;
const int char_max = 125;

void Notebook::write(int page, int row, int column, Direction dir, const std::string& s) {
    if (page<0 || row < 0 || column <0 ){
        throw invalid_argument{"invalid position, can't be negative"};
    }
    int size = (size_t)s.size();
    if(s.empty() || size==0){
        return;
    }

    if (dir == Direction::Horizontal) {
        // edge cases
        if (column + size-1>border){
            throw out_of_range{"The input is too long or the position is out of column range can't pass possition 99 "};
        }
        // there isn't that page in the notebook - so we implementing it
        if (borders.find(page) == borders.end()){
            borders[page].first = row;
            borders[page].second = row;
        }
        //there is already this page in the notebook but need to be adjusted to the borders
        else{
            //top border of the page
            if (borders[page].first > row){
                borders[page].first = row;
            }
            // bottom border of the page
            if (borders[page].second < row){
                borders[page].second = row;
            }
        }
        // last check before writing every spot(position) that we are going to write in is ok to write in
        // string position will let us know every iteration where we are exactly(each itr' he changes
        // because we are in Horizontal we iterate the column

        for (int i = 0; i <size ; ++i) {
            string position = to_string(page) + "." + to_string(row) + "." + to_string(column+i);
            //
            if (my_nootbook.find(position) != my_nootbook.end()){
                 // if it exists we check if the char is not different from the char in the string
                 if (my_nootbook[position] != '_'){
                    throw invalid_argument{"there is an other char in this possition "};
                }
            }
            if ( (s.at((unsigned int)i) <char_min || s.at((unsigned int)i) >char_max)){
                throw invalid_argument{"there is invalid chars in the string"};
            }
        }
        // starting actually to write
        for (int i = 0; i <size ; ++i) {
            string position = to_string(page) + "." + to_string(row) + "." + to_string(column+i);
            my_nootbook[position] = s.at((unsigned int)i);
        }
    }
    // vertical status
    else {
        if (column > border){
            throw out_of_range{"column is out of range must be less then 100 "};
        }
            if (borders.find(page) == borders.end()){
                borders[page].first = row;
                borders[page].second = row + size;
            }
            //adjusting to the borders by vertical situations
            else{
                if (borders[page].first > row){
                    borders[page].first = row;
                }
            if (borders[page].second < row + size){
                borders[page].second = row +size;
            }
        }
        // because we are in vartical we iterate the rows
        for (int i = 0; i <size ; ++i) {
            string position = to_string(page) + "." + to_string(row+i) + "." + to_string(column);
            if (my_nootbook.find(position) != my_nootbook.end()){
                if (my_nootbook[position] != '_'){
                    throw invalid_argument{"there is an other char in this possition "};
                }
            }
            if ((s.at((unsigned int)i) <char_min || s.at((unsigned int)i) >char_max)){
                throw invalid_argument{"there is invalid chars in the string"};
            }
        }
        for (int i = 0; i <size ; ++i) {
            string position = to_string(page) + "." + to_string(row+i) + "." + to_string(column);
            my_nootbook[position]=s.at((unsigned int)i);
        }
    }
}


string Notebook::read(int page, int row, int column, Direction dir, int chars) const {
    if (page<0 || row < 0 || column <0 || chars < 0){
        throw invalid_argument{"invalid position, can't be negative"};
    }
    string output;
    if (dir == Direction::Horizontal){
        if (column + chars-1 > border){
            throw out_of_range{"column is out of range must be less then 100"};
        }
        if(borders.find(page) == borders.end()){
            for(uint i = 0; i< chars; i++){
                output += '_';
            }
            return output;
        }
        for (int i = 0; i <chars ; ++i) {
            string position = to_string(page) + "." + to_string(row) + "." + to_string(column+i);
            if (my_nootbook.find(position) != my_nootbook.end()){
                output += my_nootbook.at(position);
            } else{
                output += "_";
            }
        }

      // vertical reading
    } else{
        if (column > border){
            throw out_of_range{"column is out of range must be less then 100"};
        }
        if(borders.find(page) == borders.end()){
            for(uint i = 0; i< chars; i++){
                output += '_';
            }
            return output;
        }
        for (int i = 0; i <chars ; ++i) {
            string position = to_string(page) + "." + to_string(row+i) + "." + to_string(column);
            if (my_nootbook.find(position) != my_nootbook.end()){
                output += my_nootbook.at(position);
            } else{
                output += "_";
            }
        }
    }
	return output;
}

void Notebook::erase(int page, int row, int column, Direction dir, int chars) {
    if (page<0 || row < 0 || column <0 || chars < 0){
        throw invalid_argument{"invalid position, can't be negative"};
    }
    if (dir == Direction::Horizontal){
        if (column + chars-1 > border){
            throw out_of_range{"column is out of range must be less then 100"};
        }
        if (borders.find(page) == borders.end()){
            borders[page].first = row;
            borders[page].second = row;
        }
            //there is already this page in the notebook but need to be adjusted to the borders
        else{
            //top border of the page
            if (borders[page].first > row){
                borders[page].first = row;
            }
            // bottom border of the page
            if (borders[page].second < row){
                borders[page].second = row;
            }
        }
        for (int i = 0; i <chars ; i++) {
            string position = to_string(page) + "." + to_string(row) + "." + to_string(column+i);
            my_nootbook[position] = '~';
        }
     // vertical reading
    } else {
        if (column > border) {
            throw out_of_range{"column is out of range must be less then 100"};
        }
        if (borders.find(page) == borders.end()){
            borders[page].first = row;
            borders[page].second = row + chars;
        }
            //adjusting to the borders by vertical situations
        else{
            if (borders[page].first > row){
                borders[page].first = row;
            }
            if (borders[page].second < row + chars){
                borders[page].second = row +chars;
            }
        }
        for (int i = 0; i < chars; ++i) {
            string position = to_string(page) + "." + to_string(row + i) + "." + to_string(column);
            my_nootbook[position] = '~';
        }
    }
}

void Notebook::show(int page) const {
    if (page < 0) {
        throw invalid_argument{"invalid page, can't be negative"};
    }
    if (borders.find(page) != borders.end()) {
        for (int i = borders.at(page).first; i < borders.at(page).second; ++i) {
            for (int j = 0; j < border; ++j) {
                string position = to_string(page) + "." + to_string(i) + "." + to_string(j);
                if (my_nootbook.find(position) != my_nootbook.end()) {
                    cout << my_nootbook.at(position);
                } else {
                    cout << "_";
                }
            }
            cout << endl;
        }
    }
}
