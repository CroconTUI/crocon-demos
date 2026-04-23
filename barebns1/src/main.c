#include <stdio.h>
#include <crocon.h>

int main() {
	
	CROCVERSION crocon_ver;
	int crocon_result;
	
	crocon_result = crocon_getver(&crocon_ver);

	printf(
		"Version: %d.%d.%d\r\n\r\n", 
		crocon_ver.major, crocon_ver.minor, crocon_ver.patch
	);
	
	crocon_initscr();
	crocon_settitle("Crocon Test Application");

	crocon_cprintf(
		COLOR_BRIGHT_GREEN, 
		"Crocon Test Application\r\n"
	);

	crocon_getch();

	crocon_fillchar('1', 8, 8, 4, 4);

	crocon_getch();

	return 0;
}
