//
//  main.m
//  CC2-5
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


/// Add two linked list number represenation (reverse order)
Node* add(Node *l, Node*r)
{
    return nil;
}

/// Convert number into linked list
Node* convertNumberToReverseLinkeList(NSInteger x)
{
    Node *head = [[Node alloc] initWithData:x%10];
    x = floor(x/10);
    
    Node *n = head;
    while (x)
    {
        n.next = [[Node alloc] initWithData:x % 10];
        x = floor(x/10);
        
        n = n.next;
    }
    
    return head;
}

/// Convert linked list to number repesentation
NSInteger convertLinkedListToNumber(Node *head)
{
    NSInteger multiplier = 0;
    NSInteger result = 0;
    Node *n = head;
    while(n)
    {
        result += n.data * pow(10, multiplier);
        n = n.next;
        multiplier++;
    }
    
    return result;
}

/// Create and return linked list
Node* createRandomLinkedList(int len, int max)
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
        
        Node *num1 = convertNumberToReverseLinkeList(4318);
        NSInteger x = convertLinkedListToNumber(num1);
        
        
        
        
    }
    return 0;
}
