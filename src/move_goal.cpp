
#include <actionlib/client/simple_action_client.h>
#include <move_base_msgs/MoveBaseAction.h>


typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
int main(int argc, char** argv){

    ros::init(argc, argv, "simple_navigation_goals");
    MoveBaseClient ac("robot1/move_base", true);
    MoveBaseClient ac1("robot2/move_base", true);


    while(!ac.waitForServer(ros::Duration(5.0))){
        
       ROS_INFO("Waiting for the move_base action server to come up");
    }
    
    move_base_msgs::MoveBaseGoal goal;
    goal.target_pose.header.frame_id = "map";
    goal.target_pose.header.stamp = ros::Time::now();
    goal.target_pose.pose.position.x = -3.0;
    goal.target_pose.pose.position.y = -9.5;


    goal.target_pose.pose.orientation.w = 1.0;

    ac.sendGoal(goal);


    ac1.sendGoal(goal);
    ac.waitForResult();

    ac1.waitForResult();
    
    return 0;
}