#pragma once

#include "opencv2/core.hpp"

/// \brief Blends two images linearly
/// \param img_1 A three channel image with data type CV_32F.
/// \param img_2 A three channel image with data type CV_32F.
/// \param weights A three channel image with data type CV_32F, containing the weights in the range [0,1].
/// \return An image result = weights*img_1 + (1-weights)*img_2.
cv::Mat linearBlending(const cv::Mat& img_1, const cv::Mat& img_2, const cv::Mat& weights);
