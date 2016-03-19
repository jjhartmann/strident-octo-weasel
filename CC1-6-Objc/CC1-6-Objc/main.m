//
//  main.m
//  CC1-6-Objc
//
//  Created by Jeremy Hartmann on 2016-03-19.
//  Copyright © 2016 Jeremy Hartmann. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSMutableArray (EXArray)
- (void)rotateMatrix90Degress;
@end

@implementation NSMutableArray (EXArray)
- (double)convertDegreetoRadians:(NSInteger) degree
{
    return (degree * M_PI)/180;
}

- (void)rotateMatrix90Degress
{
    // Rotate NxN Matrix
    NSInteger ysize = [self count];
    NSInteger roundSize = ysize -1;
    NSInteger diagIndex = 0;
    NSInteger pivot = ceil(ysize/2);
    while (roundSize > 0)
    {
        // Each node in matrix round
        for (int i = 0; i < roundSize; ++i)
        {
            int x = 0;
            int y = 0;
            int xprime = diagIndex + i;
            int yprime = diagIndex;
            
            // For each transformation on node
            NSNumber *node2 = [[self objectAtIndex:yprime] objectAtIndex:xprime];
            for (int j = 0; j < 4; ++j)
            {
                x = xprime;
                y = yprime;
                
                NSNumber *node1 = node2;
                
                // transform to new coordinate system
                xprime = -y + (ysize - 1); // shift into positive coordinates
                yprime = x;
                
                node2 = [[self objectAtIndex:yprime] objectAtIndex:xprime];
                
                // insert
                [[self objectAtIndex:yprime] replaceObjectAtIndex:xprime withObject:node1];
            }
        }
        
        // Next round is
        diagIndex++;
        roundSize -= 2;
    }
}

@end


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        // Create matrix
        NSMutableArray *mat = [[NSMutableArray alloc] initWithObjects:
                         [NSMutableArray arrayWithObjects:@1,@2,@3,@4,nil],
                         [NSMutableArray arrayWithObjects:@5,@6,@7,@8,nil],
                         [NSMutableArray arrayWithObjects:@9,@10,@11,@12,nil],
                         [NSMutableArray arrayWithObjects:@13,@14,@15,@16,nil],nil];
        
        [mat rotateMatrix90Degress];
        
        
        
        
    }
    return 0;
}
