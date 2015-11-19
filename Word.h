#ifndef WORD_H_
#define WORD_H_

#include <iosfwd>
#include <string>
#include <iostream>
#include <algorithm>
#include <string>

class Word{

	public:
		Word():value{""}{};

		Word( const std::string value );

		void read(std::istream &input);
		void print(std::ostream &output) const;

		//this < w
		inline bool operator <( const Word &w ) const {
			return std::lexicographical_compare(begin((*this).value), end((*this).value),begin(w.value), end(w.value), myLessThanComparator);
		}

		inline bool operator >( const Word &w ) const {
			return !((*this) < w);
		}

		inline bool operator ==( const Word &w ) const {

			std::string rightString{(*this).value};
			std::string leftString{w.value};

			transform(begin((*this).value), end((*this).value), begin(rightString), ::tolower);
			transform(begin(w.value), end(w.value),begin(leftString), ::tolower);

			return std::equal(begin(rightString), end(rightString), begin(leftString), end(leftString));
		}

		inline bool operator <=( const Word &w ) const {
			return ((*this) == w) || ((*this) < w);
		}

		inline bool operator >=( const Word &w ) const {
			return ((*this) == w) || ((*this) > w);
		}

		inline bool operator !=( const Word &w ) const {
			return !((*this) == w);
		}


	private:
		std::string value{};

		static bool myLessThanComparator (char c1, char c2){
			return std::tolower(c1) < std::tolower(c2);
		}


};

	inline std::ostream& operator<<(std::ostream& out, const Word &w){
		w.print(out);
		return out;
	};

	inline std::istream& operator>>(std::istream& in, Word &w){
		w.read(in);
		return in;
	};


#endif /* WORD_H_ */
