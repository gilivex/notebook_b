#include <iostream>
#include "Notebook.hpp"
using namespace ariel;
using namespace std;

void Notebook::write(unsigned int page, unsigned int row, unsigned int column, Direction dir, const std::string& s) {
    if(s.empty() || s.size()==0){
        throw invalid_argument{"the input is without chars"};
    }

    if (dir == Direction::Horizontal) {
        if (column + s.size()>99){
            throw out_of_range{"the input is too long or the position is out of column range can't pass possition 99 "}
        }
        if (borders.find(page) == borders.end()){
            borders[page].first = row;
            borders[page].second = row;
        }
        else{
            if (borders[page].first> row){
                borders[page].first = row;
            }
            if (borders[page].second<row){
                borders[page].second = row;
            }
        }

        for (int i = 0; i <s.size() ; ++i) {
            string position = to_string(page) + "." + to_string(row) + "." + to_string(column+i);
            if (my_nootbook.find(position) != my_nootbook.end()){
                if (my_nootbook[position] != s.at(i)){
                    throw invalid_argument{"there is an other char in this possition "};
                }
            }
        }
        for (int i = 0; i <s.size() ; ++i) {
            string position = to_string(page) + "." + to_string(row) + "." + to_string(column+i);
            my_nootbook[position]=s.at(i);
        }
    }

    else {
        if (column > 99){
            throw out_of_range{"column is out of range must be less then 100 "}
        }
        if (borders.find(page) == borders.end()){
            borders[page].first = row;
            borders[page].second = row + s.size();
        }
        else{
            if (borders[page].first> row){
                borders[page].first = row;
            }
            if (borders[page].second<row + s.size()){
                borders[page].second = row +s.size();
            }
        }

        for (int i = 0; i <s.size() ; ++i) {
            string position = to_string(page) + "." + to_string(row+i) + "." + to_string(column);
            if (my_nootbook.find(position) != my_nootbook.end()){
                if (my_nootbook[position] != s.at(i)){
                    throw invalid_argument{"there is an other char in this possition "};
                }
            }
        }
        for (int i = 0; i <s.size() ; ++i) {
            string position = to_string(page) + "." + to_string(row+i) + "." + to_string(column);
            my_nootbook[position]=s.at(i);
        }
    }
}


string Notebook::read(unsigned int page, unsigned int row, unsigned int column, Direction dir, unsigned int chars) const {
    string output = "";
    if (dir == Direction::Horizontal){
        if (column + chars > 99){
            throw out_of_range{"column is out of range must be less then 100"};
        }
        for (int i = 0; i <chars ; ++i) {
            string position = to_string(page) + "." + to_string(row) + "." + to_string(column+i);
            if (my_nootbook.find(position) != my_nootbook.end()){
                output += my_nootbook[position];
            } else{
                output += "_";
            }
        }
    } else{
        if (column > 99){
            throw out_of_range{"column is out of range must be less then 100"};
        }
        for (int i = 0; i <chars ; ++i) {
            string position = to_string(page) + "." + to_string(row+i) + "." + to_string(column);
            if (my_nootbook.find(position) != my_nootbook.end()){
                output += my_nootbook[position];
            } else{
                output += "_";
            }
        }
    }
	return output;
}

void Notebook::erase(unsigned int page, unsigned int row, unsigned int column, Direction dir, unsigned int chars) {


}

void Notebook::show(unsigned int page) const {
    if (borders.find(page)== borders.end()){
        return;
    }
    else{
        for (int i = borders.at(page).first ; i <borders.at(page).second ; ++i) {
            for (int j = 0; j <99 ; ++j) {
                string position = to_string(page) + "." + to_string(i) + "." + to_string(j);
                if (my_nootbook.find(position) != my_nootbook.end()){
                    cout<<my_nootbook.at(position);
                } else{
                    cout<<"_";
                }
            }
        cout<<endl;
        }
    }
}

