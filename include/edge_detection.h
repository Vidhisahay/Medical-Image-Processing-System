#ifndef EDGE_DETECTION_H
#define EDGE_DETECTION_H

#include <opencv2/opencv.hpp>

// Perform Canny edge detection
cv::Mat detectEdges(const cv::Mat& image);

#endif