/* Author:      Benjamin A Garza III
 * Date:        September 2, 2019
 * Source:      fdot.c
 * Course:      CMPS 3240 Architecture
 * Assignment:  Lab 1 - Introduction to Benchmarking
 *
 * Compile:
 *      gcc -Wall fdot.c -o fdot
 *
 * Run:
 *      time ./fdot
 *
 * Purpose: 
 *      This program is designed to benchmark tests the floating point 
 *      multiplication speed of a processor (Cruz).
 */

#include <stdio.h>
#include <stdlib.h>

//  The benchmark function. FDOT takes two integer arrays. It adds the two 
//  arrays, element by element, storing the results in Result.
void fdot( int length, float *X, float *Y, float *Result ) {
    for( int i = 0; i < length; i++ )
	Result[i] = X[i] + Y[i];
}

//  The benchmark
int main( void ) {
    const int N = 200000000; // The benchmark runs on a fixed size of work
    printf( "Running fdot operation of size %d x 1\n", N );

    //  Create three N x 1 matrixes on the heap using malloc. There are
    //  generally two reasons why we do not want to do this statically i.e. int
    //  X[N]. One, with the benchmark program we're making we may exceed the
    //  allowable size of a static array (yep, this is possible given we are
    //  taxing the system). Two, if you wanted to, you could dynamically adjust
    //  the workload via the command line (though this is not how it is currently
    //  set up).
    float *X = (float *) malloc( N * sizeof(float) );      // First vector
    float *Y = (float *) malloc( N * sizeof(float) );      // Second vector
    float *Result = (float *) malloc( N * sizeof(float) ); // Result vector

    // Carry out the operation
    fdot( N, X, Y, Result );

    // Free up the memory
    free( X );
    free( Y );
    free( Result );

    return 0;
}

