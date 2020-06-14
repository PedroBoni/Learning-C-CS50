#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/*Declared Functions*/
int count_letters(string Text);
int count_words(string Text);
int count_sentence(string Text);
float count_indice(int letters, int words, int sentences);

/*Function Main*/

int main(void)
{
    string text = get_string("Text: ");
    int letter = count_letters(text);
    int word = count_words(text);
    int sentence = count_sentence(text);
    int note = count_indice(letter, word, sentence);
    if (note >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (note < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", note);
    }

}
int count_letters(string Text)
{
    int letters = 0;
    for (int i = 0, n = strlen(Text); i < n; i++)
    {
        if (Text[i] >= 'a' & Text[i] <= 'z' || Text[i] >= 'A' & Text[i] <= 'Z')
        {
            letters++;
        }
    }
    return (int)letters;
}
int count_words(string Text)
{
    int word = 0;
    for (int i = 0, n = strlen(Text); i < n; i++)
    {
        if (Text[i] == ' ')
        {
            word++;
        }
    }
    word++;
    return (int)word;
}
int count_sentence(string Text)
{
    int sentence = 0;
    for (int i = 0, n = strlen(Text); i < n; i++)
    {
        if (Text[i] == '.' || Text[i] == '!' || Text[i] == '?')
        {
            sentence++;
        }
    }
    return (int)sentence;
}
float count_indice(int letters, int words, int sentences)
{
    float averageL = (letters * 100) / words;
    float averageS = (sentences * 100) / words;
    float index = 0.0588 * averageL - 0.296 * averageS - 15.8;
    int indice = roundf(index);
    return indice;
}
