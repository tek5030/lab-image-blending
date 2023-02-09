#include "linear_blending.h"

cv::Mat linearBlending(const cv::Mat& img_1, const cv::Mat& img_2, const cv::Mat& weights)
{
  // TODO 3.1: Blend the two images according to the weights:
  //   result = img_1 * weights + img_2 * (1-weights)
  // No need to loop through all pixels!
  // Hint: https://docs.opencv.org/4.5.5/d1/d10/classcv_1_1MatExpr.html
  return cv::Mat();
}
