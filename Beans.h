#include <iostream>
#include <string>
#include <map>
#include <exception>

class Card {
protected:
    // The map associates the certain number of coins earned with the number of cards needed
    // <number of coins,number of bean cards required to collect corresponding number of coins>

	std::map<int, int> m_cardMap;
public:
	Card() = default;
	virtual ~Card() = default;
	Card(const Card&) = delete;
	Card& operator=(const Card&) = delete;

	virtual int getCardsPerCoin(int coins) = 0;

	virtual std::string getName() const = 0;

	virtual void print(std::ostream& out) = 0;

	friend std::ostream& operator<<(std::ostream& os, Card& beanCard);
};

class Blue : public Card {
	friend class CardFactory;
private:
	Blue();
public:
	int getCardsPerCoin(int coins) override;

	std::string getName() const override;

	void print(std::ostream& out) override;
};

class Chili : public Card {
	friend class CardFactory;
private:
	Chili();
public:
	int getCardsPerCoin(int coins) override;

	std::string getName() const override;

	void print(std::ostream& out) override;
};

class Stink : public Card {
	friend class CardFactory;
private:
	Stink();
public:
	int getCardsPerCoin(int coins) override;

	std::string getName() const override;

	void print(std::ostream& out) override;
};

class Green : public Card {
	friend class CardFactory;
private:
	Green();
public:
	int getCardsPerCoin(int coins) override;

	std::string getName() const override;

	void print(std::ostream& out) override;
};

class Soy : public Card {
	friend class CardFactory;
private:
	Soy();
public:
	int getCardsPerCoin(int coins) override;

	std::string getName() const override;

	void print(std::ostream& out) override;
};

class Black : public Card {
	friend class CardFactory;
private:
	Black();
public:
	int getCardsPerCoin(int coins) override;

	std::string getName() const override;

	void print(std::ostream& out) override;
};

class Red : public Card {
	friend class CardFactory;
private:
	Red();
public:
	int getCardsPerCoin(int coins) override;

	std::string getName() const override;

	void print(std::ostream& out) override;
};

class Garden : public Card {
	friend class CardFactory;
private:
	Garden();
public:
	int getCardsPerCoin(int coins) override;

	std::string getName() const override;

	void print(std::ostream& out) override;
};

class IllegalType : private std::exception {
public:
	std::string showMessage();
};
