//
//  main.m
//  CreateBSTFromOrderedArray-ObjC
//
//  Created by Jeremy Hartmann on 2016-01-27.
//  Copyright © 2016 Jeremy Hartmann. All rights reserved.
//

#import <Foundation/Foundation.h>

////////////////////////////////////////////////////////////
/// Node Class - for BST
@interface Node : NSObject

@property Node* left;
@property Node* right;
@property int data;

-(id) initWithData:(int) d;

@end

@implementation Node

-(id)initWithData:(int)d
{
    self = [super init];
    if (self)
    {
        _data = d;
        _left = nil;
        _right = nil;
    }
    
    return self;
}

@end

////////////////////////////////////////////////////////////
/// Solution Class
@interface Solution : NSObject

+ (Node*) buildBST: (NSInteger*) elements;

@end

@implementation Solution

+(Node *)buildBST:(NSInteger *)elements
{
    return nil;
}

+(Node*) buildBSTR:(Node*) n beginInt:(int) b endInt:(int) e inArray:(NSInteger*) elements
{
    if (e - b <= 0) return nil;
    
    
    int index = b + ceil((e - b)/2);
    n = [[Node alloc] initWithData: (int) elements[index]];
    
    
    return nil;
}

         
@end


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Create a binary search tree from ordered array.");
        
        
        
        
    }
    return 0;
}
