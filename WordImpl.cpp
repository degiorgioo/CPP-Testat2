#include "Word.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <istream>
#include <sstream>
#include <stdexcept>

Word::Word( const std::string value ){
	if(std::all_of(begin(value), end(value), ::isalpha)){
		(*this).value = value;
	}else{
		throw std::invalid_argument("This is not a word.");
	}
};

void Word::read(std::istream& input){
			std::string temp{};
			char c;

			while(input.peek() != EOF){
				input.get(c);
				if(std::isalpha(c)){
					temp += c;
				}else if(!(temp.empty())){
					break;
				}
			}

			if(!(temp.empty())){
				(*this).value = temp;
			}else{
				input.setstate(input.failbit);
			}
};

void Word::print(std::ostream &output) const{
	output << (*this).value;
};




