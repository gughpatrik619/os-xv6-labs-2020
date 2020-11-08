//
// Created by gughpatrik on 9/23/20.
//

/*
 * This program opens a file specified as the second argument.
 */

#include "../kernel/types.h"
#include "../kernel/fcntl.h"
#include "user.h"

int main(int argc, char* argv[]) {

	if (argc < 2) {
		fprintf(2, "No file specified.\n");
		exit(1);
	}

	char* fileName = argv[1];

	int fd = open(fileName, O_CREATE);

	if (fd < 0) {
		fprintf(2, "Error occurred creating file: '%s'.\n", fileName);
		exit(1);
	}

	exit(0);
}
