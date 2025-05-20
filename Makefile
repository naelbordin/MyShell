##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## makes mylib
##

NAME = mysh
fichier = $(wildcard *.c)

all: $(NAME)

mysh: ## Création de la lib
	gcc $(fichier) -g3 -o mysh
	chmod 755 mysh

clean: ## Clean général
	rm -f *.o
	rm -f *~
	rm -f *#

fclean:    clean ## Supprime l'executable
	rm -f $(NAME)

re:    fclean all ## Rebuild

## -- Other --
help: ## List of commands
