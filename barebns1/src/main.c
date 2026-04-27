#include <stdio.h>
#include <crocon.h>

int main() {
	
	CROCVERSION crocon_ver;
	int crocon_result;
	
	crocon_result = crocon_getver(&crocon_ver);
	
	crocon_initscr();
	crocon_settitle("Crocon Test Application");

	crocon_cprintf(
		COLOR_BRIGHT_GREEN, 
		"Crocon Test Application\r\n"
	);
	crocon_mvcprintf2(
		0, 1, COLOR_TRANSPARENT, 80,
		"Version: %d.%d.%d\r\n", 
		crocon_ver.major, crocon_ver.minor, crocon_ver.patch
	);

	crocon_getch();

	crocon_fillchar(8, 8, 4, 4, '1');
	crocon_fillcolor(8, 8, 4, 4, COLOR_BLACK, COLOR_GRAY);

	crocon_getch();

	return 0;
}
