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
		"Version: %d.%d.%d", 
		crocon_ver.major, crocon_ver.minor, crocon_ver.patch
	);

	crocon_mvcprintf(
		0, 3, COLOR_BRIGHT_CYAN,
		"CONSOLE BUFFER METRICS"
	);
	crocon_mvcprintf2(
		0, 4, COLOR_TRANSPARENT, 80,
		"Width: %d | Height: %d",
		stdscr->metrics.width, stdscr->metrics.height
	);

	crocon_getch();

	crocon_fillchar(8, 8, 4, 4, '1');
	crocon_fillcolor(8, 8, 4, 4, COLOR_BLACK, COLOR_GRAY);

	crocon_getch();

	crocon_freescr();

	printf(
		"Here we have shown how a demo application works using the CroconTUI framework."
		"\r\n\r\nMore details at https://github.com/CroconTUI/lib.\r\n"
	);

	return 0;
}
