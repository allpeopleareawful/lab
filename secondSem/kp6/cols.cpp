#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "computer.h"

void usage(){
	printf("Usage: programm [-key] [input_filename] [output_filename]\nKeys:\n[-f] output all data\n[-t] complete the task\n");
}

int main(int argc, char *argv[]){
	if (argc != 4){
		usage();
		return 1;
	}

	computer comp;

	FILE *fi = (fi = fopen(argv[2], "rb"));
	if (!fi){
		perror("Can't open input file");
		return 2;
	}
	FILE *fo = (fo = fopen(argv[3], "w"));
	if (!fo){
		perror("Can't open output file");
		return 2;
	}

	if (!strcmp(argv[1], "-f")){
        printf("/------------------------------------------------------------------------------------------------------\
               ------------------------\\\n");
        printf("|  surname  | bit_depth | cores |  RAM  | video_type |  VRAM  | drive_type | drive_quantity |  ROM  | ports | devices |   OS    |\n");
        printf("|-----------|-----------|-------|-------|------------|--------|------------|----------------|-------|--\
               ----|---------|---------|\n");

		while (!feof(fi)){

			fread(&comp, sizeof(comp), 1, fi);
            if (feof(fi)) break;
			fprintf(fo, "surname = %s\tbit_depth = %d\tcores = %d\tRAM = %d\tvideo_type = %s\tVRAM = %d\tdrive_type = %s\tdrive_quantity = %d\tROM = %d\tports = %d\tdevices = %d\tOS = %s\n", comp.surname, comp.bit_depth, comp.cores, comp.RAM, comp.video_type, comp.VRAM, comp.drive_type, comp.drive_quantity, comp.ROM, comp.ports, comp.devices, comp.OS);
            printf("|%11s|%11d|%7d|%7d|%12s|%8d|%12s|%16d|%7d|%7d|%9d|%9s|\n", comp.surname, comp.bit_depth, comp.cores, comp.RAM, comp.video_type, comp.VRAM, comp.drive_type, comp.drive_quantity, comp.ROM, comp.ports, comp.devices, comp.OS);
		}
        printf("\\-----------------------------------------------------------------------------------------------------\
               -------------------------/\n");
	}

	else if (!strcmp(argv[1], "-t")){
        printf("/------------------------------------------------------------------------------------------------------\
               ------------------------\\\n");
		printf("|  surname  | bit_depth | cores |  RAM  | video_type |  VRAM  | drive_type | drive_quantity |  ROM  | ports | devices |   OS    |\n");
		printf("|-----------|-----------|-------|-------|------------|--------|------------|----------------|-------|--\
               ----|---------|---------|\n");

		while(!feof(fi)){
			fread(&comp, sizeof(comp), 1, fi);
            if (feof(fi)) break;
			if ((comp.bit_depth < 32) || (comp.cores < 6) || (comp.RAM < 8192) || (comp.VRAM < 2048) || ((strcmp(comp.drive_type, "SATA"))) || (comp.drive_quantity < 1) || (comp.ROM < 512) || (comp.ports < comp.devices)){
			fprintf(fo, "surname = %s\tbit_depth = %d\tcores = %d\tRAM = %d\tvideo_type = %s\tVRAM = %d\tdrive_type = %s\tdrive_quantity = %d\tROM = %d\tports = %d\tdevices = %d\tOS = %s\n", comp.surname, comp.bit_depth, comp.cores, comp.RAM, comp.video_type, comp.VRAM, comp.drive_type, comp.drive_quantity, comp.ROM, comp.ports, comp.devices, comp.OS);
			printf("|%11s|%11d|%7d|%7d|%12s|%8d|%12s|%16d|%7d|%7d|%9d|%9s|\n", comp.surname, comp.bit_depth, comp.cores, comp.RAM, comp.video_type, comp.VRAM, comp.drive_type, comp.drive_quantity, comp.ROM, comp.ports, comp.devices, comp.OS);
			}
		}
        printf("\\-----------------------------------------------------------------------------------------------------\
               -------------------------/\n");
	}

	else{
		perror("Invalid key");
		usage();
		return 1;
	}
}