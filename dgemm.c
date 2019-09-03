/* Author:      Benjamin A Garza III
 * Date:        September 2, 2019
 * Source:      dgemm.c
 * Course:      CMPS 3240 Architecture
 * Assignment:  Lab 1 - Introduction to Benchmarking
 *
 * Compile:
 *      gcc -Wall dgemm.c -o dgemm
 *
 * Run:
 *      time ./dgemm
 *
 * Purpose: 
 *      This program is designed to benchmark tests floating point operations
 *      (Cruz).
 */

#include <stdio.h>
#include <stdlib.h>

//  The benchmark function. IAXPY takes two integer arrays and a scalar as
//  input. It adds the two arrays, element by element, storing the results in
//  Result. The first term is multiplied by the scalar, called A. Hence, why
//  it is called AXPY: scalar A times X plus Y. The I in the name indicates it
//  is an integer.
void fdot( int length, double *X, double *Y, double *Result ) {
    for( int i = 0; i < length; i++ )
	for ( int j = 0; j < length; ++j ) {
	    double cij = Result[ i + j + length ];
	    
	    for ( int k = 0; k < length; ++k )
		cij += X[ i + k * length ] * Y[ k + j * length ];
	    
	    Result[ i + j * length ] = cij;
	}
}

//  The benchmark
int main( void ) {
    const int N = 1024; // The benchmark runs on a fixed size of work
    printf( "Running dgemm operation of size %d x %d\n", N , N );

    //  Create three N x N matrixes on the heap using malloc. There are
    //  generally two reasons why we do not want to do this statically i.e. float
    //  X[N]. One, with the benchmark program we're making we may exceed the
    //  allowable size of a static array (yep, this is possible given we are
    //  taxing the system). Two, if you wanted to, you could dynamically adjust
    //  the workload via the command line (though this is not how it is currently
    //  set up).
    double *X = (double *) malloc( N * N * sizeof(double) );      // First vector
    double *Y = (double *) malloc( N * N * sizeof(double) );      // Second vector
    double *Result = (double *) malloc( N * N * sizeof(double) ); // Result vector

    // Carry out the operation
    fdot( N, X, Y, Result );

    // Free up the memory
    free( X );
    free( Y );
    free( Result );

    return 0;
}

