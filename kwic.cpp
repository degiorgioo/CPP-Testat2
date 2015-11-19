#include "kwic.h"
#include "Word.h"
#include <set>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>

inline std::ostream& operator <<(std::ostream &out, const std::set<std::vector<Word>> &sentences){
	for(auto sentence: sentences){
		copy(begin(sentence), end(sentence), std::ostream_iterator<Word>{out, " "});
		out << "\n";
	}
	return out;
};

inline std::ostream& operator <<(std::ostream &out, const std::vector<Word> &sentence){
	copy(begin(sentence), end(sentence), std::ostream_iterator<Word>{out, " "});
	return out;
};

inline std::istream& operator >>(std::istream &in, std::vector<Word> &sentence){

	std::istream_iterator<Word> eof{};
	std::string line{};
	std::string templine{};

	while(getline(in, line)){
		std::istringstream linestringstream{ line };
		sentence = std::vector<Word>{std::istream_iterator<Word> {linestringstream}, eof};
	}
	return in;
};

std::set<std::vector<Word>> rotate(std::istream &in, std::ostream &out){

	std::set<std::vector<Word>> allLines{};
	std::set<std::vector<Word>> result{};
	std::istream_iterator<Word> eof{};
	std::string line{};

	while(getline(in, line)){
		std::istringstream linestringstream{ line };
		allLines.insert(begin(allLines), std::vector<Word>{std::istream_iterator<Word> {linestringstream}, eof});
	}

	for(auto line: allLines){
		for(auto word: line){
			rotate(begin(line), begin(line) + 1, end(line));
			result.insert(line);
		}
	}

	out << result;

	return result;
}
