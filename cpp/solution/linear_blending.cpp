#include "linear_blending.h"

cv::Mat linearBlending(const cv::Mat& img_1, const cv::Mat& img_2, const cv::Mat& weights)
{
  // result = img_1 * weights + img_2 * (1-weights)
  // No need to loop through all pixels!
  // Hint: https://docs.opencv.org/4.0.1/d1/d10/classcv_1_1MatExpr.html
  return img_1.mul(weights) + img_2.mul(cv::Scalar::all(1.0) - weights);
}
