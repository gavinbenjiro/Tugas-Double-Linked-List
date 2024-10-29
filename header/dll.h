#ifndef dll_h
#define dll_h
#include <iostream>
using namespace std;
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
using namespace std;

struct akun
{
    string username;
    string password;
};
typedef akun infotype;
typedef struct elmList *address;
struct elmList
{
    infotype info;
    address next;
    address prev;
};
struct List
{
    address first;
    address last;
};
void createList(List &L);
address createNewElm(infotype x);
void insertLast(List &L, address p);
address findAkun(List &L, string username);
void signUp(List &L, infotype x);
void deleteFirst(List &L, address &p);
void deleteAfter(List &L, address prec, address &p);
void deleteLast(List &L, address &p);
void removeAkun(List &L, string username);
void showList(List L);

#endif // dll_h