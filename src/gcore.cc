// Copyright 2013 Timothy J Fontaine <tjfontaine@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to permit
// persons to whom the Software is furnished to do so, subject to the
// following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN
// NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
// USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "unistd.h"

#include "v8.h"

#include "node.h"

#include "node_version.h"


using v8::Value;
using v8::String;
#if NODE_VERSION_AT_LEAST(0, 11, 3)
using v8::FunctionCallbackInfo;
#else
using v8::Arguments;
#endif
using v8::Local;
using v8::Handle;
using v8::Object;
using v8::Undefined;

using namespace node;

extern int do_core(const char* fname);

#if NODE_VERSION_AT_LEAST(0, 11, 3)
void
GCore(const v8::FunctionCallbackInfo<Value>& args)
#else
Handle<Value>
GCore(const Arguments& args)
#endif
{
	String::Utf8Value fname(args[0].As<String>());

	int ret = do_core(*fname);

#if NODE_VERSION_AT_LEAST(0, 11, 3)
	args.GetReturnValue().Set(ret);
#else
	return v8::Integer::New(ret);
#endif
}


void
init(Local<Object> module)
{
  NODE_SET_METHOD(module, "gcore", GCore);
}

NODE_MODULE(gcore, init)
