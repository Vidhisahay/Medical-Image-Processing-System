#ifndef PREPROCESSING_H
#define PREPROCESSING_H

#include <opencv2/opencv.hpp>

// Convert image to grayscale
cv::Mat convertToGray(const cv::Mat& image);

// Apply Gaussian blur to reduce noise
cv::Mat applyGaussianBlur(const cv::Mat& image);

#endif