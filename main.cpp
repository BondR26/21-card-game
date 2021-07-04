#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "resource.h"
#include "card.h"
#include <ctime>
#include <Windows.h>

#pragma comment (lib, "winmm.lib")

template<typename Pack>
void shuffle_card(Pack* deck, size_t size_of_deck)
{
	for (int i = 0; i < size_of_deck; i++)
	{
		int index = rand() % size_of_deck;

		std::swap(deck[i], deck[index]);
	}
}

int CountScore::one_more = 0;//to count score of first player than the banker


int main(int argc, char* argv[])
{
	srand(time(0));

	PlaySound(MAKEINTRESOURCE(ost_sound), NULL , SND_RESOURCE | SND_ASYNC | SND_LOOP);

	Card deck[DECK_SIZE]{ Ace(), Ace(),Ace(),Ace(),
		King(),King(), King(), King(),
		Queen(), Queen(), Queen(), Queen(),
		Jack(),Jack(),Jack(),Jack(),
		Ten(),Ten(),Ten(),Ten(),
		Nine(),Nine(),Nine(),Nine(),
		Eight(),Eight(),Eight(),Eight(),
		Seven(),Seven(),Seven(),Seven(),
		Six(),Six(),Six(),Six() };

	CountScore countscore;

	static int score = 0;
	static int bankers_score = 0;
	static int money = 50;
	static int bank = 100;


	std::cout << "You are playing against the bank\n";
	Sleep(WAIT_TIME);
	std::cout << "The bank for today is " << bank << " dollars\n";
	Sleep(WAIT_TIME);
	std::cout << "The minimum bet is "<< MINIMUM_BET <<" dollars!\n";
	Sleep(WAIT_TIME);
	std::cout << "Sometime or another bank will opt to play agianst you! So be prepared\n";
	Sleep(WAIT_TIME);
	std::cout << "Good luck\n";
	Sleep(WAIT_TIME);
	
	

	while (true)//main game cycle
	{
		rewind_the_game:

		system("CLS");
		
		std::cout << "Your bank is "<< money << " dollars!\n";
		Sleep(WAIT_TIME);

		std::cout << "Bank is shuffling cards \n";
		shuffle_card(deck, DECK_SIZE);

		Sleep(WAIT_TIME);

		std::cout << "Your first card is " << deck[LAST_CARD_IN_DECK];

		score = deck[LAST_CARD_IN_DECK].GetValue();
		
		Sleep(WAIT_TIME);

		std::cout << "Please enter how much do you want to bet __\b\b";

		int bet;

	here://operator goto is very dangerous i know
		try
		{
			
			std::cin >> bet;
			throw(bet);
		}
		catch(int bet_)
		{
			if (bet_ < 10 || bet_> 50)
			{
				std::cout << "Please bet more than 10$, but less than 50\n";
				goto here;
			}
		}

		Sleep(WAIT_TIME);
		std::cout << "Good you bet " << bet << " dollar, mi boy\n";


		std::cin.ignore();//after firs cin there is still new line character in buffer so in order to prevent it from messing up my program iam using cin.ignore

		score = countscore.add_card(deck);

		if (score > 0 and score <= TWENTY_ONE)
		{
			bankers_score = countscore.banker_play_card(deck);

			if (score > bankers_score)
			{
				Sleep(WAIT_TIME);
				std::cout << "Banker scored less than you \n";
				Sleep(WAIT_TIME);
				std::cout << "You won " << 2 * bet << " dollars, amigo\n";

				money += bet;
				bank -= bet;

				Sleep(WAIT_TIME);
			}
			else if(bankers_score >= score)
			{
				Sleep(WAIT_TIME);
				std::cout << "Bankers takes your money \n";
				bank += bet;
				money -= bet;
			}

		}
		else if(score > TWENTY_ONE)
		{
			Sleep(WAIT_TIME);
			std::cout << "Bankers takes your money \n";
			Sleep(WAIT_TIME);
			bank += bet;
			money -= bet;
		}

		Sleep(WAIT_TIME);
		
		if (money < 0 || money < MINIMUM_BET)
		{
			std::cout << "You`ve got no money to make a bet\n";
			std::cout << "The game is over for you\n";
			break;
		}
		
		if (bank < 0 || bank < MINIMUM_BET)
		{
			std::cout << "Bank has no more money\n";
			break;
		}

		/// <summary>
		/// 
		/// </summary>
		/// <param name="argc"></param>
		/// <param name="argv"></param>
		/// <returns></returns>
		/// 
		system("CLS");
		char buffer[CHAR_MAX];

		std::cout << "Now you have " << money << " dollars left\n";
		Sleep(WAIT_TIME);
		std::cout << "Bank has " << bank << " dollar left\n";
		std::cout << "You want to play one more game? type('yes' or 'no')\n";

		std::cin.getline(buffer, CHAR_MAX);
		if (strcmp(buffer, "yes") == 0)
		{
			Sleep(WAIT_TIME);
			std::cout << "Thats great, lets start another one\n";
			Sleep(WAIT_TIME);
			score = 0;
			goto rewind_the_game;
		}
		else
		{
			system("CLS");
			Sleep(WAIT_TIME);
			std::cout << "Any trouble boy?\n";
			Sleep(WAIT_TIME);
			std::cout << "No, old man . Thought i was having trouble with my adding\n";
			Sleep(WAIT_TIME);
			break;
		}


	}


	

	return EXIT_SUCCESS;
}