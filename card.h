#pragma once

#define COLOR 4

#define DECK_SIZE 36

#define WAIT_TIME 2000

#define MINIMUM_BET       10

#define LAST_CARD_IN_DECK 35
#define ONE_MORE_CARD     34
#define TWENTY_ONE        21

#define BANKERS_MINIMUM_SCORE 16

#define YES "yes"
#define NO  "no"

#define QUEEN "queen"
#define JACK "jack"
#define KING "king"
#define ACE "ace"
#define TEN "ten"
#define EIGHT "eight"
#define NINE "nine"
#define SEVEN "seven"
#define SIX "six"

#define JACK_VALUE  2
#define QUEEN_VALUE 3
#define KING_VALUE  4
#define SIX_VALUE   6
#define SEVEN_VALUE 7
#define EIGHT_VALUE 8
#define NINE_VALUE  9
#define TEN_VALUE   10 
#define ACE_VALUE   11

class Card
{
private:

	char* name;
	int value;

public:

	Card(const char* name, int value);

	Card();

	Card(const Card& other);

	~Card();

	friend std::ostream& operator<<(std::ostream& out, const Card& other);

	bool operator==(const Card& other);

	Card& operator = (const Card& other);

	int operator + (const Card& other);

	bool operator > (const int x);

	int& operator[](int size);

	int& GetValue();
};


class Jack : public Card
{
private:

public:
	Jack() : Card(JACK, JACK_VALUE) {}
	Jack(const char* name, int value) : Card(name, value) {}
};

class Queen : public Card
{
private:

public:
	Queen() : Card(QUEEN, QUEEN_VALUE) {}
	Queen(const char* name, int value) : Card(name, value) {}
};


class King : public Card
{
private:

public:
	King() : Card(KING, KING_VALUE) {}
	King(const char* name, int value) : Card(name, value) {}
};

class Six : public Card
{
private:

public:
	Six() : Card(SIX, SIX_VALUE) {}
	Six(const char* name, int value) : Card(name, value) {}
};

class Seven : public Card
{
private:

public:
	Seven() : Card(SEVEN, SEVEN_VALUE) {}
	Seven(const char* name, int value) : Card(name, value) {}
};


class Eight : public Card
{
private:

public:
	Eight() : Card(EIGHT, EIGHT_VALUE) {}
	Eight(const char* name, int value) : Card(name, value) {}
};

class Nine : public Card
{
private:

public:
	Nine() : Card(NINE, NINE_VALUE) {}
	Nine(const char* name, int value) : Card(name, value) {}
};

class Ten : public Card
{
private:

public:
	Ten() : Card(TEN, TEN_VALUE) {}
	Ten(const char* name, int value) : Card(name, value) {}
};

class Ace : public Card
{
private:

public:

	Ace() :Card(ACE, ACE_VALUE) {}

	Ace(const char* name, int value) : Card(name, value) {}
};


class CountScore
{

public:

	static int one_more;

	int add_card(Card* deck);
	int banker_play_card(Card* deck);


};