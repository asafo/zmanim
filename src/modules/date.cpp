#include "date.h"

#include <libintl.h>

#include <string>
#include <iostream>
#include <hdatepp.h>
using namespace hdate;
using namespace std;

#include <fribidi.h>
#include <string.h>

// Returns a corrected single line Bidi string from the given line
// (Using fribidi's functions)

// WARNING: If the allocation isn't enough it will crash.
//  But I seems safe now.
string LineToBidiText(string line)
{
    string out="";

    //FriBidi C string holding the originall text (that is probably with logicall hebrew)
    FriBidiChar *logical = NULL;
    //FriBidi C string for the output text (that should be visual hebrew)
    FriBidiChar *visual = NULL;

    //C string holding the originall text (not nnecessarily as unicode)
    char *ip = NULL;
    //C string for the output text
    char *op = NULL;

    //Size to allocate for the char arrays
    int size = line.size() + 2;

    //Allocate memory:
    //It's probably way too much, but at least it's not too little
    logical = new FriBidiChar[size * 3];
    visual = new FriBidiChar[size * 3];
    ip = new char[size * 3];
    op = new char[size * 3];

    FriBidiCharType base;
    size_t len, orig_len;

    //A bool type to see if conversion succeded
    fribidi_boolean log2vis;

    //Holds information telling fribidi to use UTF-8
    FriBidiCharSet char_set_num;
    char_set_num = fribidi_parse_charset ("UTF-8");

    //Copy the given string into the ip string
    strcpy(ip, line.c_str());

    //Find length of originall text
    orig_len = len = strlen( ip );

    //Insert ip to logical as unicode (and find it's size now)
    len = fribidi_charset_to_unicode (char_set_num, ip, len, logical);

    base = FRIBIDI_TYPE_ON;
    //Convert logical text to visual
    log2vis = fribidi_log2vis (logical, len, &base, /* output: */ visual, NULL, NULL, NULL);

    //If convertion was successful
    if(log2vis)
    {
        //Remove bidi marks (that we don't need) from the output text
        len = fribidi_remove_bidi_marks (visual, len, NULL, NULL, NULL);

        //Convert unicode string back to the encoding the input string was in
        fribidi_unicode_to_charset ( char_set_num, visual, len ,op);

        //Insert the output string into the output QString
        out = op;
    }

    //Free allocated memory
    delete [] visual;
    delete [] logical;
    delete [] ip;
    delete [] op;

    return out;
}
void Date::render(IBoard *board)
{
    // hdate
    Hdate h;
    h.set_hdate(12,12,5771);
    h.set_israel();

    string datestr = LineToBidiText(h.get_format_date(0));
    cout<<h.get_format_date(0)<<endl;
    board->load_group("date");
    board->set_text("date_text", datestr);
}

