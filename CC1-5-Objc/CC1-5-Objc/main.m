//
//  main.m
//  CC1-5-Objc
//
//  Created by Jeremy Hartmann on 2016-03-19.
//  Copyright © 2016 Jeremy Hartmann. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (EXString)
- (NSString *)compress;
@end

@implementation NSString (EXString)
- (NSString *)compress
{
    NSMutableString *tmp = [[NSMutableString alloc] init];
    
    int charCount = 0;
    char prevC = 0;
    for (int i = 0; i < self.length; ++i)
    {
        char currC = [self characterAtIndex:i];
        if (currC != prevC)
        {
            if (charCount > 0)
            {
                [tmp appendFormat:@"%i", charCount];
            }
            prevC = currC;
            [tmp appendFormat:@"%c", currC];
            charCount = 0;
        }
        
        charCount++;
    }
    
    [tmp appendFormat:@"%i", charCount];
    
    if (tmp.length < self.length)
        return [NSString stringWithString:tmp];
    else
        return self;
}
@end

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        NSString *test = @"aabbcccccd";
        NSString *res = [test compress];
        
    }
    return 0;
}
