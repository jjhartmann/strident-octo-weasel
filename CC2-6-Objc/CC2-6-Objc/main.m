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
        
        
    }
    return 0;
}
