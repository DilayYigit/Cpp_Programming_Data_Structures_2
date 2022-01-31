#include <iostream>
#include <string>
using namespace std;
#include "NgramTree.h"

int main( int argc, char **argv ) {
    NgramTree tree;
    string fileName( argv[1] );
    int n = atoi( argv[2] );
    tree.generateTree( fileName, n );

//    int n = 4;
//    tree.addNgram( "this" );
//    tree.addNgram( "samp" );
//    tree.addNgram( "ampl" );
//    tree.addNgram( "mple" );
//    tree.addNgram( "text" );
//    tree.addNgram( "this" );
//    tree.addNgram( "this" );


    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    cout << tree << endl;

    cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No") << endl;
    cout << n << "-gram tree is full: " << (tree.isFull() ? "Yes" : "No") << endl;

    // Before insertion of newn-grams
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;

    tree.addNgram( "samp" );
    tree.addNgram( "samp" );
    tree.addNgram( "zinc" );
    tree.addNgram( "aatt" );

    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl;
    cout << tree << endl;

    cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No") << endl;
    cout << n << "-gram tree is full: " << (tree.isFull() ? "Yes" : "No") << endl;

    return 0;
}
