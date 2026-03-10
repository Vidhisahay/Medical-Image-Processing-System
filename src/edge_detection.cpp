#include "edge_detection.h"

cv::Mat detectEdges(const cv::Mat& image) {

    cv::Mat edges;

    cv::Canny(image, edges, 50, 150);

    return edges;
}