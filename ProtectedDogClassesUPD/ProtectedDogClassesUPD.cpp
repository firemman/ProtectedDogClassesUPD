#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Collar {
public:
	void numHoz() { cout << "Вывод номера владельца собаки с ошейника. \n"; }
};

class Dog {
public:
	void run() {
		feet.run();
		head.eat();
	}
	Dog() { color = "empty"; razmer = "empty"; }
	Dog(string color, string razmer) { this->color = color; this->razmer = razmer; }

	void setColor(string color) { this->color = color; }
	void setRazmer(string razmer) { this->razmer = razmer; }

	string getColor() { return color; }
	string getRazmer() { return razmer; }

protected:
	string color, razmer;

	class Feet {
	public:
		void run() { cout << "Собака бежит... \n"; }
	};

	class Head {
	public:
		void eat() { cout << "Собака ест... \n"; }
	};

	Feet feet;
	Head head;
};

class HomeDog : public Dog {
public:
	HomeDog() : Dog() { klichka = "empty"; }
	HomeDog(string color, string razmer, string klichka) : Dog(color, razmer) { this->klichka = klichka; }

	void setKlichka(string klichka) { this->klichka = klichka; }
	string getKlichka() { return klichka; }

	Collar collar;

	void run() {
		feet.run();
		head.eat();
		collar.numHoz();
	}
private:
	string klichka;
};

int main() {
	setlocale(LC_ALL, "rus");

	HomeDog	d1("White", "Middle", "Zhychka");
	d1.setColor("Black");

	cout << "Кличка: " << d1.getKlichka() << "\nЦвет: " << d1.getColor() << "\nРазмер: " << d1.getRazmer() << "\n\n";
	d1.run();
}