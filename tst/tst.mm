
#include "header.h"
#import <XCTest/XCTest.h>

@interface test : XCTestCase

@end

@implementation test

- (void)test_lab {
    srand((unsigned)time(NULL));
    int rowCount = 3;
    int colCount = 3;
    int **arr = new int*[rowCount];
    for (int i=0; i<rowCount; i++)
    {
        arr[i] = new int[colCount];
    }
    printArray(arr, rowCount, colCount,0,0);
    XCTAssertNotEqual(rowCount, 1);
    
    for(int i = 0; i < rowCount; i++)
        delete [] arr[i];
        delete [] arr;
}



@end

