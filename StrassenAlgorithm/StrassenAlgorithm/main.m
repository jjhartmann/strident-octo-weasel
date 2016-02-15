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
@interface Matrix : NSObject

@property NSInteger *mMatrix;
@property NSInteger mDim;

- (id) initWithPower2: (NSInteger) n inMax:(NSInteger) max;
- (NSInteger) at: (NSInteger) pos_i jPos: (NSInteger) pos_j;
- (void) printMatrix;
- (Matrix*) addMatrixInRange:(Matrix *)inB
                       rowBiMin:(NSInteger)B_Mini
                       rowBiMax:(NSInteger)B_Maxi
                       rowBjMin:(NSInteger)B_Minj
                       rowBjMax:(NSInteger)B_Maxj
                       rowAiMin:(NSInteger)A_Mini
                       rowAiMax:(NSInteger)A_Maxi
                       rowAjMin:(NSInteger)A_Minj
                       rowAjMax:(NSInteger)A_Maxj;
- (void) setAt:(NSInteger) inData pos_i:(NSInteger) i pos_j:(NSInteger) j;
- (NSInteger) getAt:(NSInteger) i pos_j:(NSInteger) j;


@end

@implementation Matrix

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

///////////////////////////////////////////////////////////////////
/// Add Matrix to this matrix.
- (Matrix*) addMatrixInRange:(Matrix *)inB
                        rowBiMin:(NSInteger)B_Mini
                        rowBiMax:(NSInteger)B_Maxi
                        rowBjMin:(NSInteger)B_Minj
                        rowBjMax:(NSInteger)B_Maxj
                        rowAiMin:(NSInteger)A_Mini
                        rowAiMax:(NSInteger)A_Maxi
                        rowAjMin:(NSInteger)A_Minj
                        rowAjMax:(NSInteger)A_Maxj
{
    NSInteger dim = B_Maxi - B_Mini;
    Matrix *tmp = [[Matrix alloc] initWithPower2: dim inMax:1]; // Don't Own
    
    for (NSInteger i = B_Mini; i < B_Maxi; ++i)
    {
        for (NSInteger j = B_Minj; j < B_Maxj; ++j)
        {
            [tmp setAt:_mMatrix[i * dim + j] + inB.mMatrix[i * dim + j] pos_i:(i - B_Mini) pos_j:(j - B_Minj)];
        }
    }
    
    return tmp;
}

///////////////////////////////////////////////////////////////////
/// Replace data point at i and j
- (void) setAt:(NSInteger) inData pos_i:(NSInteger) i pos_j:(NSInteger) j
{
    if (i >= _mDim || j >= _mDim)
    {
        // Invalid dimension.
        return;
    }
    
    _mMatrix[i * _mDim + j] = inData;
}

///////////////////////////////////////////////////////////////////
/// Get data at row i and column j
- (NSInteger) getAt:(NSInteger)i pos_j:(NSInteger)j
{
    // Check bounds.
    if (i >= _mDim || i < 0 || j >= _mDim || j < 0) return -1;
    
    return _mMatrix[i * _mDim + j];
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
        
        Matrix *matA = [[Matrix alloc] initWithPower2:3 inMax:50];
        Matrix *matB = [[Matrix alloc] initWithPower2:3 inMax:50];
        
        // Print matrices.
        [matA printMatrix];
        [matB printMatrix];
        
        Matrix *matC = [matA addMatrixInRange:matB rowBiMin:0 rowBiMax:4 rowBjMin:0 rowBjMax:4 rowAiMin:0 rowAiMax:4 rowAjMin:0 rowAjMax:4];
        [matC printMatrix];
    }
    return 0;
}
