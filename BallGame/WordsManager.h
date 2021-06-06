#ifndef __WORDS_MANAGER__
#define __WORDS_MANAGER__
#include "Word.h"
class WordsManager
{
	Word wordsField[10];
public:
	WordsManager();
	void generate();
	void draw();
	void update();
};
#endif
