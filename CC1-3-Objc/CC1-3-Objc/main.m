//
//  main.m
//  CC1-3-Objc
//
//  Created by Jeremy Hartmann on 2016-03-18.
//  Copyright © 2016 Jeremy Hartmann. All rights reserved.
//
// Check if one string is permutatino of another


#import <Foundation/Foundation.h>

@interface NSString (EXString)

- (BOOL)isPermutation:(NSString *)string;
@end

@implementation NSString (EXString)
- (BOOL)isPermutation:(NSString *)string
{
    const char *s1 = [self UTF8String];
    const char *s2 = [string UTF8String];
    
    NSInteger map[256];
    bzero(&map, sizeof(NSInteger)*256);
    
    // map s1
    const char *p = s1;
    while (*p != '\0') {
        ++map[(NSInteger)*p];
        p++;
    }
    
    // Map s2
    p = s2;
    while (*p != '\0') {
        --map[(NSInteger)*p];
        if (map[(NSInteger)*p] < 0)
        {
            return NO;
        }
        
        ++p;
    }
    
    return YES;
}

@end

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        NSString *test1 = @" sisihT";
        NSString *test2 = @"This is";
        
        BOOL res = [test1 isPermutation:test2];
        
    }
    return 0;
}
