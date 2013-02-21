#include <node.h>
#include <v8.h>

using namespace v8;

Handle<Value> Hello(const Arguments& args) {
    HandleScope scope;
    return scope.Close(String::New("world"));
}

Handle<Value> Add(const Arguments& args) {
    HandleScope scope;
    if( args.Length() != 2 ) {
        return ThrowException(Exception::TypeError(String::New("Number of arguments must be 2!")));
    }
    return scope.Close(Integer::New(args[0]->Int32Value()+args[1]->Int32Value()));
}

void init(Handle<Object> target) {
    NODE_SET_METHOD(target, "hello", Hello);
    NODE_SET_METHOD(target, "add", Add);
}

NODE_MODULE(binding, init);

