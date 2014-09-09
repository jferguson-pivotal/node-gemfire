#ifndef __REGION_HPP__

#include <v8.h>
#include <nan.h>
#include <gfcpp/Region.hpp>
#include <node.h>
#include <string>
#include "cache.hpp"

using namespace v8;

namespace node_gemfire {

class Region : node::ObjectWrap {
 public:
    explicit Region(Handle<Object> cacheHandle,
                    gemfire::RegionPtr regionPtr) :
        regionPtr(regionPtr) {
      NanAssignPersistent(this->cacheHandle, cacheHandle);
    }

    ~Region() {
      NanDisposePersistent(cacheHandle);
    }

    static void Init(Handle<Object> exports);
    static NAN_METHOD(GetRegion);
    static NAN_METHOD(Clear);
    static NAN_METHOD(Put);
    static NAN_METHOD(Get);
    static NAN_METHOD(Remove);
    static NAN_METHOD(ExecuteFunction);
    static NAN_METHOD(Inspect);
    static NAN_GETTER(Name);
    static void AsyncGet(uv_work_t * request);
    static void AfterAsyncGet(uv_work_t * request, int status);
    static void AsyncPut(uv_work_t * request);
    static void AfterAsyncPut(uv_work_t * request, int status);
    static void AsyncExecuteFunction(uv_work_t * request);
    static void AfterAsyncExecuteFunction(uv_work_t * request, int status);
    static void AsyncRemove(uv_work_t * request);
    static void AfterAsyncRemove(uv_work_t * request, int status);

 private:
    gemfire::RegionPtr regionPtr;
    Persistent<Object> cacheHandle;
};

}  // namespace node_gemfire

#define __REGION_HPP__
#endif
