#include "two.h"
#define APG_IMPLEMENTATION
#include "apg.h"
#include <stdio.h>

int main (int argc, char** argv) {
	g_argc = argc;
	g_argv = argv;

	restart_apg_log ();

	int pn = check_param ("hello");
	printf ("the user param 'hello' was found at arg num %i\n", pn);
	if (pn > 0) {
		return 0;
	}


	uint uval = MAX (110, 120);
	printf ("uval = %u\n", uval);
	apg_log ("the value was %u\n", uval);

	uval = CLAMP (uval, 11, 12);
	printf ("uval = %u\n", uval);

	apg_log_err ("ERROR: this is a fake error\n");

#ifndef APPLE
	double T = 0.0;
	double prev = apg_time_linux ();
	while (T < 1.0) {
		double curr = apg_time_linux ();
		double elapsed = curr - prev;
		prev = curr;
		T += elapsed;
		printf ("T= %lf\n", T);
	}
#endif

	two ();

	return 0;
}
