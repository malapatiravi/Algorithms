# Copyright 2016 Open Source Robotics Foundation, Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import rclpy
from rclpy.node import Node
import threading
from std_msgs.msg import String
from sensor_msgs.msg import Image
from collections import deque
from rclpy.node import Node
import time

rclpy.init()
g_node = rclpy.create_node('node_name') 
rgb_image_queue = deque()
depth_image_deque = deque()

g_queue_size = 1
topic_name = "/test_topic"
topic_name2 = "/test_topic"

def rgb_img_publisher_thread() -> None:
    publisher_ = g_node.create_publisher(String, topic_name, g_queue_size)
    i = 0
    while True:
        # rclpy.spin_once(g_node) 
        # image_raw_ = depth_image_deque.pop()
        print("Inside first thread")
        msg = String()
        msg.data = 'Test Img Publisher: %d' % i
        i += 1                                                       
        publisher_.publish(msg)
        time.sleep(0.0030)  

def depth_img_publisher_thread() -> None:                                                         
    publisher_ = g_node.create_publisher(String, topic_name2, g_queue_size)
    i = 0
    while True:
        # rclpy.spin_once(g_node)                                                                                    
        # image_raw_ = rgb_image_queue.pop()
        print("Inside second thread")
        msg = String()
        msg.data = 'Test Img Publisher: %d' % i
        i += 1                                                       
        publisher_.publish(msg)                                                            
        time.sleep(0.0030)  

def main(args=None):
    thread2 = threading.Thread(target=rgb_img_publisher_thread())
    thread1 = threading.Thread(target=depth_img_publisher_thread())
    thread2.start()
    thread1.start()
    rclpy.spin(g_node)
    # while rclpy.ok(): 
    #     print("here ")
    #     rclpy.spin_once(g_node) 
    

    thread2.join()
    thread1.join()
    rclpy.shutdown()

def main1(args=None):
    i = 0
    while rclpy.ok():
        publisher1 = g_node.create_publisher(String, '/topic1', g_queue_size)
        publisher2 = g_node.create_publisher(String, '/topic2', g_queue_size)
        msg = String()
        i += 1
        msg.data = 'Test Img Publisher: %d' % i
        thread2 = threading.Thread(publisher2.publish(msg))
        thread1 = threading.Thread(publisher1.publish(msg))
        thread2.start()
        thread1.start()
        thread2.join()
        thread1.join()

if __name__ == '__main__':
    main()