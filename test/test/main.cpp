//
//  main.cpp
//  test
//
//  Created by 徐亦燊 on 2020/2/28.
//  Copyright © 2020 徐亦燊. All rights reserved.
//

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int main()
{
    Mat srcMat = imread("/Users/xuyishen/Desktop/sa jiganyouhaximeiyouga/2020.4.10/1/lena.jpg");
    Mat dstMat;
    int width, height;
    width = srcMat.cols;
    height = srcMat.rows;

    float angle = -10.0, scale = 1;
    Point2f center(srcMat.cols*0.5, srcMat.rows*0.5);
    Mat rot = getRotationMatrix2D(center, angle, scale);

    Rect bbox = RotatedRect(center,srcMat.size(),angle).boundingRect();
    rot.at<double>(0,2) += bbox.width*0.5-center.x;
    rot.at<double>(1,2) += bbox.width*0.5-center.y;
    warpAffine(srcMat, dstMat, rot,bbox.size());
    imshow("src", srcMat);
    imshow("dst", dstMat);
    waitKey(0);
    return 0;
}
