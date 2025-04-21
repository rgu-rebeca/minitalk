#include <unistd.h>

int main(void)
{
	char character;

	character = 226;
	if (character == 226)
    write(1, "byte correcto\n", 14);
	else
    write(1, "byte incorrecto\n", 16);

}
