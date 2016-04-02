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

/// Create and return linked list
Node* createLinkedList(int len)
{
    Node *head = [[Node alloc] initWithData:0];
    Node *n = head;
    
    for (int i = 1; i < len; ++i)
    {
        n.next = [[Node alloc] initWithData:i];
        n = n.next;
    }
    
    return head;
}

/// Add two linked list number represenation (reverse order)
Node* add(Node *l, Node*r)
{
    NSInteger lint = convertLinkedListToNumber(l);
    NSInteger rint = convertLinkedListToNumber(r);
    NSInteger sum = lint + rint;
    Node *result = convertNumberToReverseLinkeList(sum);
    return result;
}


Node* swapPairs(Node* head) {
    if (!head)
    {
        return head;
    }
    if (!head.next)
    {
        return head;
    }
    if (!head.next.next)
    {
        Node *tmp = head.next;
        tmp.next = head;
        head.next = nil;
        
        return tmp;
    }
    
    Node *tmp = head.next;
    Node *tmp2 = tmp.next;
    tmp.next = head;
    head.next = tmp2;
    
    head = tmp;
    Node *n = head.next.next;
    Node *p = head.next;
    while (n.next != nil)
    {
        Node *t1 = n.next;
        Node *t2 = t1.next;
        t1.next = n;
        n.next = t2;
        p.next = t1;
        p = n;
        n = t2;
    }
    
    
    return head;
}


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        Node *num1 = convertNumberToReverseLinkeList(4318);
        NSInteger x = convertLinkedListToNumber(num1);
        
        Node *head = createLinkedList(7);
        Node *res = swapPairs(head);
        
    }
    return 0;
}
