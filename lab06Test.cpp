#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>

using namespace std;

int main() {
    WordCount wc;

    ASSERT_EQUALS(0, wc.getTotalWords());
    ASSERT_EQUALS(0, wc.getNumUniqueWords());

    wc.incrWordCount("hello");
    ASSERT_EQUALS(1, wc.getTotalWords());
    ASSERT_EQUALS(1, wc.getNumUniqueWords());
    ASSERT_EQUALS(1, wc.getWordCount("hello"));

    wc.incrWordCount("world");
    ASSERT_EQUALS(2, wc.getTotalWords());
    ASSERT_EQUALS(2, wc.getNumUniqueWords());

    wc.incrWordCount("hello");
    ASSERT_EQUALS(3, wc.getTotalWords());
    ASSERT_EQUALS(2, wc.getNumUniqueWords());

    wc.incrWordCount("HELLO");
    ASSERT_EQUALS(4, wc.getTotalWords()); 
    ASSERT_EQUALS(2, wc.getNumUniqueWords());
    ASSERT_EQUALS(3, wc.getWordCount("hello"));

    wc.decrWordCount("hello");
    ASSERT_EQUALS(3, wc.getTotalWords());
    ASSERT_EQUALS(2, wc.getNumUniqueWords());
    ASSERT_EQUALS(2, wc.getWordCount("hello"));

    wc.decrWordCount("hello");
    wc.decrWordCount("hello"); 
    ASSERT_EQUALS(1, wc.getTotalWords());
    ASSERT_EQUALS(1, wc.getNumUniqueWords());
    ASSERT_EQUALS(0, wc.getWordCount("hello"));

    
    ASSERT_EQUALS("hello", wc.makeValidWord("hello!"));
    ASSERT_EQUALS("hello", wc.makeValidWord("...hello"));
    ASSERT_EQUALS("hello", wc.makeValidWord("'hello'"));
    ASSERT_EQUALS("it's", wc.makeValidWord("It's"));
    ASSERT_EQUALS("", wc.makeValidWord("!@#$%^&*"));

    cout << "All tests passed!" << endl;
    return 0;
}
