// WordCount.cpp

#include "WordCount.h"
#include <algorithm>
using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int total = 0;
	for(size_t i = 0; i<CAPACITY;i++){
		for(auto const &a:table[i]){
			total+= a.second;
		}
	}
	return total;
}

int WordCount::getNumUniqueWords() const {
	int uniqueCount = 0;
	for (size_t i = 0; i < CAPACITY; i++) {
		uniqueCount += table[i].size();
	}
	return uniqueCount;
}

int WordCount::getWordCount(std::string word) const {
	word = makeValidWord(word);
	if (word == "") {
		return 0;
	}
	size_t index = hash(word);
	for (auto const &a: table[index]) {
		if (a.first == word) {
			return a.second;
		}
	}
	return 0;
}
	
int WordCount::incrWordCount(std::string word) {
	word = makeValidWord(word);
	if (word == "") {
		return 0; 
	}
	size_t index = hash(word);
	for (auto &a : table[index]) {
		if (a.first == word) {
			a.second += 1;
			return a.second;
		}
	}
	table[index].push_back(make_pair(word, 1));
	return 1;
}

int WordCount::decrWordCount(std::string word) {
	word = makeValidWord(word);
	if (word == "") {
		return -1; 
	}
	size_t index = hash(word);
	for (size_t i = 0; i < table[index].size(); i++) {
		if (table[index][i].first == word) {
			table[index][i].second -= 1;
			if (table[index][i].second <= 0) {
				table[index].erase(table[index].begin() + i);
				return 0;
			}
			return table[index][i].second;
		}
	}
	return -1; 
}

bool WordCount::isWordChar(char c) {
	return isalpha(static_cast<unsigned char>(c)) || c == '\'' || c=='\'' || c == '-';
}

std::string WordCount::makeValidWord(std::string word) {
	std::transform(word.begin(), word.end(), word.begin(),
	               [](unsigned char c){ return std::tolower(c); });
	while (!word.empty() && !isWordChar(word.front())) {
		word.erase(word.begin());
	}
	while (!word.empty() && !isWordChar(word.back())) {
		word.pop_back();
	}
	std::string result;
	
	for (size_t i = 0; i < word.size(); ++i) {
        char c = word[i];
        if (isalpha(c)) {
            result.push_back(c);
        }
        else if ((c == '-' || c == '\'') && i > 0 && i < word.size() - 1 &&
                 isalpha(word[i - 1]) && isalpha(word[i + 1])) {
            result.push_back(c);
        }
    }
	return result;
}
