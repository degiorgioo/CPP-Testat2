#include "Word.h"
#include <iostream>
#include <istream>

Word::Word( const std::string value ) :value{ value }{};

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
			}
};

void Word::print(std::ostream &output) const{
	output << (*this).value;
};




