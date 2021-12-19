#include <iostream>
#include <array>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <initializer_list>
#include "Chrono.cpp"  

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

class Creature
{
protected:

	std::string m_name;
	char m_symb;
	int m_health;
	int m_attacked;
	int m_haveGold;

public:

	Creature(std::string name, char symb, int health, int attacked, int haveGold)
		: m_name(name), m_symb(symb), m_health(health), m_attacked(attacked), m_haveGold(haveGold)
	{
	}

	const std::string& getName() { return m_name; }
	char getSymbol() { return m_symb; }
	int getHealth() { return m_health; }
	int gethAttacked() { return m_attacked; }
	int getGold() { return m_haveGold; }

	void reduceHealth(int health) 
	{ 
		m_health -= health;
	}

	bool isDead() 
	{
		if (m_health <= 0)
		{
			return true;
		}
		else {
			return false;
		}
	}

	void addGold(int gold)
	{
		m_haveGold += gold;
	}
};

class Player : public Creature
{
private:
	int m_level = 1;

public:

	Player(std::string name="qwerty")
		: Creature(name, '@', 100, 10, 0)
	{
		std::cout << "Enter you name: \n";
		std::cin >> m_name;
		std::cout << "Welcome " << m_name << "\n";
	}

	void levelUp()
	{
		++m_level;
		m_attacked += 3;
		m_health += 15;
	}
	
	int getPlayerLevel() { return m_level; }
	bool hasWon() { return m_level >= 20; }

	friend std::ostream& operator<< (std::ostream& out, const Player& player)
	{
		out << "\n" << player.m_name << " symb - " << player.m_symb << "\n" <<
			"You " << "Level - " << player.m_level << "; Health - " << player.m_health << "; Attacked - " << player.m_attacked <<
			"; Gold - " << player.m_haveGold << "\n";
		return out;
	}
};

class Monster : public Creature
{
public:

	enum Type
	{
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES
	};

	struct MonsterData
	{
		std::string name;
		char symbol;
		int health;
		int attacked;
		int gold;
	};

	static MonsterData monsterData[MAX_TYPES];

	Monster(Type type) : 
		Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health, 
			monsterData[type].attacked, monsterData[type].gold)
	{
	}

	static Monster getRandomMonster()
	{
		int num = getRandomNumber(0, MAX_TYPES - 1);
		return Monster(static_cast<Type>(num));
	}
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "DRAGON", 'D', 200, 20, 200 },
	{ "ORC", 'O', 95, 8, 50 }, 
	{ "SLIME", 'S', 15, 5, 10 }
};

void attackMonster(Monster& m, Player& p)
{
	m.reduceHealth(p.gethAttacked());

	if (m.isDead() == true)
	{
		p.addGold(m.getGold());
		std::cout << "You killed this monster, great you LEVEL UP" << std::endl;
		p.levelUp();
		std::cout << p;
	}
}

void attackPlayer(Monster& m, Player& p)
{
	p.reduceHealth(m.gethAttacked());

	if (p.isDead() == true)
	{
		std::cout << "You were killed by a monster - YOU LOSE" << std::endl;
		std::cout << p;
	}
}

bool fightMonster(Player& p)
{
	while (1)
	{
		Monster m = Monster::getRandomMonster();
		std::cout << "\n" << p.getName() << " you have encountered a " << m.getName() << "\n";
		char choice;
		std::cout << "Run (r) or fight (f) ? - ";
		std::cin >> choice;

		if (choice == 'r')
		{
			switch (m.getSymbol())
			{
			case 'D':
			{
				int runner = getRandomNumber(0, 1);
				if (runner == 0)
				{
					std::cout << "\nit was difficult to escape from the " << m.getName() << "you took damage from it\n";
					p.reduceHealth(m.gethAttacked());
					std::cout << "You health now - " << p.getHealth() << "\n";
				}
				else
				{
					std::cout << "Managed to escape\n";
				}
				break;
			}
			case 'O':
			{
				int runner = getRandomNumber(0, 2);
				if (runner == 1)
				{
					std::cout << "\nit was difficult to escape from the " << m.getName() << "you took damage from it\n";
					p.reduceHealth(m.gethAttacked());
					std::cout << "You health now - " << p.getHealth() << "\n";
				}
				else
				{
					std::cout << "Managed to escape\n";
				}
				break;
			}
			case 'S':
			{
				int runner = getRandomNumber(0, 3);
				if (runner == 2)
				{
					std::cout << "\nit was difficult to escape from the " << m.getName() << "you took damage from it\n";
					p.reduceHealth(m.gethAttacked());
					std::cout << "You health now - " << p.getHealth() << "\n";
				}
				else
				{
					std::cout << "Managed to escape\n";
				}
				break;
			}
			default:
			{
				break;
			}
			}

			if (p.getHealth() <= 0)
			{
				std::cout << "\nYOU LOSE\n";
				return false;
			}
		} // Ветвление выбора 'r' -> Run (r) or fight (f)?

		if (choice == 'f') // Ветвление выбора 'r' -> Run (r) or fight (f)?
		{
			std::cout << "\nYou took a fight with a monster\n";
			while (true)
			{
				attackMonster(m, p);
				if (m.getHealth() <= 0)
				{
					return true;
				}
				attackPlayer(m, p);
				if (p.getHealth() <= 0)
				{
					std::cout << "\nYOU LOSE\n";
					return false;
				}
			}
			if (p.getPlayerLevel() >= 20)
			{
				std::cout << "GREAT, you have max level - 20\n" << "YOU WON\n";
			}
		} // Ветвление выбора 'r' -> Run (r) or fight (f)?
	}
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	rand();

	Player p;
	std::cout << p << std::endl;
	std::cout << "DRAGON - the strongest is better to avoid him up to level 7-8 approximately, ORK - you can kill at once but only one, two in a row is death, SLIME is the weakest kill him always\n";

	while (p.getHealth() > 0 && p.getPlayerLevel() < 20)
	{
		fightMonster(p);
	}

	return 0;
}


