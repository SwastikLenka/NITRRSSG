#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <cv_bridge/cv_bridge.h>
   
   int main(int argc, char** argv)
   {
     ros::init(argc, argv, "i1");
     ros::NodeHandle nh;
     image_transport::ImageTransport it(nh);
     image_transport::Publisher pub = it.advertise("camera/image", 1);
     cv::Mat image = cv::imread("/home/swastik/Desktop/a.jpeg");
     cv::waitKey(30);
     sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
   
     ros::Rate loop_rate(5);
     while (nh.ok()) {
       pub.publish(msg);
       ros::spinOnce();
       loop_rate.sleep();
     }
   }
