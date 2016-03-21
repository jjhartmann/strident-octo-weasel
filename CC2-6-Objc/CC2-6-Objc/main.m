//
//  main.m
//  CC2-6-Objc
//
//  Created by Jeremy Hartmann on 2016-03-21.
//  Copyright © 2016 Jeremy Hartmann. All rights reserved.
//

#import <Foundation/Foundation.h>



@interface Node : NSObject
@property Node *next;
@property NSInteger data;

- (id)initWithData:(NSInteger)data;
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

@interface Solution : NSObject
+ (Node *)findStartofCircle:(Node *)head;

@end

@implementation Solution

+ (Node *)findStartofCircle:(Node *)head
{
    Node *pt1 = head.next;
    Node *pt2 = head.next.next;
    
    // Find collision point
    while (pt2 != pt1)
    {
        // Walker
        pt1 = pt1.next;
        
        // Runner
        pt2 = pt2.next.next;
    }
    
    // Walk from head to start of circle
    pt1 = head;
    while (pt1 != pt2)
    {
        pt2 = pt2.next;
        pt1 = pt1.next;
    }
    
    return pt1;
}


@end

/// Build random circular linked list
Node* createCircularLinkedList(int len)
{
    Node *head = [[Node alloc] initWithData:0];
    Node *n = head;
    NSInteger start = arc4random() % len;
    Node *startNode = nil;
    for (int i = 1; i < len; ++i)
    {
        n.next = [[Node alloc] initWithData:i];
        if (start == i)
        {
            startNode = n.next;
        }
        
        n = n.next;
    }
    
    // Set circle
    n.next = startNode;
    
    return head;
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        // BUild circular linked list
        Node *head = createCircularLinkedList(10);
        Node *start = [Solution findStartofCircle:head];
        
    }
    return 0;
}
