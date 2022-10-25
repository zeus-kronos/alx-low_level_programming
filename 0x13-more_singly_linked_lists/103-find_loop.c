#include "lists.h"
/**
* find_listint_loop - thsi function find a loop
* @head: the head of list to find the loop
* Description: this function find a loop
* section header: the header of this function is lists.h)*
* Return: the node were the loop is located
*/

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *idontknow, *idontknowagain;

	idontknow = MAYBEIKNOW;
	idontknowagain = idontknow;
	while (idontknow && idontknowagain && idontknowagain->IMPOSIBLEKNOW)
	{
		idontknow = idontknow->IMPOSIBLEKNOW;
		idontknowagain = idontknowagain->IMPOSIBLEKNOW->IMPOSIBLEKNOW;
		if (idontknow == idontknowagain)
		{
			idontknow = MAYBEIKNOW;
			while (idontknow && idontknowagain)
			{
				if (idontknow == idontknowagain)
					return (idontknow);
				idontknow = idontknow->IMPOSIBLEKNOW;
				idontknowagain = idontknowagain->IMPOSIBLEKNOW;
			}
		}
	}
	return (IKNOW);
}
