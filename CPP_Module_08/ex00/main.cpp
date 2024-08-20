#include "easyfind.hpp"

int main (void)
{
	{
		std::vector<int> int_vec;
		for (int i = 0; i < 5; ++i) { int_vec.push_back(i); }
		std::vector<int>::iterator it;

		{
			int number_to_find = 10;
			std::cout << BLUE "Essai avec un " INVERT "int" BLUE " " UNDERLINED
			<< "introuvable" BLUE " (" << number_to_find << "): " RESET << std::endl;

			it = std::find(int_vec.begin(), int_vec.end(), number_to_find);
			if (it != int_vec.end())
				std::cout << "find: Element trouve : " << *it << std::endl;
			else
				std::cout << "find: Mais ou est passe cet element ? O_o" << std::endl;

			it = easyfind(int_vec, number_to_find);
			if (it != int_vec.end())
				std::cout << "easyFind: Element trouve : " << *it << std::endl;
			else
				std::cout << "easyFind: Mais ou est passe cet element ? O_o" << std::endl;
		}
		{
			int number_to_find = 2;
			std::cout << BLUE "\nEssai avec un " INVERT "int" BLUE " " UNDERLINED
			<< "trouvable" BLUE " (" << number_to_find << "): " RESET << std::endl;

			it = std::find(int_vec.begin(), int_vec.end(), number_to_find);
			if (it != int_vec.end())
				std::cout << "find: Element trouve : " << *it << std::endl;
			else
				std::cout << "find: Mais ou est passe cet element ? O_o" << std::endl;

			it = easyfind(int_vec, number_to_find);
			if (it != int_vec.end())
				std::cout << "easyFind: Element trouve : " << *it << std::endl;
			else
				std::cout << "easyFind: Mais ou est passe cet element ? O_o" << std::endl;
		}
	}

	{
		std::vector<std::string> string_vec;
		string_vec.push_back("hey");
		string_vec.push_back("coucou");
		string_vec.push_back("salut");
		std::vector<std::string>::iterator it;

		{
			std::string string_to_find = "bonsoir";
			std::cout << BLUE "\n\nEssai avec une " INVERT "string" BLUE " " UNDERLINED
			<< "introuvable" BLUE " (\"" << string_to_find << "\"): " RESET << std::endl;

			it = std::find(string_vec.begin(), string_vec.end(), string_to_find);
			if (it != string_vec.end())
				std::cout << "find: Element trouve : " << *it << std::endl;
			else
				std::cout << "find: Mais ou est passe cet element ? O_o" << std::endl;

			it = better_easyfind(string_vec, string_to_find);
			if (it != string_vec.end())
				std::cout << "better_easyFind: Element trouve : " << *it << std::endl;
			else
				std::cout << "better_easyFind: Mais ou est passe cet element ? O_o" << std::endl;
		}
		{
			std::string string_to_find = "hey";
			std::cout << BLUE "\nEssai avec une " INVERT "string" BLUE " " UNDERLINED
			<< "trouvable" BLUE " (\"" << string_to_find << "\"): " RESET << std::endl;

			it = std::find(string_vec.begin(), string_vec.end(), string_to_find);
			if (it != string_vec.end())
				std::cout << "find: Element trouve : " << *it << std::endl;
			else
				std::cout << "find: Mais ou est passe cet element ? O_o" << std::endl;

			it = better_easyfind(string_vec, string_to_find);
			if (it != string_vec.end())
				std::cout << "better_easyFind: Element trouve : " << *it << std::endl;
			else
				std::cout << "better_easyFind: Mais ou est passe cet element ? O_o" << std::endl;
		}
	}
}
