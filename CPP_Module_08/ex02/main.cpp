#include "MutantStack.hpp"
#include "MutantStack.tpp"

int main()
{
	{
		std::cout << TOP LEFT "                   " PURPLE "Tests with our MutantStack:" RESET
		<< "                   " RIGHT "\n" LEFT EMPTY_LINE RIGHT << std::endl;

		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << LEFT "Valeur du haut apres avoir push 5 et 17: " RESET
		<< mstack.top() << "                      " RIGHT << std::endl;

		mstack.pop();
		std::cout << LEFT "Taille de la pile apres avoir retire la valeur du haut: " RESET
		<< mstack.size() << "        " RIGHT << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		std::cout << LEFT EMPTY_LINE RIGHT "\n"
		<< LEFT "On empile 4 autres valeurs.                                      " << RIGHT << std::endl;

		std::cout << LEFT "Affichage de la pile en utilisant notre iterator: " RESET;
		MutantStack<int>::iterator first = mstack.begin();
		MutantStack<int>::iterator last = mstack.end();
		++first;
		--first;
		while (first != last)
		{
			std::cout << *first;
			++first;
			if (first != last)
				std::cout << "; ";
		}
		std::cout << RIGHT << std::endl << MIDDLE;
	}
	{
		std::cout << LEFT "                       " PURPLE "Tests with a list:" RESET
		<< "                        " RIGHT "\n" LEFT EMPTY_LINE RIGHT << std::endl;

		std::list<int> mlist;
		mlist.push_back(5);
		mlist.push_back(17);
		std::cout << LEFT "Valeur du haut apres avoir push 5 et 17: " RESET
		<< mlist.back() << "                      " RIGHT << std::endl;

		mlist.pop_back();
		std::cout << LEFT "Taille de la pile apres avoir retire la valeur du haut: " RESET
		<< mlist.size() << "        " RIGHT << std::endl;
		
		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(0);
		std::cout << LEFT EMPTY_LINE RIGHT "\n"
		<< LEFT "On empile 4 autres valeurs.                                      " << RIGHT << std::endl;

		std::cout << LEFT "Affichage de la pile en utilisant notre iterator: " RESET;
		int size = mlist.size();
		while (size)
		{
			std::cout << mlist.front();
			mlist.pop_front();
			size--;
			if (size)
				std::cout << "; ";
		}
		std::cout << RIGHT << std::endl << BOTTOM;
	}
	return 0;
}

