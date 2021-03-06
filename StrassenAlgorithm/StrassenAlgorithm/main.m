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
- (id) initWithInt: (NSInteger) n inMax:(NSInteger) max;
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
- (Matrix*) subtractMatrixInRange:(Matrix *)inB
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
- (Matrix*) getSubmatrix:(NSInteger)min_i
                 rowMaxi:(NSInteger)max_i
                 colMinj:(NSInteger)min_j
                 colMaxj:(NSInteger) max_j;
- (Matrix*) addMatrix:(Matrix*) inB;
- (Matrix*) subtractMatrix:(Matrix*) inB;


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
/// Create a matrix based on dimensions
- (id) initWithInt:(NSInteger)n inMax:(NSInteger) max
{
    self = [super init];
    if (self)
    {
        // Set Dimension
        _mDim = n;
        
        // Create matrix buffer
        _mMatrix = (NSInteger*) malloc(sizeof(NSInteger) * n * n);
        
        // Build matrix
        for (NSInteger i = 0; i < n; ++i)
        {
            for (NSInteger j = 0; j < n; ++j)
            {
                NSInteger tmp = random() % max;;
                _mMatrix[i * n + j] = tmp;
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
    NSInteger dimB = B_Maxi - B_Mini;
    NSInteger dimA = A_Maxi - A_Mini;
    
    // Verify same dimensions
    if (dimA != dimB || A_Maxi > _mDim || A_Maxj > _mDim) return nil;
    
    // Create new zero matrix with given dimensions.
    Matrix *tmp = [[Matrix alloc] initWithInt: dimA inMax:1]; // Don't Own
    
    for (NSInteger i = 0; i < dimA; ++i)
    {
        for (NSInteger j = 0; j < dimA; ++j)
        {
            [tmp setAt:_mMatrix[(i + A_Mini) * _mDim + (j + A_Minj)] + inB.mMatrix[(i + B_Mini) * [inB mDim] + (j + B_Minj)] pos_i:i pos_j:j];
        }
    }
    
    return tmp;
}

///////////////////////////////////////////////////////////////////
/// Subtract Matrix against self
- (Matrix*) subtractMatrixInRange:(Matrix *)inB
                    rowBiMin:(NSInteger)B_Mini
                    rowBiMax:(NSInteger)B_Maxi
                    rowBjMin:(NSInteger)B_Minj
                    rowBjMax:(NSInteger)B_Maxj
                    rowAiMin:(NSInteger)A_Mini
                    rowAiMax:(NSInteger)A_Maxi
                    rowAjMin:(NSInteger)A_Minj
                    rowAjMax:(NSInteger)A_Maxj
{
    NSInteger dimB = B_Maxi - B_Mini;
    NSInteger dimA = A_Maxi - A_Mini;
    
    // Verify same dimensions
    if (dimA != dimB || A_Maxi > _mDim || A_Maxj > _mDim) return nil;
    
    // Create new zero matrix with given dimensions.
    Matrix *tmp = [[Matrix alloc] initWithInt: dimA inMax:1]; // Don't Own
    
    for (NSInteger i = 0; i < dimA; ++i)
    {
        for (NSInteger j = 0; j < dimA; ++j)
        {
            [tmp setAt:(_mMatrix[(i + B_Mini) * _mDim + (j + B_Minj)] - inB.mMatrix[(i + A_Mini) * [inB mDim] + (j + A_Minj)]) pos_i:i pos_j:j];
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

///////////////////////////////////////////////////////////////////
/// Get a submatrix from self.
- (Matrix*) getSubmatrix:(NSInteger)min_i rowMaxi:(NSInteger)max_i colMinj:(NSInteger)min_j colMaxj:(NSInteger)max_j
{
    NSInteger rowDim = max_i - min_i;
    NSInteger colDim = max_j - min_j;
    if (rowDim != colDim) return nil;
    
    Matrix *tmp = [[Matrix alloc] initWithInt:rowDim inMax:1]; // Don't Own
    
    for (int i = 0; i < rowDim; ++i)
    {
        for (int j = 0; j < colDim; ++j)
        {
            NSInteger val = _mMatrix[(i + min_i) * _mDim + (j + min_j)];
            [tmp setAt:val pos_i:i pos_j:j];
        }
    }
    
    return tmp;
}

///////////////////////////////////////////////////////////////////
/// Add entire matrix and return new matrix
- (Matrix*) addMatrix:(Matrix *)inB
{
    // Bound checking.
    if (_mDim != [inB mDim]) return nil;
    
    
    Matrix *tmp = [[Matrix alloc] initWithInt:_mDim inMax:1];
    
    for (int i = 0; i < _mDim; ++i)
    {
        for (int j = 0; j < _mDim; ++j)
        {
            NSInteger vala = [self getAt:i pos_j:j];
            NSInteger valb = [inB getAt:i pos_j:j];
            [tmp setAt:vala + valb pos_i:i pos_j:j];
        }
    }
    
    return tmp;
}

///////////////////////////////////////////////////////////////////
/// Subtract entire matrix and return new matrix
- (Matrix*) subtractMatrix:(Matrix *)inB
{
    // Bound checking.
    if (_mDim != [inB mDim]) return nil;
    
    
    Matrix *tmp = [[Matrix alloc] initWithInt:_mDim inMax:1];
    
    for (int i = 0; i < _mDim; ++i)
    {
        for (int j = 0; j < _mDim; ++j)
        {
            NSInteger vala = [self getAt:i pos_j:j];
            NSInteger valb = [inB getAt:i pos_j:j];
            [tmp setAt:vala - valb pos_i:i pos_j:j];
        }
    }
    
    return tmp;
}

@end

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
/// Merge 4 Matrices into 1;
Matrix* Merge(Matrix* C11, Matrix* C12, Matrix* C21, Matrix* C22)
{
    int dim = [C11 mDim];
    
    // Create zero matrix
    Matrix *tmp = [[Matrix alloc] initWithInt:2*dim inMax:1];
    
    for (int i = 0; i < 2*dim; ++i)
    {
        for (int j = 0; j < 2*dim; ++j)
        {
            // Merge the matrices here.
            NSInteger val = 0;
            if (i < dim && j < dim)
            {
                // C11
                val = [C11 getAt:i pos_j:j];
            }
            else if (i < dim && j >= dim)
            {
                // C12
                val = [C12 getAt:i pos_j:j - dim];
                
            }
            else if (i >= dim && j < dim)
            {
                // C21
                val = [C21 getAt:i - dim pos_j:j];
            }
            else
            {
                // C22
                val = [C22 getAt:i - dim pos_j:j - dim];
            }
            
            // Set val in new matrix
            [tmp setAt:val pos_i:i pos_j:j];
        }
    }
    
    
    return tmp;
}

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
/// Strassen Algorithm
Matrix* strassenMatrixMultiplication(Matrix *A, Matrix *B)
{
    // Base case
    if ([A mDim] <=1)
    {
        NSInteger a = [A getAt:0 pos_j:0];
        NSInteger b = [B getAt:0 pos_j:0];
        NSInteger res = a * b;
        
        [A setAt:res pos_i:0 pos_j:0];
        return A;
    }
    
    // Get dimensions
    NSInteger begin = 0;
    NSInteger mid = [A mDim]/2;
    NSInteger end = [A mDim];
    
    // Build S1 .. S10
    Matrix *S1 = [A addMatrixInRange:A
                           rowBiMin:begin
                           rowBiMax:mid
                           rowBjMin:begin
                           rowBjMax:mid
                           rowAiMin:mid
                           rowAiMax:end
                           rowAjMin:mid
                           rowAjMax:end];
    
    Matrix *S2 = [B addMatrixInRange:B
                            rowBiMin:mid
                            rowBiMax:end
                            rowBjMin:mid
                            rowBjMax:end
                            rowAiMin:begin
                            rowAiMax:mid
                            rowAjMin:begin
                            rowAjMax:mid];
    
    Matrix *S3 = [A addMatrixInRange:A
                            rowBiMin:mid
                            rowBiMax:end
                            rowBjMin:begin
                            rowBjMax:mid
                            rowAiMin:mid
                            rowAiMax:end
                            rowAjMin:mid
                            rowAjMax:end];
    
    Matrix *S4 = [B subtractMatrixInRange:B
                            rowBiMin:begin
                            rowBiMax:mid
                            rowBjMin:mid
                            rowBjMax:end
                            rowAiMin:mid
                            rowAiMax:end
                            rowAjMin:mid
                            rowAjMax:end];
    
    Matrix *S5 = [B subtractMatrixInRange:B
                            rowBiMin:mid
                            rowBiMax:end
                            rowBjMin:begin
                            rowBjMax:mid
                            rowAiMin:begin
                            rowAiMax:mid
                            rowAjMin:begin
                            rowAjMax:mid];
    
    Matrix *S6 = [A addMatrixInRange:A
                            rowBiMin:begin
                            rowBiMax:mid
                            rowBjMin:begin
                            rowBjMax:mid
                            rowAiMin:begin
                            rowAiMax:mid
                            rowAjMin:mid
                            rowAjMax:end];
    
    Matrix *S7 = [A subtractMatrixInRange:A
                            rowBiMin:mid
                            rowBiMax:end
                            rowBjMin:begin
                            rowBjMax:mid
                            rowAiMin:begin
                            rowAiMax:mid
                            rowAjMin:begin
                            rowAjMax:mid];
    
    Matrix *S8 = [B addMatrixInRange:B
                            rowBiMin:begin
                            rowBiMax:mid
                            rowBjMin:begin
                            rowBjMax:mid
                            rowAiMin:begin
                            rowAiMax:mid
                            rowAjMin:mid
                            rowAjMax:end];
    
    Matrix *S9 = [A subtractMatrixInRange:A
                            rowBiMin:begin
                            rowBiMax:mid
                            rowBjMin:mid
                            rowBjMax:end
                            rowAiMin:mid
                            rowAiMax:end
                            rowAjMin:mid
                            rowAjMax:end];
    
    Matrix *S10 = [B addMatrixInRange:B
                             rowBiMin:mid
                             rowBiMax:end
                             rowBjMin:begin
                             rowBjMax:mid
                             rowAiMin:mid
                             rowAiMax:end
                             rowAjMin:mid
                             rowAjMax:end];
    
    // Get Submatrices
    Matrix *B11 = [B getSubmatrix:begin rowMaxi:mid colMinj:begin colMaxj:mid];
    Matrix *A11 = [A getSubmatrix:begin rowMaxi:mid colMinj:begin colMaxj:mid];
    Matrix *A22 = [A getSubmatrix:mid rowMaxi:end colMinj:mid colMaxj:end];
    Matrix *B22 = [B getSubmatrix:mid rowMaxi:end colMinj:mid colMaxj:end];
    
    // Conquer on S1..S10
    Matrix *M1 = strassenMatrixMultiplication(S1, S2);
    Matrix *M2 = strassenMatrixMultiplication(S3, B11);
    Matrix *M3 = strassenMatrixMultiplication(A11, S4);
    Matrix *M4 = strassenMatrixMultiplication(A22, S5);
    Matrix *M5 = strassenMatrixMultiplication(S6, B22);
    Matrix *M6 = strassenMatrixMultiplication(S7, S8);
    Matrix *M7 = strassenMatrixMultiplication(S9, S10);
    
    // Merge Stage: M1..M7 and build components C11..C22
    Matrix *C11 = [M1 addMatrix:[M4 addMatrix:[M7 subtractMatrix:M5]]];
    Matrix *C12 = [M3 addMatrix:M5];
    Matrix *C21 = [M2 addMatrix:M4];
    Matrix *C22 = [M1 addMatrix:[M3 addMatrix:[M6 subtractMatrix:M2]]];
    
    // Merge C11..C22 into larger matrix.
    Matrix *C = Merge(C11, C12, C21, C22);
    return C;
}


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Simple Implementation of Strassen's Algorithm");
        
        Matrix *matA = [[Matrix alloc] initWithPower2:3 inMax:10];
        Matrix *matB = [[Matrix alloc] initWithPower2:3 inMax:10];
        Matrix *matF = [[Matrix alloc] initWithPower2:3 inMax:10];
        Matrix *matG = [[Matrix alloc] initWithPower2:3 inMax:10];
        
        // Print matrices.
        [matA printMatrix];
        [matB printMatrix];
        [matF printMatrix];
        [matG printMatrix];
        
//        Matrix *matC = [matA addMatrixInRange:matA rowBiMin:0 rowBiMax:2 rowBjMin:0 rowBjMax:2 rowAiMin:0 rowAiMax:2 rowAjMin:0 rowAjMax:2];
//        [matC printMatrix];
//
//        Matrix *matD = [matA getSubmatrix:0 rowMaxi:1 colMinj:1 colMaxj:2];
//        [matD printMatrix];
//        
//        Matrix *matE = [matA subtractMatrix:matB];
//        [matE printMatrix];
//        
//        Matrix *matH = Merge(matA, matB, matF, matG);
//        [matH printMatrix];
        
        Matrix *Result = strassenMatrixMultiplication(matA, matB);
        [Result printMatrix];
    }
    return 0;
}
