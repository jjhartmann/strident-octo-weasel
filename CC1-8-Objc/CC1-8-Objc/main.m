//
//  main.m
//  CC1-8-Objc
//
//  Created by Jeremy Hartmann on 2016-03-19.
//  Copyright © 2016 Jeremy Hartmann. All rights reserved.
//

#import <Foundation/Foundation.h>
@interface NSString (EXString)
- (BOOL)isRotation:(NSString *)string;
@end;


@implementation NSString (EXString)
- (BOOL)isRotation:(NSString *)string
{
    NSInteger len1 = self.length;
    NSInteger len2 = string.length;
    
    // If not same lenght, can't be rotation
    if (len1 != len2)
    {
        return NO;
    }
    
    // Iteratre through string until match.
    int j = 0;
    BOOL isRotation = NO;
    for (int i = 0; i < 2*len1; ++i)
    {
        if ([self characterAtIndex:i%len1] == [string characterAtIndex:j%len1])
        {
            if(!isRotation) isRotation = YES;
            j++;
        }
        else
        {
            if (isRotation) isRotation = NO;
            if (j > 0) j = 0;
        }
    }
    
    return isRotation;
}
@end


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        
        NSString *test =  @"rotations";
        NSString *test2 = @"ationtrot";
        
        BOOL res = [test isRotation:test2];
        
    }
    return 0;
}
