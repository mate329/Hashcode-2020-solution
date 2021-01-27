#include <iostream>
#include <math.h>
#include <string>
#include <cstring>

using namespace std;

typedef struct {
    int numberOfBooks;
    int signupProcess;
    int booksShippedEachDay;
    int *whichBooks;
    int id;
    int sum;
    float avg;
}knjiznica;

void sort(knjiznica &lib, int books[]) {
    for (int j = 0; j < lib.numberOfBooks - 1; ++j) {
            for (int l = 0; l < lib.numberOfBooks - j - 1; ++l) {
                if (books[lib.whichBooks[l]] > books[lib.whichBooks[l + 1]]) {
                    int tmp = lib.whichBooks[l];
                    lib.whichBooks[l] = lib.whichBooks[l + 1];
                    lib.whichBooks[l + 1] = tmp;
                }
            }
        }
}

void lensort(knjiznica libraries[], int numberOfLibraries) {
    for (int j = 0; j < numberOfLibraries - 1; ++j) {
         for (int l = 0; l < numberOfLibraries - j - 1; ++l) {
            if (libraries[l].signupProcess > libraries[l + 1].signupProcess) {
                knjiznica tmp = libraries[l];
                libraries[l] = libraries[l + 1];
                libraries[l + 1] = tmp;
            }
        }
    }
}


int main()
{
    int numberOfBooks, numberOfLibraries, daysOfScanning;
    int *books;
    knjiznica *libraries;

    cin >> numberOfBooks >> numberOfLibraries >> daysOfScanning;
    books = new int[numberOfBooks];
    libraries = new knjiznica[numberOfLibraries];

    //scanning book scores
    for(int i = 0; i < numberOfBooks; i++){
        cin >> books[i];
    }

    for(int i = 0; i < numberOfLibraries; i++){
        //scanning library properties
        cin >> libraries[i].numberOfBooks >> libraries[i].signupProcess >> libraries[i].booksShippedEachDay;
        libraries[i].whichBooks = new int[libraries[i].numberOfBooks];
        libraries[i].id = i;

        //scanning books in a library
        for(int j = 0; j < libraries[i].numberOfBooks; j++){
            cin >> libraries[i].whichBooks[j];
        }

        sort(libraries[i], books);
    }

    for(int i = 0; i < numberOfLibraries; i++){
        libraries[i].sum = 0;
        for(int j = 0; j < libraries[i].numberOfBooks; j++){
            libraries[i].sum += books[libraries[i].whichBooks[j]];
        }
        libraries[i].avg = (float)libraries[i].sum / libraries[i].numberOfBooks;
    }

    lensort(libraries, numberOfLibraries);

    cout << numberOfLibraries << endl;

    for(int i = 0; i < numberOfLibraries; i++){
        cout << libraries[i].id << " " << libraries[i].numberOfBooks << endl;
        for(int j = libraries[i].numberOfBooks-1; j >=0; j--){
            cout << libraries[i].whichBooks[j] << " ";
        }
        cout << endl;
    }
    
    cout << endl;
    return 0;
}
