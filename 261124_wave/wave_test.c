#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/* Este código só funciona em processadores little ended
 */
 
#define SIZE_BUFFER	128

struct chunk {
	char ChunkID[4];
	uint32_t ChunkSize;
	char Format[4];
};

struct subChunk1 {
	char SubChunk1ID[4];
	uint32_t SubChunk1Size;
	uint16_t AudioFormat;
	uint16_t NumChannels;
	uint32_t SampleRate;
	uint32_t ByteRate;
	uint16_t BlockAlign;
	uint16_t BitsPerSample;
};


int main(int argc, char *argv[])
{
	
	FILE *fd = fopen(argv[1], "r");

	struct chunk chunk;
	size_t nbytes = fread(&chunk, 1, sizeof chunk, fd);
	
	if (strncmp("WAVE", chunk.Format, 4) != 0) {
		fprintf(stderr, "File format isn't a WAVE\n");
		exit(EXIT_FAILURE);
	}

	struct subChunk1 subChunk1;
	nbytes = fread(&subChunk1, 1, sizeof subChunk1, fd);
	
	printf("Number of channels = %d\n", subChunk1.NumChannels);
	printf("Sample rate = %d\n", subChunk1.SampleRate);
	printf("Bits per sample = %d\n", subChunk1.BitsPerSample);
}

