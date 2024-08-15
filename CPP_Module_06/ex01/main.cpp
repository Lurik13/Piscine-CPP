#include "Serializer.hpp"

int main(int argc, char **argv)
{
	
	if (argc != 2 || static_cast<std::string>(argv[1]).find_first_not_of("0123456789") != std::string::npos)
	{
		std::cout << "\e[38;2;170;0;0;1mWrong params.\e[0m" << std::endl;
		return (EXIT_FAILURE);
	}
	Data data;
	data.value = atoi(argv[1]);

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized data: " << raw << std::endl;
	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized data: " << deserializedData->value << std::endl;

}