
// #include <iostream>
using namespace std;
struct Character
{
    char content;
    Character *next;
    Character *prev;
};

struct Cursor
{
    Character *character;
    int height = 0;
    int width = 0;
};

Character *head = new Character;
Character *tail = new Character;
Cursor *cursor = new Cursor;

int noteHeight;
int noteWidth;

int strSize;

// void printStr(void)
// {
//     Character *ptr = head;
//     while (1)
//     {
//         // cout << ptr->content;
//         if ((ptr->content) == '$')
//             break;

//         ptr = ptr->next;
//     }
//     // cout << endl;
// }

int getIndex(int height, int width)
{
    return height * noteWidth + width;
}

void init(int H, int W, char mStr[])
{
    *tail = {'$', nullptr, head};
    *head = {'%', tail, nullptr};

    noteHeight = H;
    noteWidth = W;

    Character *ptr = head;

    int i = 0;
    // cout << "init : head " << head << endl;
    while (mStr[i] != '\0')
    {

        Character *newChar = new Character({mStr[i++], nullptr, nullptr});
        // cout << "init : " << i << " : " << newChar << endl;
        (newChar)->prev = ptr;
        (newChar)->next = ptr->next;
        ptr->next->prev = newChar;
        ptr->next = newChar;

        ptr = ptr->next;
    }

    strSize = i;

    cursor->height = 0;
    cursor->width = 0;
    cursor->character = head;
    // printStr();
}

void insert(char mChar)
{

    Character *newChar = new Character({mChar, nullptr, nullptr});
    Character *cursorChar = cursor->character;

    newChar->prev = cursorChar;
    newChar->next = cursorChar->next;
    cursorChar->next->prev = newChar;
    cursorChar->next = newChar;

    cursor->character = newChar;

    if ((cursor->width) >= noteWidth - 1)
    {
        (cursor->width) = 0; // -1 can change
        (cursor->height)++;
    }
    else
        (cursor->width)++;

    strSize++;
    // cout << "after insert cursor char : " << cursor->character->content << endl;
}

char moveCursor(int mRow, int mCol)
{
    mRow--;
    mCol--;
    // cout << "before mc cursor char : " << cursor->character->content << endl;

    // cout << (cursor->height) << " -> " << mRow << " | " << (cursor->width) << " -> " << mCol << endl;

    if (strSize < getIndex(mRow, mCol))
    {
        cursor->character = tail->prev;
        cursor->width = strSize % noteWidth;
        cursor->height = strSize / noteWidth;
        // cout << "mc : $" << endl;
        return '$';
    }

    int moveCount =
        noteWidth * (mRow - (cursor->height)) + (mCol - (cursor->width));

    // cout << "Moves " << moveCount << endl;

    if (moveCount > 0)
        for (int i = 0; i < moveCount; i++)
            cursor->character = cursor->character->next;
    else
        for (int i = 0; i < moveCount * (-1); i++)
            cursor->character = cursor->character->prev;

    // cout << "mc : " << cursor->character->next->content << endl;

    cursor->height = mRow;
    cursor->width = mCol;
    // printStr();
    return cursor->character->next->content;
}

int countCharacter(char mChar)
{

    int searchCount = 0;

    Character *ptr = cursor->character->next;
    while (1)
    {
        if ((ptr->content) == mChar)
            searchCount++;

        if ((ptr->content) == '$')
            break;

        ptr = ptr->next;
    }

    // printStr();
    // cout << "cc searchcount : " << searchCount << endl;
    return searchCount;
}
