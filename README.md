# ROS Publisher-Subscriber, Services, and Actions (C++)

This project demonstrates the **Publisher-Subscriber**, **Service**, and **Action** concepts in **ROS** using **C++**. It consists of four nodes:
1. **Publisher Node**: Publishes messages to a topic.
2. **Subscriber Node**: Subscribes to the topic and processes the messages.
3. **Service Server Node**: Provides a simple service.
4. **Service Client Node**: Requests a service from the service server.
5. **Action Server Node**: Performs long-running tasks with feedback.
6. **Action Client Node**: Sends goals to the action server and receives feedback.

## **Features**
- **Publisher-Subscriber**: Basic communication between nodes via topics.
- **Service**: Synchronous communication between nodes with request-response.
- **Action**: Asynchronous communication with feedback for long-running tasks.

## **Folder Structure**
```
ros_publisher_subscriber_action_service_cpp/
├── CMakeLists.txt               # Build configuration for C++ nodes
├── package.xml                  # ROS package configuration file
├── src/
│   ├── publisher.cpp            # Publisher node implementation
│   ├── subscriber.cpp           # Subscriber node implementation
│   ├── service_server.cpp       # Service server node implementation
│   ├── service_client.cpp       # Service client node implementation
│   ├── action_server.cpp        # Action server node implementation
│   └── action_client.cpp        # Action client node implementation
└── README.md                    # This documentation file
```

## **Setup Instructions**

### **1. Install ROS**
Ensure that ROS is installed. Follow the installation guide for your ROS version [here](http://wiki.ros.org/ROS/Installation).

### **2. Create a Catkin Workspace**
```bash
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/src
catkin_create_pkg ros_publisher_subscriber_action_service_cpp std_msgs roscpp actionlib
cd ~/catkin_ws
catkin_make
```

### **3. Compile the Project**
```bash
cd ~/catkin_ws
catkin_make
```

### **4. Run the Nodes**
Open multiple terminals to run the nodes:

- **Terminal 1 (Publisher)**:
```bash
source devel/setup.bash
rosrun ros_publisher_subscriber_action_service_cpp publisher
```

- **Terminal 2 (Subscriber)**:
```bash
source devel/setup.bash
rosrun ros_publisher_subscriber_action_service_cpp subscriber
```

- **Terminal 3 (Service Server)**:
```bash
source devel/setup.bash
rosrun ros_publisher_subscriber_action_service_cpp service_server
```

- **Terminal 4 (Service Client)**:
```bash
source devel/setup.bash
rosrun ros_publisher_subscriber_action_service_cpp service_client
```

- **Terminal 5 (Action Server)**:
```bash
source devel/setup.bash
rosrun ros_publisher_subscriber_action_service_cpp action_server
```

- **Terminal 6 (Action Client)**:
```bash
source devel/setup.bash
rosrun ros_publisher_subscriber_action_service_cpp action_client
```

## **Dependencies**
- ROS Noetic or Melodic
- C++ (C++11 or later)
- **actionlib** (for Actions)
- **roscpp** (C++ client library for ROS)
- **std_msgs** (for messages)

