/*
    Tárgy: Elte IK Operációs rendszerek 1. Beadandó
    Készítette: Sándor Balázs - AZA6NL
    Leadás: 2016.11.07
	Git: https://github.com/SandorBalazsHU/elte-ik-os-1

    A látogatókat reprezentáló adatszerkezetethez tartozó fügvények.
*/

#include <string.h>
#include <stdio.h>
#include "./Tests.h"
#include "./view/ConsoleIO.h"
#include "./model/Events.h"
#include "./model/Event.h"
#include "./model/Visitor.h"
#include "./controller/File.h"

//A teszteket egyszerre futtató függvény.
int test(int argc, char** argv)
{
    if(argc > 1)
    {
        if(strcmp(argv[1], testConsoleParameter))
        {
            //A visitor adatszerkezet tesztje.
            int testVisitor();

            //Az Event adatszerkezet tesztje kevesebb mint 5 elemre.
            int testEvent(3);

            //Az Event adatszerkezet tesztje több mint 5 elemre.
            int testEvent(10);

            //Az Events adatszerkezet tesztje kevesebb mint 5 elemre.
            int testEvents(3);

            //Az Events adatszerkezet tesztje több mint 5 elemre.
            int testEvents(8,3);

            return 1;
        }
    }
    return 0;
}

//A visitor adatszerkezet tesztje.
int testVisitor()
{
    printf("\n testVisitor \n");

    Visitor* visitor1 = newVisitor(0, "visitor1", "visitor1@mail.org", getDate());
    printf("     newVisitor - \x1b[32mOK\x1b[0m\n");

    freeVisitor(visitor1);
    printf("     freeVisitor - \x1b[32mOK\x1b[0m\n");
}

//Az Event adatszerkezet tesztje.
int testEvent(int n)
{
    printf("\n testEvent \n");
    Event* event1 = newEvent(0,"event1");
    printf("newEvent1 - \x1b[32mOK\x1b[0m\n");
    int i;
        for(i = 0; i < n; ++i)
        {
            Visitor* visitor = newVisitor(i, "visitor", "visitor@mail.org", getDate());
            printf("     newVisitor%i - \x1b[32mOK\x1b[0m\n", (i+1));
            addVisitorToEvent(event1, visitor);
            printf("     addVisitorToEvent%i - \x1b[32mOK\x1b[0m\n", (i+1));
        }
    freeEvent(event1);
    printf("     freeEvent - \x1b[32mOK\x1b[0m\n");
}

//Az Events adatszerkezet tesztje.
int testEvents(int n, int m)
{
    printf("\n testEvents \n");

    Events* events1 = newEvents();
    printf("     newEvents1 - \x1b[32mOK\x1b[0m \n");

    int i;
    for(i = 0; i < n; ++i)
    {
        Event* event1 = newEvent(i,"event");
        printf("          newEvent%i - \x1b[32mOK\x1b[0m \n", (i+1));
        int j;
        for(j = 0; j < m; ++j)
        {
            Visitor* visitor = newVisitor(j, "visitor", "visitor@mail.org", getDate());
            printf("     newVisitor%i - \x1b[32mOK\x1b[0m\n", (j+1));
            addVisitorToEvent(event1, visitor);
            printf("     addVisitorToEvent%i - \x1b[32mOK\x1b[0m\n", (j+1));
        }
        addEventToEvents(events1, event1);
        printf("          addEventToEvents1 - \x1b[32mOK\x1b[0m \n");
    }

    freeEvents(events1);
    printf("     freeEvents1 - \x1b[32mOK\x1b[0m \n");
}