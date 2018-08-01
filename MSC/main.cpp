//
//  main.cpp
//  MSC
//
//  Created by mac on 20/7/2018.
//  Copyright © 2018 DvixExtract. All rights reserved.
//

#include "opencv2/highgui.hpp"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;

//int main(int argc, char* argv[])
//{
//    VideoCapture cap("/Users/mac/Desktop/mscvideos/gait.mp4");
//
//    if (cap.isOpened() == false)
//    {
//        cout << "Cannot open the video file" << endl;
//        cin.get();
//        return -1;
//    }
//
//    double fps = cap.get(CAP_PROP_FPS);
//    cout << "Frames per seconds : " << fps << endl;
//
//    String window_name = "My First Video";
//
//    namedWindow(window_name, WINDOW_NORMAL);
//    while (true)
//    {
//        Mat frame;
//        bool bSuccess = cap.read(frame);
//        if (bSuccess == false)
//        {
//            cout << "Found the end of the video" << endl;
//            break;
//        }
//
//        imshow(window_name, frame);
//
//        if (waitKey(10) == 27)
//        {
//            cout << "Esc key is pressed by user. Stoppig the video" << endl;
//            break;
//        }
//    }
//
//    return 0;
int main()
{
    cv::VideoCapture capture;
    cv::Mat RGB, HSV;
    
    string videoPath = "/Users/mac/Desktop/mscvideos/gait.mp4";
    
    if(!capture.open(videoPath))
    {
        cout<<"Video Not Found"<<endl;
        return -1;
    }
    
    while(true)
    {
        capture>>RGB;  //Read a frame from the video
        
        if(RGB.empty()) //Check if the frame has been read correctly or not
        {
            cout<<"Capture Finished"<<endl;
            break;
        }
        
        cv::cvtColor(RGB,HSV,CV_BGR2HSV);
        
        cv::imshow("HSV Image",HSV);
//        cv::resizeWindow('mxm', 600, 600)
        cv::waitKey(10);
    }
    
    capture.release();
    return 0;
}
