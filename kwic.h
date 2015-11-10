
#ifndef KWIC_H_
#define KWIC_H_

#include <set>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>
#include "Word.h"

std::set<std::vector<Word>> rotate(std::istream &is, std::ostream &os);

inline std::ostream& operator <<(std::ostream &out, const std::vector<Word> &sentence){
	copy(begin(sentence), end(sentence), std::ostream_iterator<Word>{out, " "});
	return out;
};

inline std::istream& operator >>(std::istream &in, std::vector<Word> &sentence){

	std::istream_iterator<Word> input{};
	std::istream_iterator<Word> eof{};
	std::string line{};

	getline(in, line);

	std::istringstream linestringstream{ line };
	sentence = std::vector<Word>{std::istream_iterator<Word> {linestringstream}, eof};

	return in;
};

#endif /* KWIC_H_ */
