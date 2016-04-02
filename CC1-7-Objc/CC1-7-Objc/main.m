//
//  main.m
//  CC1-7-Objc
//
//  Created by Jeremy Hartmann on 2016-03-19.
//  Copyright © 2016 Jeremy Hartmann. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MatrixUtils : NSObject
+ (void)zeroOutMatrix:(NSMutableArray *)matrix;

@end

@implementation MatrixUtils

+ (void)zeroOutMatrix:(NSMutableArray *)matrix
{
    NSInteger rows = [matrix count];
    NSInteger cols = [[matrix objectAtIndex:0] count];
    NSInteger rowMap[rows];
    NSInteger colMap[cols];
    
    // zero out rows and cols map
    bzero(&rowMap, sizeof(NSInteger)*rows);
    bzero(&colMap, sizeof(NSInteger)*cols);
    
    // Index all zeros
    for (int i = 0; i < [matrix count]; ++i)
    {
        NSMutableArray *row = [matrix objectAtIndex:i];
        for (int j = 0; j < [row count]; ++j)
        {
            NSNumber *num = [row objectAtIndex:j];
            if ([num isEqual:@0])
            {
                rowMap[i] = 1;
                colMap[j] = 1;
            }
        }
    }
    
    // Zero out matrix
    for (int i = 0; i < rows; ++i)
    {
        NSMutableArray *row = [matrix objectAtIndex:i];
        for (int j = 0; j < cols; ++j)
        {
            if (rowMap[i] || colMap[j])
            {
                [row replaceObjectAtIndex:j withObject:@0];
            }
        }
    }
}

@end

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        NSMutableArray *mat = [NSMutableArray arrayWithObjects:
                        [NSMutableArray arrayWithObjects:@1,@2,@3,@4,@5,nil],
                        [NSMutableArray arrayWithObjects:@6,@0,@8,@9,@10,nil],
                        [NSMutableArray arrayWithObjects:@11,@12,@13,@0,@15,nil],nil];
        
        [MatrixUtils zeroOutMatrix:mat];
        
    }
    return 0;
}
