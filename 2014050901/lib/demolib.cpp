#include <node.h>
#include <node_buffer.h>
#include <v8.h>

using namespace node;
using namespace v8;

Handle<Value> newtonSqrt(Arguments const& args) {
    HandleScope scope;
    if ( args.Length() != 1 ) {
        return ThrowException(Exception::TypeError(String::New("Number of arguments must be 1!")));
    }
    float a, x;
    a = x = args[0]->NumberValue();
    for ( int i=1; i<=10; ++i ) {
        x = (x+a/x)/2;
    }
    return scope.Close(Number::New(x));
}

Handle<Value> drawSomething(Arguments const& args) {
    HandleScope scope;
    if ( args.Length()!=1 && !Buffer::HasInstance(args[0]) ) {
        return ThrowException(Exception::TypeError(String::New("Number of arguments must be 1!")));
    }
    unsigned char* buf = (unsigned char*)Buffer::Data(args[0]->ToObject());
    for ( int i=0; i<4; ++i) {
        ++buf[i*4];
    }
    return scope.Close(Undefined());
}

void init(Handle<Object> target) {
    NODE_SET_METHOD(target, "newtonSqrt",     newtonSqrt);
    NODE_SET_METHOD(target, "drawSomething",  drawSomething);
}

NODE_MODULE(demolib, init);
