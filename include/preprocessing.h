#ifndef PREPROCESSING_H
#define PREPROCESSING_H

#include <opencv2/opencv.hpp>

cv::Mat convertToGray(const cv::Mat& image);

cv::Mat applyGaussianBlur(const cv::Mat& image);

// NEW
cv::Mat enhanceContrast(const cv::Mat& image);

#endif