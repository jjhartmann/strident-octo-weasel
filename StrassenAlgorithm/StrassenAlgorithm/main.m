//
//  main.m
//  StrassenAlgorithm
//
//  Created by Jeremy Hartmann on 2016-02-13.
//  Copyright © 2016 Jeremy Hartmann. All rights reserved.
//

#import <Foundation/Foundation.h>


////////////////////////////////////////////////////////////////
/// Matrix Class
@interface P2Matrix : NSObject

@property NSInteger *mMatrix;
@property NSInteger mDim;

- (id) initWithPower2: (NSInteger) n inMax:(NSInteger) max;
- (NSInteger) at: (NSInteger) pos_i jPos: (NSInteger) pos_j;
- (void) printMatrix;

@end

@implementation P2Matrix

///////////////////////////////////////////////////////////////////
/// Deallocate the NSInterger array.
- (void) dealloc {
    if (_mMatrix != nil)
    {
        free(_mMatrix);
        _mMatrix = nil;
    }
}

///////////////////////////////////////////////////////////////////
/// Create a matrix that is a power of 2.
- (id) initWithPower2:(NSInteger)n inMax:(NSInteger) max
{
    self = [super init];
    if (self)
    {
        // build random matrix power of 2
        NSInteger pw2 = ceil(log2(n));
        NSInteger pwN = pow(2, pw2);
        BOOL pad = (pwN == n) ? NO : YES;
        
        // Set Dimension
        _mDim = pwN;
        
        // Create matrix buffer
        _mMatrix = (NSInteger*) malloc(sizeof(NSInteger) * pwN * pwN);
        
        // Build matrix
        for (NSInteger i = 0; i < pwN; ++i)
        {
            for (NSInteger j = 0; j < pwN; ++j)
            {
                NSInteger tmp = 0;
                if (i < n && j < n)
                {
                    tmp = random() % max;
                }
                
                _mMatrix[i * pwN + j] = tmp;
                
            }
        }
        
        
    }
    
    return self;
}


///////////////////////////////////////////////////////////////////
/// Get position i and j from Matrix
- (NSInteger) at:(NSInteger)pos_i jPos:(NSInteger)pos_j
{
    if (pos_i >= _mDim || pos_j >= _mDim)
    {
        // Out of bounds
        return -1;
    }
    
    return _mMatrix[pos_i * _mDim + pos_j];
}

///////////////////////////////////////////////////////////////////
/// Print Matrix to terminal
- (void) printMatrix
{
    NSMutableString *str = [[NSMutableString alloc] initWithString:@"\n"];
    for (NSInteger i = 0; i < _mDim; ++i)
    {
        for (NSInteger j = 0; j < _mDim; ++j)
        {
            [str appendString: [@(_mMatrix[i * _mDim + j]) stringValue]];
            [str appendString: @" "];

        }
        
        [str appendString: @"\n"];
    }
    
    NSLog(@"%@", str);
}

@end


///////////////////////////////////////////////////////////////////
/// Strassen Algorithm
NSInteger* strassenMatrixMultiplication(NSInteger *A, NSInteger *B)
{
    
    
    
    
    return nil;
}


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Simple Implementation of Strassen's Algorithm");
        
        P2Matrix *matA = [[P2Matrix alloc] initWithPower2:3 inMax:50];
        P2Matrix *matB = [[P2Matrix alloc] initWithPower2:3 inMax:50];
        
        // Print matrices.
        [matA printMatrix];
        [matB printMatrix];
        
    }
    return 0;
}
