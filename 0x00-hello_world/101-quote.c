<<<<<<< HEAD
#include <unistd.h>

=======
#include <stdio.h>
#include <unistd.h>
>>>>>>> b55b0d73a75321aa0a9ba600ae7aec14be9793ea
/**
 *  * main - Prints "and that piece of art is useful" - Dora Korpar, 2015-10-19",
 *   *                followed by a new line, to standard error.
 *    *
 *     * Return: Always 1.
 *      */
int main(void)
{
<<<<<<< HEAD
		write(2, "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n",  59);

		return (1);
=======
write(2, "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n",
sizeof("and that piece of art is useful\" - Dora Korpar, 2015-10-19"));
return (1);
>>>>>>> b55b0d73a75321aa0a9ba600ae7aec14be9793ea
}
