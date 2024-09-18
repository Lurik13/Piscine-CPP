#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    try
    {
        BitcoinExchange bitcoin_exchange(argc, argv);
        bitcoin_exchange.bitcoin_algorithm();
    }
    catch(const std::exception& e)
    {
        std::cerr << ERROR << e.what() << '\n';
    }
}
