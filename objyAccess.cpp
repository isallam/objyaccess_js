#include "objyAccess.h"


Nan::Persistent<v8::Function> ObjyAccess::constructor;

ObjyAccess::ObjyAccess(string connectionString) : 
    _connectionString(connectionString) {
}

ObjyAccess::~ObjyAccess() {
}

void ObjyAccess::Init(v8::Local<v8::Object> exports) {
  Nan::HandleScope scope;

  // Prepare constructor template
  v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
  tpl->SetClassName(Nan::New("ObjyAccess").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  // Prototype
  Nan::SetPrototypeMethod(tpl, "connection", GetConnection);
  Nan::SetPrototypeMethod(tpl, "query", Query);
  Nan::SetPrototypeMethod(tpl, "query2", Query2);

  constructor.Reset(tpl->GetFunction());
  exports->Set(Nan::New("ObjyAccess").ToLocalChecked(), tpl->GetFunction());
}

void ObjyAccess::New(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  if (info.IsConstructCall()) {
    // Invoked as constructor: `new ObjyAccess(...)`
    //double value = info[0]->IsUndefined() ? 0 : info[0]->NumberValue();
    if (info[0]->IsString()) {
      v8::String::Utf8Value str(info[0]->ToString());
      string connection_str = (const char*)(*str);
      printf("Connection to: [%s]\n", connection_str.c_str());
      ObjyAccess* obj = new ObjyAccess(connection_str);
      obj->Wrap(info.This());
      info.GetReturnValue().Set(info.This());
    }
  } else {
    // Invoked as plain function `ObjyAccess(...)`, turn into construct call.
    const int argc = 1;
    v8::Local<v8::Value> argv[argc] = { info[0] };
    v8::Local<v8::Function> cons = Nan::New<v8::Function>(constructor);
    info.GetReturnValue().Set(cons->NewInstance(argc, argv));
  }
}

void ObjyAccess::GetConnection(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  ObjyAccess* obj = ObjectWrap::Unwrap<ObjyAccess>(info.Holder());
  info.GetReturnValue().Set(Nan::New(obj->_connectionString.c_str()).ToLocalChecked());
  //info.GetReturnValue().Set(Nan::New("Blah Blah").ToLocalChecked());
}

void ObjyAccess::Query(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  ObjyAccess* obj = ObjectWrap::Unwrap<ObjyAccess>(info.Holder());
  
  if (info[0]->IsString())
  {
    v8::String::Utf8Value queryString(info[0]->ToString());
    printf("Got query string: %s\n", (const char*)(*queryString));
  }
  v8::Local<v8::Function> cb = info[1].As<v8::Function>();
  
  //v8::Local<v8::Function> cons = Nan::New<v8::Function>(constructor);

  const int argc = 1;
  for (int i = 0; i < 3; i++)
  {
    string results = "Query results " + std::to_string(i);
    v8::Local<v8::Value> argv[argc] = { Nan::New(results.c_str()).ToLocalChecked() };
    Nan::MakeCallback(Nan::GetCurrentContext()->Global(), cb, argc, argv);
  }
}

void ObjyAccess::Query2(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Function> cb = info[0].As<v8::Function>();
  const unsigned argc = 1;
  v8::Local<v8::Value> argv[argc] = { Nan::New("Query world (CB)").ToLocalChecked() };
  Nan::MakeCallback(Nan::GetCurrentContext()->Global(), cb, argc, argv);
}
