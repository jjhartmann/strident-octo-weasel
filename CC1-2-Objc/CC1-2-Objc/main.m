//
//  main.m
//  CC1-2-Objc
//
//  Created by Jeremy Hartmann on 2016-03-18.
//  Copyright © 2016 Jeremy Hartmann. All rights reserved.
//

#import <Foundation/Foundation.h>

void reverse(char *str)
{
    char *prt1 = str;
    char *prt2 = str;
    while (*prt2 != '\0')
    {
        prt2++;
    }
    prt2--;
    
    while (prt1 != prt2)
    {
        char c = *prt1;
        *prt1 = *prt2;
        *prt2 = c;
        
        prt1++;
        prt2--;
    }
    
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        char str[] = "This is a test string";
        reverse(str);
        
        
        
    }
    return 0;
}
