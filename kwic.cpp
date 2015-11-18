#include "kwic.h"
#include "Word.h"
#include <set>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>

std::set<std::vector<Word>> rotate(std::istream &in, std::ostream &out){

	std::istream_iterator<Word> input{in};
	std::istream_iterator<Word> eof{};

	std::vector<Word> words{input, eof};

	std::set<std::vector<Word>> result{};

	for(auto word: words){
		rotate(begin(words), begin(words) + 1, end(words));
		result.insert(words);
	}
	return result;
}
