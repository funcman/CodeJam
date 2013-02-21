Code Jam
===

funcman的代码涂鸦
***

+	2013020801

	使用C++为node.js编写addon。

		# 构建
		node-gyp configure
		node-gyp build
		# 测试
		node test.js

	官方推荐的构建器为[node-gyp](https://github.com/TooTallNate/node-gyp)，它使用了[gyp](http://code.google.com/p/gyp/)语法。
	
	一份值得阅读的教程：[node.js extensions
with C++ and V8](http://kkaefer.github.com/node-cpp-modules/)。