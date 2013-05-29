#include <stdio.h> // printf
#include <stdlib.h> // malloc
#include <string.h> // strlen

#include "list.h"

struct koala
{
	char const * nom;
	int age;
	char const * catchphrase;
};

static void dump_string(void *content, int size)
{
	printf(" Content [%s], Size [%d]\n", (char*)content, size);
}

static void dump_koala(void * content, int size)
{
	struct koala * bob = (struct koala *)content;

	printf(" %s is %d years old and usually says \"%s\"\n", bob->nom, bob->age, bob->catchphrase);
}

static struct koala * make_koala(char const * nom, int age, char const * catchphrase)
{
	struct koala * ret = (struct koala *)malloc(1 * sizeof(struct koala));
	ret->nom = nom;
	ret->age = age;
	ret->catchphrase = catchphrase;

	return ret;
}

t_item 	*multiply(void *content)
{
	t_item *madafaka = malloc(sizeof(t_item));
	struct koala *current = content;
	struct koala *lol = malloc(sizeof(struct koala));

	lol->age = current->age * 2;
	lol->nom = malloc(strlen(current->nom));
	lol->nom = current->nom;
	lol->catchphrase = malloc(strlen(current->catchphrase));
	lol->catchphrase = current->catchphrase;
	madafaka->content = lol;
	return (madafaka);
}

int main()
{
	t_list * list = NULL;
	int i = 0;
	char* test_contents[] = {"ga", "bu", "zo", "meu"};
	int test_qty = 4;

	/*
	 * We create a list and fill it with a few test character
	 * strings
	 */
	list = new_list_by_default();
	for (i = 0; i < test_qty; ++i)
	{
		list_add_front(list, test_contents[i], strlen(test_contents[i]));
	}
	delete_item(list, list->head->next);
	printf("Elements in the list [%d]:\n", list->len);
	list_iter(list, &dump_string);

	if (list_mem(list, "meu", 3))
		printf("[meu] is in the list (OK)\n");
	else
	{
		printf("[meu] isn't in the list, error!\n");
		return 1;
	}
	delete_list(list);

	/*
	 * We create another list and fill it with Koalas
	 */
	list = new_list_by_default();
	list_add_back(list, make_koala("zaz", 42, "nah, too lazy to do that."), sizeof(struct koala));
	list_add_back(list, make_koala("jack", 84, "That's a RUMOR!"), sizeof(struct koala));
	list_add_back(list, make_koala("thor", 168, "Proceed..."), sizeof(struct koala));
	printf("Koalas in the list:\n");
	list_iter(list, &dump_koala);

	delete_list(list);
	return 0;
}
