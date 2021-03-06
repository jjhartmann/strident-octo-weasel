//
//  main.m
//  CC2-4-Objc
//
//  Created by Jeremy Hartmann on 2016-03-19.
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


void partition(Node* head, NSInteger x)
{
    
    Node *i = head;
    Node *n = head;
    while (n != nil)
    {
        if (n.data < x)
        {
            // Swap with i
            NSInteger tmp = n.data;
            n.data = i.data;
            i.data = tmp;
        
            i = i.next;
        }
        
        n = n.next;
    }
}


Node* createRandomLinkedlist(int len, int max)
{
    Node *head = [[Node alloc] initWithData:arc4random() % max];
    Node *n = head;
    for (int i = 0; i < len; ++i)
    {
        n.next = [[Node alloc] initWithData:arc4random() % max];
        n = n.next;
    }
    
    return head;
}


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        Node *head = createRandomLinkedlist(10, 20);
        partition(head, 10);
    }
    return 0;
}
