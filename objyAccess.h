#ifndef _OBJYACCESS_H_
#define _OBJYACCESS_H_

#include <string>
#include <nan.h>

using namespace std;

class ObjyAccess : public Nan::ObjectWrap {
 public:
  static void Init(v8::Local<v8::Object> exports);

 private:
  explicit ObjyAccess(string connectionString);
  ~ObjyAccess();

  static void New(const Nan::FunctionCallbackInfo<v8::Value>& info);
  static void GetConnection(const Nan::FunctionCallbackInfo<v8::Value>& info);
  static void Query(const Nan::FunctionCallbackInfo<v8::Value>& info);
  static void Query2(const Nan::FunctionCallbackInfo<v8::Value>& info);
  static Nan::Persistent<v8::Function> constructor;
  string _connectionString;
};

#endif
