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
- (void)heapSort:(NSMutableArray *) inArr;


@end

// Private Methods
@interface HEAPSORT (Helpers)
- (void)buildMaxHeap:(NSMutableArray *)inArr;
- (void)heapify:(NSMutableArray *)inArr;
@end

@implementation HEAPSORT

- (void)heapSort:(NSMutableArray *)inArr
{
    
    
}

// Private Methods
- (void)buildMaxHeap:(NSMutableArray *)inArr
{
    
}

- (void)heapify:(NSMutableArray *)inArr
{
    
}

@end



int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
    }
    return 0;
}
