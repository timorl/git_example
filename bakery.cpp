#include<iostream>
#include<vector>

void say(std::string message) {
	std::cout << message << std::endl;
}

int ask(std::string question, std::vector<std::string> answers) {
	int answer = 0;
	while (true) {
		say(question);
		for (int i = 0; i < answers.size(); i++) {
			std::cout << i+1 << ". " << answers[i] << std::endl;
		}
		std::cin >> answer;
		if (answer > 0 && answer <= answers.size()) {
			return answer;
		}
		say("That is not one of the options!");
	}
}

class Cake {
	public:
		Cake(int w, int l) {
			width = w;
			length = l;
		}

		void eat() {
			say("What delicious cake!");
		}

		void admire() {
			say("This cake looks great!");
			std::cout << "All " << area() << " square centimeters of it." << std::endl;;
		}

	private:
		int area() {
			return width*width;
		}

		int width;
		int length;
};

class Bakery {
	public:
		Cake * bake(int width, int length) {
			say("Baking a cake!");
			return new Cake(width, length);
		}
};

int main() {
	Bakery theBakery;
	say("Welcome to the bakery, friend!");
	std::vector<std::string> yesOrNo;
	yesOrNo.push_back("Yes");
	yesOrNo.push_back("No");
	std::vector<std::string> sizes;
	sizes.push_back("Tiny (10cm)");
	sizes.push_back("Small (20cm)");
	sizes.push_back("Standard (30cm)");
	sizes.push_back("Big (40cm)");
	sizes.push_back("Huge (50cm)");
	sizes.push_back("X-Treme (60cm)");
	std::vector<std::string> cakeActions;
	cakeActions.push_back("Admire...");
	cakeActions.push_back("Eat!");
	while (true) {
		if (ask("Do you want a cake?", yesOrNo) == 2) {
			say("Bye then!");
			return 0;
		}
		int width = ask("What width?", sizes) * 10;
		int length = ask("What length?", sizes) * 10;
		Cake * theCake = theBakery.bake(width, length);
		while (theCake) {
			int answer = ask("What do you want to do with the cake?", cakeActions);
			if ( answer == 1 ) {
				theCake->admire();
			} else if ( answer == 2 ) {
				theCake->eat();
				delete theCake;
				theCake = 0;
			}
		}
	}
}
