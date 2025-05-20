##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## makes mylib
##

NAME = mysh
fichier = $(wildcard ./tools/*.c ./tools/clean_str/*.c ./tools/env_changer/*.c ./tools/my_virg_to_word_array/*.c src/*.c)

all: $(NAME)

mysh: ## Execute le programme
	gcc $(fichier) -g3 -o mysh
	chmod 755 mysh

clean: ## Clean général
	rm -f *.o
	rm -f *~
	rm -f *#

fclean:    clean
	rm -f $(NAME)

re:    fclean all
