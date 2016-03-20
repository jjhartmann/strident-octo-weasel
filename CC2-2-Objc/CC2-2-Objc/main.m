//
//  main.m
//  CC2-2-Objc
//
//  Created by Jeremy Hartmann on 2016-03-19.
//  Copyright © 2016 Jeremy Hartmann. All rights reserved.
//

#import <Foundation/Foundation.h>

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


@interface Solution : NSObject
+ (Node *)findKthToLastElement:(Node *)head elementk:(NSInteger)k;
@end

@implementation Solution

+ (Node *)findKthToLastElement:(Node *)head elementk:(NSInteger)k
{
    // Define a two pointers: runner and walk.
    Node *run = head;
    Node *walk = head;
    
    NSInteger index = 0;
    while (run != nil)
    {
        if (index >= k)
        {
            walk = walk.next;
        }
    
        run = run.next;
        ++index;
    }
    
    return walk;
}
@end


/// Build random linked list
Node* createRandomLinkedList(int len, int max)
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
        
        Node *head = createRandomLinkedList(10, 10);
        
        Node *res = [Solution findKthToLastElement:head elementk:4];
        
        
        
        
    }
    return 0;
}
