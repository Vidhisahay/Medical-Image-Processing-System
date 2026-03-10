#ifndef REGION_DETECTION_H
#define REGION_DETECTION_H

#include <opencv2/opencv.hpp>

// Detect significant regions using contours
cv::Mat detectRegions(const cv::Mat& image, const cv::Mat& edges);

#endif