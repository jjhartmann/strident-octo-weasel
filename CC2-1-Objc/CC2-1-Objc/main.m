//
//  main.m
//  CC2-1-Objc
//
//  Created by Jeremy Hartmann on 2016-03-19.
//  Copyright © 2016 Jeremy Hartmann. All rights reserved.
//

#import <Foundation/Foundation.h>
#include <stdlib.h>

@interface Node : NSObject
@property Node *next;
@property NSInteger data;
- (id) initWithData:(NSInteger)data;

@end

@implementation Node

- (id)initWithData:(NSInteger)data
{
    self = [super init];
    if (self)
    {
        _next = nil;
        _data = data;
    }
    
    return self;
}
@end


/// Solution class
@interface Solution : NSObject
+ (void)removeDuplicates:(Node *)head;
@end

@implementation Solution

+ (void)removeDuplicates:(Node *)head
{
    NSMutableSet *map = [NSMutableSet set];
    
    Node *n = head;
    Node *p = nil;
    while (n != nil)
    {
        if (![map containsObject:@(n.data)])
        {
            [map addObject:@(n.data)];
            p = n;
        }
        else
        {
            // remove from linked list
            p.next = n.next;
        }
        
        n = n.next;
    }
}

@end


/// Create random linked list with length 'len'
Node* createLinkedList(int len, int max)
{

    Node *head = [[Node alloc] initWithData:arc4random()%max];
    Node *n = head;
    for (int i = 0; i < len; ++i)
    {
        n.next = [[Node alloc] initWithData:arc4random()%max];
        n = n.next;
    }
    
    return head;
}


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        Node *head = createLinkedList(20, 5);
        [Solution removeDuplicates:head];
    }
    return 0;
}
