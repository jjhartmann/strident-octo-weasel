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
/// Solution Class
@interface Solution : NSObject

// Class Method (static)
+(BOOL) checkForBalancedTree: (Node*) root;
@end

@implementation Solution
// Use recursion to find depth and compare min and max levels.
+(void) checkForBalanceRecursion:(Node*)n minInt:(int*)min maxInt:(int*)max countInt:(int)count
{
    if (!n)
    {
        if (count > *max) *max = count;
        if (count < *min) *min = count;
        
        return;
    }
    
    ++count;
    
    if (![n left] || ![n right])
    {
        if (count > *max) *max = count;
        if (count < *min) *min = count;
    }
    
    [self checkForBalanceRecursion:[n left] minInt:min maxInt:max countInt:count];
    [self checkForBalanceRecursion:[n right] minInt:min maxInt:max countInt:count];
}

// Check if a tree is balanced
+(BOOL)checkForBalancedTree:(Node *)root
{
    int min = INT32_MAX;
    int max = INT32_MIN;
    int count = 0;
    
    [self checkForBalanceRecursion:root minInt:&min maxInt:&max countInt:count];
    
    return (max - min <= 1) ? YES : NO;
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
        
        BOOL res = [Solution checkForBalancedTree:root];
        NSLog(@"The result is: %i \nFor the tree: %@", res, root);
        
    }
    return 0;
}
