#include <iostream>
#include "Scope.h"


int main() {
	
	Scope global;
	global.defineSymbol("foo", new VariableNode);
	Scope function(global);

	global.getSymbol("foo")->value = "global";

	std::cout << global.getSymbol("foo")->value << '\n';

	function.defineSymbol("foo", new VariableNode);
	function.getSymbol("foo")->value = "function";

	std::cout << global.getSymbol("foo")->value << " " << function.getSymbol("foo")->value << '\n';

	return 0;

}
	
