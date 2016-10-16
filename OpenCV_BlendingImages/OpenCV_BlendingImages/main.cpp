//
//  main.cpp
//  OpenCV_BlendingImages
//
//  Created by Jeremy Hartmann on 9/22/16.
//  Copyright © 2016 Jeremy Hartmann. All rights reserved.
//

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, const char * argv[]) {
    
    
    double alpha = 0.5;
    double input = 0.5;
    Mat src1, src2, dst;
    
    cout << "Select alpha: ";
    cin >> input;
    
    if (input >= 0.0 && input <= 1.0) {
        alpha = input;
    }
    
    
    src1 = imread("/Users/j3hartma/Documents/ImageNet/ILSVRC_2015/val_256/Places365_val_00000004.jpg");
    src2 = imread("/Users/j3hartma/Documents/ImageNet/ILSVRC_2015/val_256/Places365_val_00000005.jpg");
    
    // Error check
    if (!src1.data) {
        cout << "Error: No image for src1" << endl;
        return -1;
    }
    if (!src2.data) {
        cout << "Error: No image for src2" << endl;
        return -1;
    }
    
    // Blend Image
    namedWindow("win1");
    addWeighted(src1, alpha, src2, 1.0 - alpha, 0.0, dst);
    
    
    imshow("win1", src1);
    waitKey();
    
    imshow("win1", src2);
    waitKey();
    
    imshow("win1", dst);
    waitKey();
    
    
    
    
    
    
}
