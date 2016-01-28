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
@property NSInteger data;

-(id) initWithData:(NSInteger) d;

@end

@implementation Node

-(id)initWithData:(NSInteger)d
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

+ (Node*) buildBST: (NSInteger*) elements arraySize:(NSInteger)size;

@end

@implementation Solution

+(Node *)buildBST:(NSInteger *)elements arraySize:(NSInteger)size
{
    NSInteger begin = 0;
    NSInteger end = size - 1;
    
    Node *root = nil;
    root = [self buildBSTR:root beginInt:begin endInt:end inArray:elements];
    
    return root;
}

+(Node*) buildBSTR:(Node*) n beginInt:(NSInteger) b endInt:(NSInteger) e inArray:(NSInteger*) elements
{
    if (e - b < 0) return nil;
    
    
    int index = b + ceil(((double)e - (double)b)/2);
    n = [[Node alloc] initWithData: elements[index]];
    
    [n setLeft:[self buildBSTR:[n left] beginInt:b endInt:index - 1 inArray:elements]];
    [n setRight: [self buildBSTR:[n right] beginInt:index + 1 endInt:e inArray:elements]];
    
    return n;
}

         
@end


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Create a binary search tree from ordered array.");
        
        // Test Array
        NSInteger intArray[] = {0,1,2,3,4,5,6,7};
        NSInteger size = 8;
        Node *res = [Solution buildBST:intArray arraySize:size];
        
        
        NSLog(@"FINSIH");
        
    }
    return 0;
}
