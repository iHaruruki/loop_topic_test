#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>


// String 型のメッセージを受け取るコールバック関数を定義
void callback( const std_msgs::msg::String::SharedPtr msg )
{
	RCLCPP_INFO( rclcpp::get_logger( ), "%s", msg->data.c_str( ) );
}

int main( int argc, char **argv )
{
	rclcpp::init( argc, argv );
	auto node = rclcpp::Node::make_shared( "my_subscriber" );
	// String 型のメッセージを greeting トピック経由で受け取ったら callback 関数を実行する
	auto sub_greeting = node->create_subscription<std_msgs::msg::String>( "greeting", 1, callback );
	// callback の永続待ち． main 関数はブロックされる． Ctrl+C などで終了させると先に進む．
	while ( rclcpp::ok( ) )
	{
		rclcpp::spin_some( node );
	}
	g_node = nullptr;
	rclcpp::shutdown( );
	return 0;
}
