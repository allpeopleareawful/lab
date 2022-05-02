#ifndef	COMPUTERS_H
#define COMPUTERS_H

typedef struct{
	char surname[15];
	int bit_depth;
	int cores;
	int RAM;
	char video_type[5];
	int VRAM;
	char drive_type[6];
	int drive_quantity;
	int ROM;
	int ports;
	int devices;
	char OS[10];
}	computer;
#endif