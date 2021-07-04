#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<WIndows.h>
#include "resource.h"
#include "card.h"

Card::Card() : name{ nullptr }, value(0) {}

Card::Card(const char* name, int value): name{new char[strlen(name)+1]}, value(value)
{
	strcpy(this->name, name);
}

Card::~Card()
{
	delete[] name;
}


Card::Card(const Card& other)
{
	this->name = new char[strlen(other.name)+1];
	strcpy(this->name, other.name);

	this->value = other.value;
}

Card& Card::operator = (const Card& other)
{
	if (*this == other)
	{
		return *this;
	}

	if (this->name != nullptr)
	{
		delete[] this->name;
	}

	name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);

	this->value = other.value;

	return *this;
}

int& Card::GetValue()
{
	return this->value;
}

bool Card::operator==(const Card& other)
{
	return strcmp(this->name, other.name) == 0 and this->value == other.value;
}


std::ostream& operator<<(std::ostream& out, const Card& other)
{
	out << other.name << " value " << other.value << std::endl;
	return out;
}

int Card::operator + (const Card& other)
{
	return this->value + other.value;
	
}

bool Card::operator >(const int x)
{
	return this->value > x;
}


int& Card::operator[](int size)
{
	return this->value;
}

//global variable for the current lowest card 

int CountScore::add_card(Card *deck)
{
	one_more = ONE_MORE_CARD;

	char answer[CHAR_MAX];

	int score = deck[LAST_CARD_IN_DECK].GetValue();

	while (true)
	{
		std::cout << "\nYou want to take another card ?(type 'yes' or 'no') \n";

		std::cin.getline(answer, CHAR_MAX);

		Sleep(WAIT_TIME);

		bool choice;

		if(strcmp(answer, YES) == 0)
		{
				std::cout << "You receive one more card\n";
				std::cout << deck[one_more];
				Sleep(WAIT_TIME);
				score += deck[one_more--].GetValue();
				std::cout << "Your score now is -> " << score;
				Sleep(WAIT_TIME);
		}
		else if(strcmp(answer, NO) == 0)
		{
			
			break;
			
		}

		if (score == TWENTY_ONE)
		{
			std::cout << "\nYou`ve won 21!\n";
			Sleep(WAIT_TIME);
			std::cout << "Now the bank will play\n";
			Sleep(WAIT_TIME);
			std::cout << "If bank score 21, bnk wins and takes your money\n";
			Sleep(WAIT_TIME);
			return TWENTY_ONE;
			break;
		}
		else if (score > TWENTY_ONE)
		{
			std::cout << "\nYou`ve lost brotha\n";
			Sleep(WAIT_TIME);
			return score;
			break;
		}
	}

	return score;
}

int CountScore::banker_play_card(Card* deck)
{
	int bankers_score = deck[one_more].GetValue();
	Sleep(WAIT_TIME);
	std::cout << "Banker is supoosed to take cards until he is over "<< BANKERS_MINIMUM_SCORE << std::endl;
	Sleep(WAIT_TIME);
	std::cout << "Bankers card -> " << deck[one_more];

	while (bankers_score <= BANKERS_MINIMUM_SCORE)
	{
		bankers_score += deck[--one_more].GetValue();
		Sleep(WAIT_TIME);
		std:: cout << "Banker received new card -> " << deck[one_more];
		Sleep(WAIT_TIME);
		std::cout << "Bankers score -> " << bankers_score<<std::endl;

		if (bankers_score > TWENTY_ONE)
		{
			std::cout << "Bankers lost\n";
			return -1;
			break;
		}
		else if (bankers_score == TWENTY_ONE)
		{
			std::cout << "Bankers got 21. Bankers win!\n";
			break;
		}

	}

	return bankers_score;

}