COMPILER = c++
FLAGS += -Wall -Wextra -Werror -g -std=c++98


# ----------------------------- Sources ----------------------------- #

NAME = megaphone
FILES = megaphone

SRCS = $(addsuffix .cpp, $(FILES))
OBJS = $(addsuffix .o, $(FILES))


# ------------------------------ Rules ------------------------------ #

all: $(NAME)

$(NAME): $(OBJS)
	@$(COMPILER) -o $@ $^ $(FLAGS)
	@echo "\033[38;2;0;170;0;1mSuccessfully compiled to \033[38;2;255;145;5;3m./$(NAME)\033[0m\033[38;2;0;170;0;1m!\033[0m"

%.o: %.cpp
	@$(COMPILER) -o $@ -c $< $(FLAGS)

clean:
	@rm -rf $(OBJS)
	@echo "\033[38;2;170;0;0;1mAll object files have been successfully deleted.\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[38;2;255;145;5;3m\033[1m./$(NAME)\033[0m\033[38;2;170;0;0;1m has been successfully deleted.\033[0m"

re: fclean all

code: all clean

.PHONY: all clean fclean re



# $@ : produit (ou but) de la règle 
# $< : nom de la première dépendance (ou source) 
# $? : toutes les dépendances plus récentes que le but 
# $^ : toutes les dépendances 
# $+ : idem mais chaque dépendance apparait autant de fois qu'elle
#      est cité et l'ordre d'apparition est conservé
