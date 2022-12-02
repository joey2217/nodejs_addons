#include <nan.h>
#include <cube/cube_api.h>

void MyFunction(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
    int code = 0;
    if (Cube::IsCubeRunning())
    {
        code = 1;
    }

    info.GetReturnValue().Set(Nan::New(code));
}

void CreateFunction(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
    v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();
    v8::Local<v8::FunctionTemplate> tpl =
        Nan::New<v8::FunctionTemplate>(MyFunction);
    v8::Local<v8::Function> fn = tpl->GetFunction(context).ToLocalChecked();

    // omit this to make it anonymous
    fn->SetName(Nan::New("theFunction").ToLocalChecked());

    info.GetReturnValue().Set(fn);
}

void Init(v8::Local<v8::Object> exports, v8::Local<v8::Object> module)
{
    Nan::SetMethod(module, "exports", CreateFunction);
}

NODE_MODULE(addon, Init)
