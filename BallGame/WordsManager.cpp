#include "Headers.h"
extern Ball ball;
extern bool gameover;
extern string input;
WordsManager::WordsManager()
{
	// Reading 10 words from file
	ifstream in("Words.txt", ios::in);
	for (int i = 0; i < 10; i++)
	{
		string temp;
		in >> temp;
		wordsField[i].set(temp);
	}
	in.close();
}
void WordsManager::generate()
{
	// Generating random word from 10 words
	while (1)
	{
		int i = rand() % 10;
		if (!wordsField[i].isActive())
		{
			wordsField[i].active();
			wordsField[i].setXY(rand() % 590, 675 - rand() % 630);
			break;
		}
	}
		
}

void WordsManager::update()
{
	for (int i = 0; i < 10; i++)
	{
		if (wordsField[i].isActive())
		{
			// Checking if the user enters a valid word
			if (input == wordsField[i].get())
			{
				wordsField[i].deactive();
				input.clear();
				break;
			}

			// Checking for word - ball collision
			if (ball.getX() + ball.getRadius() >= wordsField[i].getX() &&
				ball.getX() - ball.getRadius() <= wordsField[i].getX() + wordsField[i].getWidth() &&
				ball.getY() + ball.getRadius() >= wordsField[i].getY() &&
				ball.getY() - ball.getRadius() <= wordsField[i].getY() + wordsField[i].getHeight())
			{
				gameover = true;
				break;
			}
		}
	}
}
void WordsManager::draw()
{
	for (int i = 0; i < 10; i++)
	{
		if (wordsField[i].isActive())
		{
			Draw::setColor(1,1,1);
			Draw::rectangle(wordsField[i].getX(), wordsField[i].getY(), 110, 45);
			Text::render(wordsField[i].getX(), wordsField[i].getY(), wordsField[i].get());
		}
	}
}