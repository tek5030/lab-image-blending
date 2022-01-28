def lab02():
    def showResult(title, img):
        cv2.namedWindow(title, cv2.WINDOW_NORMAL | cv2.WINDOW_KEEPRATIO)
        cv2.imshow(title, img)
        cv2.waitKey(0)
    
    import cv2
    import numpy as np
    img_01 = cv2.imread("./tiger.png", cv2.IMREAD_UNCHANGED)
    img_01 = np.float32(img_01)*(1.0/255.0)

    img_02 = cv2.imread("./white_tiger.png", cv2.IMREAD_UNCHANGED)
    img_02 = np.float32(img_02)*(1.0/255.0)
    showResult('tiger', img_01)
    showResult('white_tiger', img_02)

    weights = np.zeros(img_01.shape, dtype=np.float32)
    weights[:, :int(weights.shape[1]/2)] = (1., 1., 1.)

    ramp_width = 5
    weights = cv2.blur(weights, (ramp_width+1, ramp_width+1))

    showResult('weights', weights)

    def linearBlend(img1, img2, weights):
        return np.multiply(img1, weights) + np.multiply(img2, 1.-weights)
    
    linear = linearBlend(img_01, img_02, weights)
    showResult('linear', linear)

    def gaussPyr(img):
        pyr = [img]
        while pyr[-1].shape[1] > 16:
            pyr.append(cv2.pyrDown(pyr[-1]))
        return pyr
    
    def laplacePyr(img):
        pyr = gaussPyr(img)
        for i in range(len(pyr)-1):
            pyr[i] = pyr[i] - cv2.pyrUp(pyr[i+1],dstsize=pyr[i].shape[0:2])
        return pyr
    
    
    weights_pyr = gaussPyr(weights)
    img1_pyr = laplacePyr(img_01)
    img2_pyr = laplacePyr(img_02)

    blend_pyr = []
    for im1, im2, w in zip(img1_pyr, img2_pyr, weights_pyr):
        blend_pyr.append(
            linearBlend(im1, im2, w)
        )
    
    def collapsePyr(pyr):
        for i, img in reversed(list(enumerate(pyr[:-1]))):
            pyr[i] = pyr[i] + cv2.pyrUp(pyr[i+1], dstsize=pyr[i].shape[0:2])
        
        return pyr[0]

    blend = collapsePyr(blend_pyr)
    showResult('blend', blend)
    
    
def hello(who="world"):
    print(f"Hello, {who}!")
    

if __name__ == "__main__":
    """Hei"""
    hello(who="lab 02")
    lab02()