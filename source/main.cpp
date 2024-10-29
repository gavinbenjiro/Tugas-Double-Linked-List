#include <iostream>
#include "../header/dll.h"
using namespace std;

int main()
{
    List L;
    infotype data;
    address pInp, pDel, find, prec;

    // Judul
    cout << "==================" << endl;
    cout << "DOUBLE LINKED LIST" << endl;
    cout << "==================\n"
         << endl;

    // Membuat List kosong
    createList(L);

    // Memasukkan data ke-1 (insertLast)
    cout << "Memasukkan data ke-1 (insertLast)" << endl;
    data.username = "gavinbenjiro";
    data.password = "Gavin123";
    pInp = createNewElm(data);
    insertLast(L, pInp);

    // Sign Up akun yang sudah terdaftar pada data ke-1
    cout << "Sign Up akun yang sudah terdaftar pada data ke-1" << endl;
    data.username = "gavinbenjiro";
    data.password = "Gavin123";
    signUp(L, data);

    // Memasukkan data ke-2 (insertLast)
    cout << "Memasukkan data ke-2 (insertLast)" << endl;
    data.username = "arsyadfillah";
    data.password = "Maming123";
    pInp = createNewElm(data);
    insertLast(L, pInp);

    // Memasukkan data ke-3 (signUp)
    cout << "Memasukkan data ke-3 (signUp)" << endl;
    data.username = "anandamarchel";
    data.password = "Marchel123";
    signUp(L, data);

    // Menampilkan seluruh elemen list
    showList(L);

    // Mencari akun dengan username : "gavinbenjiro"
    cout << "Mencari akun dengan username : 'gavinbenjiro'" << endl;
    find = findAkun(L, "gavinbenjiro");
    if (find == NULL)
    {
        cout << "Data tidak ditemukan \n"
             << endl;
    }
    else
    {
        cout << "Data ditemukan" << endl;
        cout << "Username : " << info(find).username << endl;
        cout << "Password : " << info(find).password << "\n"
             << endl;
    }

    // Memasukkan data ke-4 (signUp)
    cout << "Memasukkan data ke-4 (signUp)" << endl;
    data.username = "ihsannaufal";
    data.password = "Ihsan123";
    signUp(L, data);

    // Memasukkan data ke-5 (insertLast)
    cout << "Memasukkan data ke-5 (insertLast)" << endl;
    data.username = "veironvaya";
    data.password = "Veiron123";
    pInp = createNewElm(data);
    insertLast(L, pInp);

    // Memasukkan data ke-6 (insertLast)
    cout << "Memasukkan data ke-6 (insertLast)" << endl;
    data.username = "arsyadmaulana";
    data.password = "Arsyad123";
    pInp = createNewElm(data);
    insertLast(L, pInp);

    // Menampilkan seluruh elemen list
    showList(L);

    // Mencari akun dengan username : "nabilaazhari"
    cout << "Mencari akun dengan username : 'nabilaazhari'" << endl;
    find = findAkun(L, "nabilaazhari");
    if (find == NULL)
    {
        cout << "Data tidak ditemukan \n"
             << endl;
    }
    else
    {
        cout << "Data ditemukan" << endl;
        cout << "Username : " << info(find).username << endl;
        cout << "Password : " << info(find).password << "\n"
             << endl;
    }

    // Menghapus data urutan ke-1 (deleteFirst)
    cout << "Menghapus data urutan ke-1 (deleteFirst)" << endl;
    deleteFirst(L, pDel);

    // Menghapus data urutan ke-6 (deleteLast)
    cout << "Menghapus data urutan ke-6 (deleteLast)" << endl;
    deleteLast(L, pDel);

    // Menampilkan seluruh elemen list
    showList(L);

    // Menghapus data urutan ke-3 (deleteAfter)
    cout << "Menghapus data urutan ke-3 (deleteAfter)" << endl;
    find = findAkun(L, "ihsannaufal");
    prec = prev(find);
    deleteAfter(L, prec, pDel);

    // Menghapus data dengan username : "arsyadfillah"
    cout << "Menghapus data dengan username : 'arsyadfillah'" << endl;
    removeAkun(L, "arsyadfillah");

    // Menghapus data dengan username : "arsyadfillah"
    cout << "Menghapus data dengan username : 'rafiftaufiq'" << endl;
    removeAkun(L, "rafiftaufiq");

    // Menampilkan seluruh elemen list
    showList(L);

    return 0;
}