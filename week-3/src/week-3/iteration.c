#include <cs50.h>
#include <stdio.h>

int preferences[3][3] = {
    // A    B    C
    { 0,   3,   2 }, // Alice vs [A,B,C]
    { 1,   0,   2 }, // Bob   vs [A,B,C]
    { 2,   2,   0 }  // Charlie vs [A,B,C]
};


int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}

void draw(int height)
{

}
