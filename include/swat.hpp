#ifndef SWAT_HPP_
#define SWAT_HPP_

#include <ros/package.h>
#include <string>
#include <actionlib/client/simple_action_client.h>
#include <move_base_msgs/MoveBaseAction.h>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;



class Swat{
    public:
        explicit Swat(ros::NodeHandle nh,std::string name);
        ~Swat();
        bool moving;

        move_base_msgs::MoveBaseGoal get_goal(std::pair<float,float>&);
        std::unique_ptr<MoveBaseClient> get_client();
        void move_to_goal(std::pair<float,float>goal);
        // std::pair<float,float> make_pair(float a, float b);

    
    private:
        std::string robot_name;
        ros::NodeHandle nh_;

};

std::pair<float,float>make_pair(float a, float b);

#endif