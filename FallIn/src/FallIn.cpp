#include <ugdk/system/engine.h>

int main() {
	namespace system = ugdk::system;
	system::Initialize();
	system::Run();
	system::Release();
	return 0;
}