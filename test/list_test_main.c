#include <stdio.h> // printf
#include <stdlib.h> // malloc
#include <string.h> // strlen

#include "list.h"

struct				koala
{
	char const	*nom;
	int 				age;
	char const	*catchphrase;
};

void	dump_string(void *content, int size)
{
	printf(" Content [%s], Size [%d]\n", (char*)content, size);
}

void						dump_koala(void * content, int size)
{
	struct koala	*bob = (struct koala *)content;

	printf(" %s is %d years old and usually says \"%s\"\n", bob->nom, bob->age, bob->catchphrase);
}

struct koala		*make_koala(char const * nom, int age, char const * catchphrase)
{
	struct koala	*ret = (struct koala *)malloc(1 * sizeof(struct koala));

	ret->nom = nom;
	ret->age = age;
	ret->catchphrase = catchphrase;

	return ret;
}

int	 			main()
{
	t_list	*list = NULL;
	int 		i = 0;
	char		*test_contents[] = {"ga", "bu", "zo", "meu"};
	int 		test_qty = 4;

	/*
	 * We create a list and fill it with a few test character
	 * strings
	 */

	list = list_init();
	for (i = 0; i < test_qty; ++i)
		item_pf(list, test_contents[i], (strlen(test_contents[i]) + 1));

	item_delete(list, list->head->next);
	printf("Elements in the list (%d):\n", list->len);
	list_iter(list, &dump_string);

	if ((list_mem(list, "meu", 4)) == 1)
		printf("[meu] is in the list (OK)\n");
	else
	{
		printf("[meu] isn't in the list, error!\n");
		return 1;
	}
	list_delete(list);

	/*
	 * We create another list and fill it with Koalas
	 */
	list = list_init();
	item_pb(list, make_koala("zaz", 42, "nah, too lazy to do that."), sizeof(struct koala));
	item_pb(list, make_koala("jack", 84, "That's a RUMOR!"), sizeof(struct koala));
	item_pb(list, make_koala("thor", 168, "Proceed..."), sizeof(struct koala));
	printf("Koalas in the list:\n");
	list_iter(list, &dump_koala);

	list_delete(list);
	return 0;
}
