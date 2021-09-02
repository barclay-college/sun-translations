#include<stdio.h>
#include<string.h>


typedef struct SunSymbol {
    char word[30];
    char symbol[30];
} SunSymbol;


int main()
{
    const char filename[] = "content/sun_dictionary.csv";
    FILE *fh;

    fh = fopen(filename,"r");
    if(!fh)
    {
        printf("Unable to read from file %s\n",filename);
        return(1);
    }

    /* Count total number of symbols */
    int total_symbols = 0;
    int ch;
    while(!feof(fh))
    {
        ch = fgetc(fh);
        if(ch == '\n')
        {
            total_symbols++;
        }
    }
    rewind(fh);

    /* Read in english/symbol translations */
    SunSymbol symbols[total_symbols];
    int i = 0;

    char buffer[200];
    fgets(buffer, 200, fh);

    while(!feof(fh))
    {
        SunSymbol *s = symbols + i;

        char *token = strtok(buffer, ",");
        if(token)
        {

            strcpy(s->word, token);

            char *token = strtok(NULL, ",");
            strcpy(s->symbol, token);

        }

        fgets(buffer, 200, fh);
        i++;

    }

    fclose(fh);

    /* SunSymbol *testpt = symbols;
    printf("%s\n", (testpt+1)->word); */
    /* for(i = 0; i < total_symbols; i++)
        printf("%s = %s", symbols[i].word, symbols[i].symbol); */
    

    /* Translate English words */
    /* char test_word[] = "awake";

    for(i = 0; i < total_symbols; i++)
    {
        if(!strcmp(symbols[i].word, test_word))
            printf("%s = %s\n",test_word, symbols[i].symbol);
    } */

    return(0);
}
