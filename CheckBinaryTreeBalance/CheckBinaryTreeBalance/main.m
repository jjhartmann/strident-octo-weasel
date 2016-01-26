//
//  main.m
//  CheckBinaryTreeBalance
//
//  Created by Jeremy Hartmann on 2016-01-25.
//  Copyright © 2016 Jeremy Hartmann. All rights reserved.
//

#import <Foundation/Foundation.h>

///////////////////////////////////////////////////////////////////
/// Node Class
@interface Node : NSObject

@property int mData;
@property Node *left;
@property Node *right;

@end

@implementation Node

-(id) initWithData: (int) d
{
    self = [super init];
    if (self){
        _mData = d;
        _left = nil;
        _right = nil;
    }
    
    return self;
}

@end

///////////////////////////////////////////////////////////////////
/// Build Random Tree
Node* BuildRandomTree()
{
    int MAX = 20;
    Node *root = [[Node alloc]initWithData:0];
    
    srand(time(0));
    // Temp vec to store leafs.
    NSMutableArray *tmpVec = [[NSMutableArray alloc] initWithObjects:root, nil];
    
    for (int i = 0; i < 20; ++i) {
        
        int rnd = rand();
        int index = rnd % [tmpVec count];
        Node *n = tmpVec[index];
        
        
        if(rand() % 2 && ![n left])
        {
            [n setLeft:[[Node alloc] initWithData:rnd % MAX] ];
            [tmpVec addObject:[n left]];
            
        }else if (![n right])
        {
            [n setRight:[[Node alloc] initWithData:rnd % MAX] ];
            [tmpVec addObject:[n right]];
        }else if (![n left])
        {
            [n setLeft:[[Node alloc] initWithData:rnd % MAX] ];
            [tmpVec addObject:[n left]];
        }
        
        if ([n right] && [n left])
        {
            // Remove element.
            [tmpVec removeObjectAtIndex:index];
        }
        
    }
    
    return root;
    
    
}




int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        // Build the array
        Node *root = BuildRandomTree();
        
    }
    return 0;
}
