#include <nan.h>
#include "objyAccess.h"

void InitAll(v8::Local<v8::Object> exports) {
	ObjyAccess::Init(exports);
}

NODE_MODULE(addon, InitAll)
