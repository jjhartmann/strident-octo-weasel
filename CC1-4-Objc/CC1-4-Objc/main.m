//
//  main.m
//  CC1-4-Objc
//
//  Created by Jeremy Hartmann on 2016-03-19.
//  Copyright © 2016 Jeremy Hartmann. All rights reserved.
//
//  Replace all ' ' with "%20".

#import <Foundation/Foundation.h>

@interface NSString (EXString)
- (NSString *)normailzeSpace;
@end

@implementation NSString (EXString)
- (NSString *)normailzeSpace
{
    NSInteger spaceCount = 0;
    for (int i = 0; i < self.length; ++i)
    {
        if ([self characterAtIndex:i] == ' ')
        {
            spaceCount++;
        }
    }
    
    NSInteger newLen = self.length + (spaceCount *2);
    char str[newLen];
    
    int j = 0;
    for (int i = 0; i < self.length; ++i)
    {
        str[j] = [self characterAtIndex:i];
        if (str[j] == ' ')
        {
            str[j] = '%';
            str[j + 1] = '2';
            str[j + 2] = '0';
            
            j += 2;
        }
        
        ++j;
    }
    
    return [NSString stringWithUTF8String:str];
    
}
@end



int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        // Trivial way to replace spaces.
        NSString *test = @"This is a test string.";
        NSString *result = [test stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet alphanumericCharacterSet]];
        
        NSString *test2 = @"This is a test to see if white space gets replaced";
        NSString *res = [test2 normailzeSpace];
        
        
    }
    return 0;
}
