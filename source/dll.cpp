#include <iostream>
#include "../header/dll.h"
using namespace std;

void createList(List &L)
{
    first(L) = NULL;
    last(L) = NULL;
}

address createNewElm(infotype x)
{
    address p;
    p = new elmList;
    info(p) = x;
    next(p) = NULL;
    prev(p) = NULL;
    return p;
}

void insertLast(List &L, address p)
{
    if (first(L) == NULL && last(L) == NULL)
    {
        first(L) = p;
        last(L) = p;
    }
    else
    {
        next(last(L)) = p;
        prev(p) = last(L);
        last(L) = p;
    }
    cout << "Account name '" << info(p).username << "' has been inputed to list\n"
         << endl;
}

address findAkun(List &L, string username)
{
    address p;
    bool ketemu;

    if (first(L) == NULL)
    {
        cout << "List kosong" << endl;
        return NULL;
    }
    else
    {
        p = first(L);
        ketemu = username == info(p).username;
        while (p != last(L) && !ketemu)
        {
            p = next(p);
            ketemu = username == info(p).username;
        }
        if (ketemu)
        {
            return p;
        }
        else
        {
            return NULL;
        }
    }
}

void signUp(List &L, infotype x)
{
    address p;
    bool akunTerdaftar = false;
    if (first(L) == NULL)
    {
        p = createNewElm(x);
        insertLast(L, p);
    }
    else
    {
        p = findAkun(L, x.username);
        if (p == NULL)
        {
            p = createNewElm(x);
            insertLast(L, p);
        }
        else
        {
            cout << "Account name '" << x.username << "' has been registered.\n"
                 << endl;
        }
    }
}

void deleteFirst(List &L, address &p)
{
    p = first(L);
    if (first(L) == last(L))
    {
        first(L) = NULL;
        last(L) = NULL;
    }
    else
    {
        first(L) = next(p);
        next(p) = NULL;
        prev(first(L)) = NULL;
    }
    cout << "Account name '" << info(p).username << "' has been deleted from list\n"
         << endl;
    delete p;
}

void deleteAfter(List &L, address prec, address &p)
{
    if (next(prec) == last(L))
    {
        p = next(prec);
        last(L) = prec;
        next(prec) = NULL;
        prev(p) = NULL;
    }
    else if (next(prec) != last(L))
    {
        p = next(prec);
        next(prec) = next(p);
        prev(next(p)) = prec;
        next(p) = NULL;
        prev(p) = NULL;
    }
    else
    {
        p = NULL;
    }
    cout << "Account name '" << info(p).username << "' has been deleted from list\n"
         << endl;
    delete p;
}

void deleteLast(List &L, address &p)
{
    p = last(L);
    if (first(L) == last(L))
    {
        first(L) = NULL;
        last(L) = NULL;
    }
    else
    {
        last(L) = prev(p);
        next(last(L)) = NULL;
        prev(p) = NULL;
    }
    cout << "Account name '" << info(p).username << "' has been deleted from list\n"
         << endl;
    delete p;
}

void removeAkun(List &L, string username)
{
    address p, prec;
    if (first(L) != NULL)
    {
        p = findAkun(L, username);
        if (p == first(L))
        {
            deleteFirst(L, p);
        }
        else if (p != first(L) && p != NULL)
        {
            prec = prev(p);
            deleteAfter(L, prec, p);
        }
    }
    if (p == NULL)
    {
        cout << "Account name '" << username << "' not found from list\n"
             << endl;
    }
}

void showList(List L)
{
    address p;
    int i = 1;

    if (first(L) == NULL)
    {
        cout << "List kosong\n"
             << endl;
    }
    else
    {
        p = first(L);
        cout << "Show all elemen list" << endl;
        while (p != NULL)
        {
            cout << "Data ke-" << i << endl;
            cout << "Username : " << info(p).username << endl;
            cout << "Password : " << info(p).password << "\n"
                 << endl;
            p = next(p);
            i++;
        }
    }
}