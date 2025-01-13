#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>


int main(int argc, char **argv)
{
	rclcpp::init(argc,argv); // ノードを初期化
	auto node = rclcpp::Node::make_shared("my_publisher"); // ノードの 生成
	// String 型のメッセージを扱う greeting トピックを生成
	auto pub_greeting = node->create_publisher<std_msgs::msg::String>("greeting",1);

	rclcpp::WallRate loop(1); // ループ周期を 1Hz に設定
	int count = 0;

	while (rclcpp::ok()){
		auto msg = std_msgs::msg::String(); // String 型のメッセージを生成
		msg.data = "Hello world " + std::to_string(count++);
		pub_greeting->publish(msg); // メッセージを配信
		RCLCPP_INFO(node->get_logger(),"%s", msg.data.c_str());
		loop.sleep(); // 周期が 1Hz になるように時間調整
	}
	rclcpp::shutdown(); // 通信を切断
	return 0;
}
