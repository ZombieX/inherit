
#include<iostream>
#include<utility>

class animal {
public:
	virtual void bark()const = 0;
};
class cat : public animal{
public:
	void meow()const {
		std::cout << "meow\n";
	}
	auto bark()const->decltype(std::declval<animal>().bark()) override {
		meow();
	}
};
class dog:public animal{
public :
	void roar()const{
		std::cout << "BowBow!\n";
	}
	auto bark()const->decltype(std::declval<animal>().bark()) override {
		roar();
	}
};


class static_animal{
public:
	virtual void bark()const = 0;
};

template<class T>
class template_animal{};

int main() {
	dog d;
	cat c;
	d.roar();
	c.meow();


	animal* ap = &d;
	ap->bark();

	ap = &c;
	ap->bark();


	return 0;
}