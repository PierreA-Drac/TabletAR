#!/usr/bin/python3

# Python 2/3 compatibility
from __future__ import print_function

import cv2 as cv

def callback_trackbar(val):
    pass

def callback_button(state, params):
    pass

if __name__ == '__main__':
    import sys

    wname = 'TAR Project'
    
    fname = 'opencv.png'
    im = cv.imread(cv.samples.findFile(fname))
    if im is None:
        print('Failed to load image file:', fname)
        sys.exit(1)

    cv.imshow(wname, im)
    cv.displayOverlay(wname, 'Cliquez sur un bouton pour interagir avec l\'application.', 0);
    cv.displayStatusBar(wname, 'On peut placer des informations et trackbars ici.', 0);
    cv.createTrackbar("Trackbar exemple", wname, 128, 255, callback_trackbar);
    cv.createTrackbar("Trackbar exemple", "", 128, 255, callback_trackbar);
    cv.createButton("Bouton", callback_button, wname, 0);
    
    while True:
        k = cv.waitKey(0)
        if k == 27:
            print('ESC')
            cv.destroyAllWindows()
            break
    cv.destroyAllWindows()
