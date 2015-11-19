
#ifndef KWIC_H_
#define KWIC_H_

#include <set>
#include <vector>
#include <iterator>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "Word.h"

std::set<std::vector<Word>> rotate(std::istream &is, std::ostream &os);

#endif /* KWIC_H_ */
