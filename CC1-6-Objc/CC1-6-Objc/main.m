//
//  main.m
//  CC1-6-Objc
//
//  Created by Jeremy Hartmann on 2016-03-19.
//  Copyright © 2016 Jeremy Hartmann. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (EXArray)
- (NSArray *)rotateMatrix;
@end

@implementation NSArray (EXArray)

- (NSArray *)rotateMatrix
{
    
}

@end


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        // Create matrix
        NSArray *mat = [[NSArray alloc] initWithObjects:
                         @[@1,@2,@3,@4],
                         @[@5,@6,@7,@8],
                         @[@9,@10,@11,@12],
                         @[@13,@14,@15,@16],nil];
        
        
        
        
        
        
    }
    return 0;
}
