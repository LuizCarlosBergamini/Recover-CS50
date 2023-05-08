#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

const uint8_t BLOCK_SIZE = 64;

//recover.c

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./recover IMAGE\n");
    }

    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("null!");
        return 1;
    }

    uint8_t buffer[BLOCK_SIZE];

    int count = 0;

    FILE *jpg = NULL;

    while (fread(buffer, 1, BLOCK_SIZE, card) == BLOCK_SIZE)
    {
        //finds the start of a new jpeg file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] >> 4) == 0xe)
        {
            //if a file is already open closes it
            if (jpg != NULL)
            {
                fclose(jpg);
            }
            //create a string variable that will store the name of the actual file
            char filename[8];
            sprintf(filename, "%03i.jpg", count++);
            //creates a new file in jpg pointer with the name in filename variable
            jpg = fopen(filename, "w");
            //if that jpg pointer is null, that means that the file could not be created
            if (jpg == NULL)
            {
                printf("Could not create %s\n", filename);
                return 2;
            }
            //If it was created correctly, prints it
            printf("%s created\n", filename);
        }
        //if the jpg pointer is not NULL aka its not empty, writes the actual read date into the file inside it
        if (jpg != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, jpg);
        }
    }

    //closes the jpg file
    if (jpg != NULL)
    {
        fclose(jpg);
    }

    //closes the card file
    fclose(card);
}
