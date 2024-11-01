from launch import LaunchDescription
from launch_ros.actions import Node
import os

def generate_launch_description():
    # Set the path to your URDF file
    urdf_file_path = os.path.join(
        '/home/shri/ros2_ws/src/trial_links/urdf',
        'Untitled_v2.urdf'
    )

    # Check if the URDF file exists
    if not os.path.isfile(urdf_file_path):
        raise FileNotFoundError(f"URDF file not found: {urdf_file_path}")

    # RViz configuration file (update path if you have a custom RViz config)
    rviz_config_file = os.path.join(
        '/home/shri/ros2_ws/src/trial_links/rviz',
        'display_config.rviz'
    )

    # Check if the RViz config file exists
    if not os.path.isfile(rviz_config_file):
        raise FileNotFoundError(f"RViz configuration file not found: {rviz_config_file}")

    return LaunchDescription([
        # Node to publish the robot description
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[{'robot_description': open(urdf_file_path).read()}]
        ),
        
        # Node to launch RViz with the configuration file
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            output='screen',
            arguments=['-d', rviz_config_file]
        ),
    ])