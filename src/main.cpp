#include <opencv2/opencv.hpp>
#include <iostream>
#include <filesystem>
#include <chrono>

#include "preprocessing.h"
#include "edge_detection.h"
#include "region_detection.h"

namespace fs = std::filesystem;
using namespace std::chrono;

int main() {

    std::string inputFolder = "images";

    for (const auto& entry : fs::directory_iterator(inputFolder)) {

        std::string imagePath = entry.path().string();

        std::cout << "\nProcessing: " << imagePath << std::endl;

        cv::Mat image = cv::imread(imagePath);

        if (image.empty()) {
            std::cout << "Skipping invalid image\n";
            continue;
        }

        // ---- Preprocessing ----
        auto start_pre = high_resolution_clock::now();

        cv::Mat gray = convertToGray(image);
        cv::Mat blurred = applyGaussianBlur(gray);

        auto end_pre = high_resolution_clock::now();
        std::cout << "Preprocessing time: "
                  << duration_cast<milliseconds>(end_pre - start_pre).count()
                  << " ms\n";

        // ---- Edge detection ----
        auto start_edge = high_resolution_clock::now();

        cv::Mat edges = detectEdges(blurred);

        auto end_edge = high_resolution_clock::now();
        std::cout << "Edge detection time: "
                  << duration_cast<milliseconds>(end_edge - start_edge).count()
                  << " ms\n";

        // ---- Region detection ----
        auto start_region = high_resolution_clock::now();

        cv::Mat result = detectRegions(image, edges);

        auto end_region = high_resolution_clock::now();
        std::cout << "Region detection time: "
                  << duration_cast<milliseconds>(end_region - start_region).count()
                  << " ms\n";

        std::string outputPath =
            "results/processed_" + entry.path().filename().string();

        cv::imwrite(outputPath, result);

        std::cout << "Saved: " << outputPath << std::endl;
    }

    std::cout << "\nBatch processing complete\n";

    return 0;
}