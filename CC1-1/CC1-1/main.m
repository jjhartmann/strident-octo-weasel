//
//  main.m
//  CC1-1
//
//  Created by Jeremy Hartmann on 2016-03-18.
//  Copyright © 2016 Jeremy Hartmann. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Solution : NSObject
+ (BOOL)isStringUnique1:(NSString *)string;
+ (BOOL)isStringUnique2;
@end

@implementation Solution

+ (BOOL)isStringUnique1:(NSString *)string
{
    NSInteger map[256];
    bzero(&map, sizeof(NSInteger)*256);
    
    for (int i = 0; i < [string length]; ++i)
    {
        NSInteger index = (NSInteger) [string characterAtIndex:i];
        ++map[index];
        if (map[index] > 1)
        {
            return NO;
        }
    }
    
    return YES;
}

@end


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        NSString *test = @"THiscanbe l";
        BOOL res = [Solution isStringUnique1:test];
        
    }
    return 0;
}
