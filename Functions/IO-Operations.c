#include <IO-Operations.h>

/**
 * Receive string [s] as pointer to the first character
 * and compare it to the word "ENTRA"
 * 
 * Return: 
 *  0 if [s] is equal to ENTRA.
 *  A number >0 or <0 if the word is different
 */
int command_ENTRY(char *s)
{
    return strcmp(s, "ENTRA");
}

/**
 * Receive string [s] as pointer to the first character
 * and compare it to the word "SAI"
 * 
 * Return: 
 *  0 if [s] is equal to SAI.
 *  A number >0 or <0 if the word is different
 */
int command_EXIT(char *s)
{
    return strcmp(s, "SAI");
}

/**
 * Receive a character [c] and compare it to some special
 * ascii characters:
 *      0x20, 0x10, 0x13, 0x00
 *   (SPACE), (\n), (\r), (\0)
 * 
 * Return:
 *  1 if [c] is different than all the characters above
 *  0 if [c] is different
 */
int isCharValid(char c)
{
    return (c != ' ' && c != '\n' && c != '\r' && c != '\0');
}   

/**
 * Receive a [FILE *stream] and return a string heap allocated
 * with the bytes captured from [stream] (Ex: keyboard source)
 * 
 * Return:
 *  64bit pointer to string allocated in the heap memory.
 *  string automatically alloc the last byte for the \0 byte 
*/
char *allocStringInMemory(FILE *stream)
{
    char c, *string = NULL;
    int sizeString = 0;
    // getc(stream); // Exclui o caracter (space) que sobra na linha.
    while (isCharValid(c = getc(stream)))
    {
        string = (char *)realloc(string, (sizeString + 1) * sizeof(char));
        string[sizeString] = c;
        sizeString++;
    }

    string = (char *)realloc(string, (sizeString + 1) * sizeof(char));
    string[sizeString] = '\0';
    return string;
}
