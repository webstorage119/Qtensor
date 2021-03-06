#ifndef CAMERARUNNABLE_H
#define CAMERARUNNABLE_H

#include <QAbstractVideoFilter>
#include <QOpenGLTexture>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/videoio.hpp"

#include <opencv/highgui.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <aruco/aruco.h>
#include "backend.h"

#include <QDebug>

class CameraFilter;

class CameraRunnable : public QVideoFilterRunnable
{
public:
    CameraRunnable( CameraFilter *filter );
    ~CameraRunnable();

    QVideoFrame run( QVideoFrame *input, const QVideoSurfaceFormat &surfaceFormat, RunFlags flags ) Q_DECL_OVERRIDE;

private:
    CameraFilter * m_filter;
    QOpenGLTexture *texture;
    aruco::MarkerDetector * markerDetector;
    std::vector< aruco::Marker > detectedMarkers;
    aruco::CameraParameters *cameraParameters;
    cv::CascadeClassifier *frontalFaceClassifier;
    cv::CascadeClassifier *smileClassifier;

    QImage wrapper(const QVideoFrame &input);

};
#endif // CAMERARUNNABLE_H
