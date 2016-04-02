//
//  main.m
//  CutRodDP-Objc
//
//  Created by Jeremy Hartmann on 2016-03-25.
//  Copyright © 2016 Jeremy Hartmann. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Solution : NSObject
+ (NSInteger)cuttingRod:(NSArray *)price length:(NSInteger)length;

@end

@implementation Solution

+ (NSInteger)cuttingRod:(NSArray *)price length:(NSInteger)length
{
    // Buffer
    NSInteger buffer[length];
    bzero(&buffer, sizeof(NSInteger)*length);
    for (NSInteger i = 0; i < length; ++i)
    {
        NSInteger max = INT32_MIN;
        for (NSInteger j = 0; j <= i; ++j)
        {
            NSInteger val = buffer[j] + [[price objectAtIndex:i-j] integerValue];
            if (max < val)
                max = val;
        }
        buffer[i] = max;
    }
    
    
    
    return buffer[length - 1];
}

@end

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Cutting Rod");
        NSArray *price = @[@0, @1, @3, @4, @6, @6, @7, @8, @15, @25, @44];
        NSInteger result = [Solution cuttingRod:price length:9];
    }
    return 0;
}
