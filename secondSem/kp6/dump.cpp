#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "computer.h"

void usage(){
	printf("Usage: programm [input_filename] [output_filename]\n");
}

int main(int argc, char *argv[]){
	if (argc != 3){
		usage();
		return 1;
	}

	computer comp;
	
	FILE *fi, *fo;
	fi = (fi = fopen(argv[1], "r"));
	if (!fi){
		perror("Can't open input file");
		return 2;
	}

	fo = (fo = fopen(argv[2], "wb"));
	if (!fo){
		perror("Can't open output file");
		return 2;
	}

	while (!feof(fi)){
		fscanf(fi,"%s %d %d %d %s %d %s %d %d %d %d %s\n", comp.surname, &comp.bit_depth, &comp.cores, &comp.RAM, comp.video_type, &comp.VRAM, comp.drive_type, &comp.drive_quantity, &comp.ROM, &comp.ports, &comp.devices, comp.OS);
		printf("%s %d %d %d %s %d %s %d %d %d %d %s\n", comp.surname, comp.bit_depth, comp.cores, comp.RAM, comp.video_type, comp.VRAM, comp.drive_type, comp.drive_quantity, comp.ROM, comp.ports, comp.devices, comp.OS);
		fwrite(&comp, sizeof(comp), 1, fo);
	}

	return 0;
}