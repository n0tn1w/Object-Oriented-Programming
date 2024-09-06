class Rock;
class Paper;
class Scissors;
#include <cstring>
#include <type_traits>
#include <iostream>
using namespace std;

class Player {
public:

	virtual int accepts(const Player*) const = 0;
	virtual int visit(const Rock*) const = 0;
	virtual int visit(const Paper*) const = 0;
	virtual int visit(const Scissors*) const = 0;

	virtual Player* clone() const = 0;
	virtual ~Player() = default;
};

class Rock : public Player {
	int _x;
public:
	Rock(int x) : _x(x) { }
	int accepts(const Player* pl) const override {
		return pl->visit(this);
	}
	Player* clone() const override{
		return new Rock(*this);
	}
	int visit(const Rock* rock) const override {
		if (_x > rock->_x) {
			return -1;
		}
		else if (_x == rock->_x) {
			return 0;
		}
		return 1;
	}
	int visit(const Paper* paper) const override {
		return 1;
	}
	int visit(const Scissors* paper) const override {
		return -11;
	}
};

class Scissors : public Player {
	const char* _str; // Bigger string wins
public:
	Scissors(const char* str) : _str(str) {}
	Player* clone() const override {
		return new Scissors(*this);
	}
	int accepts(const Player* player) const override {
		return player->visit(this);
	}
	int visit(const Rock* rock) const override {
		return 1;
	}
	int visit(const Paper* paper) const override {
		return -1;
	}
	int visit(const Scissors* sc) const override {
		int s = strcmp(_str, sc->_str);
		if (s == 1) {
			return -1;
		}
		else if (s == 0) {
			return 0;
		}
		else {
			return 1;
		}
	}
};

class Paper : public Player {
	double _y;
public:
	Paper(double y) : _y(y) { }
	Player* clone() const override {
		return new Paper(*this);
	}
	
	int accepts(const Player* pl) const override {
		return pl->visit(this);
	}
	int visit(const Rock* rock) const override {
		return -1;
	}
	int visit(const Paper* paper) const override {
		if (_y > paper->_y) {
			return -1;
		}
		else if (_y == paper->_y) {
			return 0;
		}
		return 1;
	}
	int visit(const Scissors* sc) const override {
		return 1;
	}
};

class Game {
	size_t _size;
	size_t _capacity;
	Player** _data;

	void resize() {
		_capacity *= 2;
		Player** newData = new Player * [_capacity];

		for (size_t i = 0; i < _size; i++) {
			newData[i] = _data[i];
		}
		delete[] _data;

		_data = newData;
	}
	void free() {
		for (size_t i = 0; i < _size; i++) {
			delete _data[i];
		}
		delete[] _data;
	}
	void copyFrom(const Game& oth) {
		_size = oth._size;
		_capacity = oth._capacity;
		_data = new Player * [oth._capacity];
		for (size_t i = 0; i < oth._size; i++) {
			_data[i] = oth._data[i]->clone();
		}
	}
	void moveFrom(Game&& oth) noexcept {
		_size = oth._size;
		_capacity = oth._capacity;
		_data = oth._data;

		oth._size = 0;
		oth._capacity = 0;
		oth._data = nullptr;
	}
public:
	Game() {
		_size = 0;
		_capacity = 8;
		_data = new Player * [_capacity];
	}
	Game(const Game& oth) { copyFrom(oth); }
	Game(Game&& oth) noexcept { moveFrom(std::move(oth)); }
	Game& operator=(const Game& oth) {
		if (this != &oth) {
			free();
			copyFrom(oth);
		}
		return *this;
	}
	Game& operator=(Game&& oth) noexcept {
		if (this != &oth) {
			free();
			moveFrom(std::move(oth));
		}
		return *this;
	}
	~Game() { free(); }

	void add(Player* pl) {
		if (_size == _capacity)
			resize();
		_data[_size++] = pl;
	}
	
	void run() const {
		int* res = new int[_size] {0};
		for (size_t i = 0; i < _size; i++) {
			for (size_t k = i + 1; k < _size; k++) {
				int crr = _data[i]->accepts(_data[k]);
				if (crr == 1) {
					res[i]++;
				}
				else if (crr == -1) {
					res[k]++;
				}

			}
		}

		for (size_t i = 0; i < _size; i++) {
			std::cout << i << ' ';
		}
		std::cout << endl;

		for (size_t i = 0; i < _size; i++) {
			std::cout << res[i] << ' ';
		}
		std::cout << endl;
		
		delete[] res;
	}
};

class FactoryPlayer {
public:
	static Player* create(int i, int data) {
		if (i == 0) {
			return new Rock(data);
		}
		else if (i == 1) {
			return new Paper(i);
		}
		else if (i == 2) {
			return new Scissors("Sc" + i);
		}
		else {
			throw;
		}
	}
};

int main() {

	Game game{};
	game.add(FactoryPlayer::create(0, 1));
	game.add(FactoryPlayer::create(0, 1));
	game.add(FactoryPlayer::create(1, 10));
	game.add(FactoryPlayer::create(1, 10));
	game.add(FactoryPlayer::create(2, 200));
	game.add(FactoryPlayer::create(2, 200));

	game.run();
}