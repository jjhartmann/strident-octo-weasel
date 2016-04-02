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
+ (BOOL)isStringUnique2:(NSString *)string;
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

+ (BOOL)isStringUnique2:(NSString *)string
{
    // Convert into NSArray
    NSMutableArray *charArray = [NSMutableArray arrayWithCapacity:string.length];
    for (int i = 0; i < string.length; ++i)
    {
        [charArray addObject:[string substringWithRange:NSMakeRange(i, 1)]];
    }
    
    NSArray *sorted = [charArray sortedArrayUsingComparator:^(NSString *a, NSString *b){
        return [a compare:b];
    }];
    
    for (int i = 1; i < sorted.count; ++i)
    {
        if ([[sorted objectAtIndex:i] isEqualToString:[sorted objectAtIndex:i-1]])
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
        
        NSString *test = @"THisc anbe l";
        BOOL res = [Solution isStringUnique2:test];
        
    }
    return 0;
}
