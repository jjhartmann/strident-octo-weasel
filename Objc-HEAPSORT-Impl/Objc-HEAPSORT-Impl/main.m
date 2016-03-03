//
//  main.m
//  Objc-HEAPSORT-Impl
//
//  Created by Jeremy Hartmann on 2016-03-01.
//  Copyright © 2016 Jeremy Hartmann. All rights reserved.
//

#import <Foundation/Foundation.h>




@interface HEAPSORT : NSObject {
    
}

// Public method access
+ (void)heapSort:(NSMutableArray *) inArr;


@end

// Private Methods
@interface HEAPSORT (Helpers)
+ (void)buildMaxHeap:(NSMutableArray *)inArr;
+ (void)heapify:(NSMutableArray *)inArr index:(NSInteger)i;
+ (NSInteger)left:(NSInteger)i;
+ (NSInteger)right:(NSInteger)i;
@end

@implementation HEAPSORT

+ (void)heapSort:(NSMutableArray *)inArr
{
    
    
}

// Private Methods
+ (void)buildMaxHeap:(NSMutableArray *)inArr
{
    NSInteger size = [inArr count];
    for (NSInteger i = (NSInteger) floor(size/2); i >= 0; --i)
    {
        [self heapify:inArr index:i];
    }
}

+ (void)heapify:(NSMutableArray *)inArr index:(NSInteger)i
{
    NSInteger lchild = [self left:i];
    NSInteger rchild = [self right:i];
    NSInteger size = [inArr count];
    NSInteger largest = i;
    
    if (lchild < size && [inArr objectAtIndex:lchild] > [inArr objectAtIndex:largest])
    {
        largest = lchild;
    }
    
    if (rchild < size && [inArr objectAtIndex:rchild] > [inArr objectAtIndex:largest])
    {
        largest = rchild;
    }
    
    if (largest != i)
    {
        NSNumber *tmp = [inArr objectAtIndex:i];
        [inArr replaceObjectAtIndex:i withObject:[inArr objectAtIndex:largest]];
        [inArr replaceObjectAtIndex:largest withObject:tmp];
        [self heapify:inArr index:largest];
    }
    
    
}

+ (NSInteger)left:(NSInteger)i
{
    return 2*i + 1;
}

+ (NSInteger)right:(NSInteger)i
{
    return 2*i + 2;
}

@end



int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Simple Heapsort Impl");
        
        NSMutableArray *arr = [[NSMutableArray alloc] initWithObjects:@1,@9,@4,@5,@3,@9,@8,@1,@6,@0, nil];
        [HEAPSORT buildMaxHeap:arr];
        
        
        
    }
    return 0;
}
